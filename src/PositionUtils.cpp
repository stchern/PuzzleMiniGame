#include "PositionUtils.h"
#include "MatrixUtils.h"

bool InternalUtils::UPosition::isFoundNextPositionsInColsAndRowsByPosition(
        const Matrix& matrix,
        const std::pair<Position, Path>& startPositionAndPath,
        const Position& positionToFound,
        std::queue<std::pair<Position, Path>>& stack,
        bool isStartFromCol)
{

    size_t currRow = startPositionAndPath.first.row();
    size_t currCol = startPositionAndPath.first.column();

    if (isStartFromCol) {
        if (currCol == positionToFound.column()) {
            Path newPath = startPositionAndPath.second;
            newPath.push_back(positionToFound);
            stack.push(std::make_pair(positionToFound, newPath));
        }
        else  {
            for (size_t row = 0; row < matrix.rowCount(); ++row)
                if (row != currRow) {
                    Path newPath = startPositionAndPath.second;
                    newPath.push_back(Position(row, currCol));
                    stack.push(std::make_pair(Position(row, currCol), newPath));
                }
        }

    }
    else {
        if (currRow == positionToFound.row()) {
            Path newPath = startPositionAndPath.second;
            newPath.push_back(positionToFound);
            stack.push(std::make_pair(positionToFound, newPath));
        }
        else {
            for (size_t col = 0; col < matrix.columnCount(); ++col)
                if (col != currCol) {
                    Path newPath = startPositionAndPath.second;
                    newPath.push_back(Position(currRow, col));
                    stack.push(std::make_pair(Position(currRow, col), newPath));
                }
        }

    }
}

bool InternalUtils::UPosition::isFoundNextPositionsInColsAndRowsByValue(
        const Matrix& matrix,
        const std::pair<Position, Path>& startPositionAndPath,
        unsigned char value,
        std::stack<std::pair<Position, Path>>& stack,
        bool isStartFromCol)
{
    Position startPosition(startPositionAndPath.first);
    std::vector<Position> resultVector;
    bool isFound = false;

    if (!isStartFromCol)
        isFound = InternalUtils::UMatrix::isFoundInRow(matrix, startPosition, value, resultVector);
    else
        isFound = InternalUtils::UMatrix::isFoundInCol(matrix, startPosition, value, resultVector);

    if (isFound)
        for (const Position& position: resultVector) {
            Path currPath = startPositionAndPath.second;
            currPath.push_back(position);
            stack.push(std::pair(position, currPath));
        }
    return isFound;

}


//bool InternalUtils::UPosition::isFoundNotVisitedPositionInRow(const std::vector<Position>& row, const Position& currPosition, const std::vector<bool>& isVisitedCol, int maxColumnCount, int& notVisitedCol)
//{
//    size_t currentRow = currPosition.row();
//    size_t currentCol = currPosition.column();
//    for (size_t col = 0; col < maxColumnCount; ++col)
//        if (col != currentCol && !isVisitedCol[col]) {
//            auto it = std::find(std::begin(row), std::end(row), Position(currentRow, col));
//            if (it != std::end(row)) {
//                notVisitedCol = col;
//                return true;
//            }
//        }
//    return false;
//}

bool InternalUtils::UPosition::isPositionInPath(const std::vector<Position>& pathPositions, const Position& position)
{
    auto it = std::find(std::begin(pathPositions), std::end(pathPositions), position);
    if (it != std::end(pathPositions))
        return true;

    return false;
}

bool InternalUtils::UPosition::isFoundTwoPositionsForWastedMoves(const std::vector<Position>& positions, const Position& currPosition, const int maxColumnCount, Path& outPathOfTwoPositions)
{
    size_t currCol = currPosition.column();
    size_t currRow = currPosition.row();
    for (size_t col = 0; col < maxColumnCount; ++col)
        if (col != currCol) {
            Position positionInSameRow(currRow, col);
            Position positionInFirstRow(0, col);
            if (!isPositionInPath(positions, positionInFirstRow) && !isPositionInPath(positions, positionInSameRow)) {
                outPathOfTwoPositions = Path({positionInFirstRow, positionInSameRow});
                return true;
            }
        }

    return false;
}
