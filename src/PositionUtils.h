#ifndef POSITIONUTILS_H
#define POSITIONUTILS_H

#include <stack>
#include <queue>
#include "Position.h"
#include "Matrix.h"
#include "Path.h"

namespace InternalUtils {

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
}

#endif // POSITIONUTILS_H
