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


bool InternalUtils::UPosition::isFoundNotVisitedPositionInRow(const std::vector<Position>& row, const Position& currPosition, const std::vector<bool>& isVisitedCol, int maxColumnCount, int& notVisitedCol)
{
    size_t currentRow = currPosition.row();
    size_t currentCol = currPosition.column();
    for (size_t col = 0; col < maxColumnCount; ++col)
        if (col != currentCol && !isVisitedCol[col]) {
            auto it = std::find(std::begin(row), std::end(row), Position(currentRow, col));
            if (it != std::end(row)) {
                notVisitedCol = col;
                return true;
            }
        }
    return false;
}

bool InternalUtils::UPosition::isPositionIsAnyPaths(const Path& rhsPath, const Path& lhsPath, const Position& position)
{
    auto it = std::find(std::begin(rhsPath.positions()), std::end(rhsPath.positions()), position);
    if (it != std::end(rhsPath.positions()))
        return true;

    it = std::find(std::begin(lhsPath.positions()), std::end(lhsPath.positions()), position);
    if (it != std::end(lhsPath.positions()))
        return true;
    return false;
}
