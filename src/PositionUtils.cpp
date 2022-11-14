#include "PositionUtils.h"
#include "MatrixUtils.h"

void InternalUtils::UPosition::nextPositionsInColOrRow(
        const std::pair<Position, Path>& startPositionAndPath,
        const Position& positionToFound,
        size_t rowCount, size_t columnCount,
        std::queue<std::pair<Position, Path>>& queue,
        bool isStartFromCol)
{
    if (isStartFromCol)
        nextPositionsInCol(startPositionAndPath, positionToFound, rowCount, queue);
    else
        nextPositionsInRow(startPositionAndPath, positionToFound, columnCount, queue);
}

void InternalUtils::UPosition::nextPositionsInCol(
        const std::pair<Position, Path>& startPositionAndPath,
        const Position& positionToFound,
        size_t rowCount,
        std::queue<std::pair<Position, Path>>& queue)
{
    size_t currRow = startPositionAndPath.first.row();
    size_t currCol = startPositionAndPath.first.column();

    if (currCol == positionToFound.column()) {
        Path newPath = startPositionAndPath.second;
        newPath.push_back(positionToFound);
        queue.push(std::make_pair(positionToFound, newPath));
        return;
    }

    for (size_t row = 0; row < rowCount; ++row)
        if (row != currRow) {
            Path newPath = startPositionAndPath.second;
            newPath.push_back(Position(row, currCol));
            queue.push(std::make_pair(Position(row, currCol), newPath));
        }
}

void InternalUtils::UPosition::nextPositionsInRow(
        const std::pair<Position, Path>& startPositionAndPath,
        const Position& positionToFound,
        size_t columnCount,
        std::queue<std::pair<Position, Path>>& queue)
{
    size_t currRow = startPositionAndPath.first.row();
    size_t currCol = startPositionAndPath.first.column();

    if (currRow == positionToFound.row()) {
        Path newPath = startPositionAndPath.second;
        newPath.push_back(positionToFound);
        queue.push(std::make_pair(positionToFound, newPath));
        return;
    }

    for (size_t col = 0; col < columnCount; ++col)
        if (col != currCol) {
            Path newPath = startPositionAndPath.second;
            newPath.push_back(Position(currRow, col));
            queue.push(std::make_pair(Position(currRow, col), newPath));
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

bool InternalUtils::UPosition::isPositionInPath(const std::vector<Position>& pathPositions, const Position& position)
{
    auto it = std::find(std::begin(pathPositions), std::end(pathPositions), position);
    return it != std::end(pathPositions);
}

bool InternalUtils::UPosition::isFoundTwoPositionsForWastedMoves(const std::vector<Position>& positions, const Position& currPosition, const int maxColumnCount, std::vector<Path>& outPathsOfTwoPositions)
{
    size_t currCol = currPosition.column();
    size_t currRow = currPosition.row();
    for (size_t col = 0; col < maxColumnCount; ++col)
        if (col != currCol) {
            Position positionInSameRow(currRow, col);
            Position positionInFirstRow(0, col);
            if (!isPositionInPath(positions, positionInFirstRow) && !isPositionInPath(positions, positionInSameRow))
                outPathsOfTwoPositions.push_back(Path({positionInFirstRow, positionInSameRow}));

        }
    return !outPathsOfTwoPositions.empty();
}
