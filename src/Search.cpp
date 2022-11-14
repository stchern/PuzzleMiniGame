#include "Search.h"
#include "PositionUtils.h"
#include "MatrixUtils.h"
#include <stack>
#include <queue>


std::vector<Path> Search::DFS(
        const Matrix& matrix,
        const Sequence& sequence,
        const Position& startPosition,
        std::size_t maxLengthPath)
{
    if (sequence.codes().size() == 1)
        return std::vector<Path>{Path(std::vector<Position>{startPosition})};

    std::vector<Path> possiblePaths;
    if (sequence.codes().size() > maxLengthPath)
        return possiblePaths;

    Matrix isVisitedMatrix = InternalUtils::UMatrix::createIsVisitedMatrix(matrix.rowCount(), matrix.columnCount(), startPosition);
    bool isStartFromCol = true;
    auto seqIt = std::next(sequence.codes().begin());
    std::vector<Position> foundPositions;
    foundPositions.reserve(matrix.columnCount());
    std::stack<std::pair<Position, Path>> stack;

    if (InternalUtils::UMatrix::isFoundInRow(matrix, startPosition, *seqIt, foundPositions) | InternalUtils::UMatrix::isFoundInCol(matrix, startPosition, *seqIt, foundPositions))
        for (const Position& position: foundPositions)
            stack.push(std::make_pair(position, Path(std::vector<Position>{startPosition, position})));

    while (!stack.empty()) {
        std::pair<Position, Path> positionAndPath = stack.top();
        stack.pop();
        Position currPosition = positionAndPath.first;
        Path possiblePath = positionAndPath.second;

        if (!InternalUtils::UMatrix::isValid(currPosition, isVisitedMatrix, matrix, *seqIt))
            continue;

        isVisitedMatrix.setValue(currPosition, 1);
        seqIt = sequence.codes().begin() + possiblePath.positions().size();

        if (seqIt == sequence.codes().end()) {
            possiblePaths.push_back(Path(possiblePath));
            isVisitedMatrix = InternalUtils::UMatrix::createIsVisitedMatrix(matrix.rowCount(), matrix.columnCount(), startPosition);
            if (!stack.empty())
                InternalUtils::UMatrix::setVisitedPositions(isVisitedMatrix, stack.top().second);
            continue;
        }

        isStartFromCol = !(currPosition.row() - possiblePath.positions()[possiblePath.positions().size() - 2].row());
        if (!InternalUtils::UPosition::isFoundNextPositionsInColsAndRowsByValue(matrix, positionAndPath, *seqIt, stack, isStartFromCol))
            isVisitedMatrix.setValue(currPosition, 0);
    }

    return possiblePaths;
}


std::vector<Path> Search::BFS(
        const Matrix& matrix,
        const Position& endPositionCurrSeq,
        const Position& startPositionNextSeq,
        bool isNextSeqStartByCol,
        bool isStartFromCol)
{
    std::vector<Path> possiblePaths;

    Matrix isVisitedMatrix = InternalUtils::UMatrix::createIsVisitedMatrix(matrix.rowCount(), matrix.columnCount(), endPositionCurrSeq);
    std::queue<std::pair<Position, Path>> queue;

    Path currPath({endPositionCurrSeq});
    queue.push(std::make_pair( endPositionCurrSeq, currPath));

    InternalUtils::UPosition::nextPositionsInColsOrRows(matrix, std::make_pair(endPositionCurrSeq, currPath), startPositionNextSeq, queue, isStartFromCol);
    queue.pop();

    while (!queue.empty()) {
        std::pair<Position, Path> positionAndPath = queue.front();
        queue.pop();

        Position currPosition = positionAndPath.first;
        Path possiblePath = positionAndPath.second;

        if (isVisitedMatrix.value(currPosition))
            continue;

        if (currPosition == startPositionNextSeq) {
            bool isCurrPathEndByCol = (currPosition.row() - possiblePath.positions()[possiblePath.positions().size() - 2].row());
            if (isCurrPathEndByCol != isNextSeqStartByCol) {
                std::vector<Position> intermediatePath;
                for (size_t idx = 1; idx < possiblePath.positions().size() - 1; ++idx)
                    intermediatePath.push_back(possiblePath.positions()[idx]);
                possiblePaths.push_back(Path(intermediatePath));
                isVisitedMatrix = InternalUtils::UMatrix::createIsVisitedMatrix(matrix.rowCount(), matrix.columnCount(), endPositionCurrSeq);
            }
            if (!queue.empty())
                    InternalUtils::UMatrix::setVisitedPositions(isVisitedMatrix, Path({startPositionNextSeq}));
            continue;
        }

        if (possiblePath.positions().size() > 3) {
            isVisitedMatrix.setValue(currPosition, 1);
            continue;
        }

        isStartFromCol = !(currPosition.row() - possiblePath.positions()[possiblePath.positions().size() - 2].row());
        InternalUtils::UPosition::nextPositionsInColsOrRows(matrix, positionAndPath, startPositionNextSeq, queue, isStartFromCol);
    }

    return possiblePaths;
}

