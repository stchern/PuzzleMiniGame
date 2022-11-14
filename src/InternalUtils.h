#ifndef INTERNALUTILS_H
#define INTERNALUTILS_H

#include <vector>
#include <stack>
#include <queue>
#include "Position.h"
#include "Sequence.h"
#include "Matrix.h"
#include "Path.h"


namespace InternalUtils
{

namespace UPath {

std::vector<std::pair<Path, int>> combinePurePath(
        const std::vector<std::vector<Path>>& purePaths,
        const Path& currPath,
        const Sequence& currSequence,
        std::vector<bool>& isVisitedSequence,
        const std::vector<Sequence>& sequences,
        const Matrix& matrix, size_t maxLengthPath, int score);

Path concatenatePaths(const Path& rhsPath, const Path& lhsPath);
bool isCreatedPathsAfterCurrent(
        const Path& currPath,
        const Path& nextPath,
        const Sequence& currSequence,
        const Sequence& nextSequence,
        const Matrix& matrix,
        size_t maxLengthPath,
        std::vector<Path>& outPaths);

bool hasOverlapping(const Sequence& rhsPath, const Sequence& lhsPath, size_t& overlapLength);
bool hasIntersection(const Path& rhsPath, const Path& lhsPath);

}

namespace UPosition {

bool isFoundNotVisitedPositionInRow(
        const std::vector<Position>& row,
        const Position& currPosition,
        const std::vector<bool>& isVisitedCol,
        int maxColumnCount, int& notVisitedCol);
bool isPositionIsAnyPaths(const Path& rhsPath, const Path& lhsPath, const Position& position);
bool isFoundNextPositionsInColsAndRowsByPosition(
        const Matrix& matrix,
        const std::pair<Position, Path>& startPositionAndPath,
        const Position& positionToFound,
        std::queue<std::pair<Position, Path>>& queue,
        bool isStartFromCol = false);
bool isFoundInRowByPosition(const Matrix& matrix,  const Position& startPosition,  const Position& positionToFound, std::vector<Position>& outVector);
bool isFoundInColByPosition(const Matrix& matrix,  const Position& startPosition,  const Position& positionToFound, std::vector<Position>& outVector);
bool isFoundNextPositionsInColsAndRowsByValue(
        const Matrix& matrix,
        const std::pair<Position, Path>& startPositionAndPath,
        unsigned char value,
        std::stack<std::pair<Position, Path>>& stack,
        bool isStartFromCol = false);
}

namespace UMatrix {

bool isValid(const Position& currPosition, const Matrix& isVisitedMatrix, const Matrix& matrix, unsigned char seqValue);
bool isFoundInRow(const Matrix& matrix,  const Position& startPosition, unsigned char value, std::vector<Position>& outVector);
bool isFoundInCol(const Matrix& matrix,  const Position& startPosition, unsigned char value, std::vector<Position>& outVector);
Matrix createIsVisitedMatrix(int row, int col, const Position& startPosition);
void setVisitedPositions(Matrix& isVisitedMatrix, const Path& visitedPath = Path(std::vector<Position>{}));
}

namespace USequence {
bool isPossibleAddWastedMovesBetweenSequences(const Path& rhsPath, const Path& lhsPath, const Matrix& matrix, size_t maxLengthPath, std::vector<Path>& outPaths);
bool isPossibleAddWastedMovesBeforeFirstSequences(const Path& path, int maxColumnCount, size_t maxLengthPath, Path& outPath);

bool addOneWastedMoveBeforeFirstSequence(const Path& path, Path& outPath);
bool addTwoWastedMovesBeforeFirstSequence(const Path& path, int maxColumnCount, Path& outPath);
}


}

#endif // INTERNALUTILS_H
