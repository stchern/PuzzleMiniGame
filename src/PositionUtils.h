#ifndef POSITIONUTILS_H
#define POSITIONUTILS_H

#include <stack>
#include <queue>
#include "Position.h"
#include "Matrix.h"
#include "Path.h"

namespace InternalUtils {

namespace UPosition {

bool isPositionInPath(const std::vector<Position>& pathPositions, const Position& position);
void nextPositionsInColsOrRows(
        const Matrix& matrix,
        const std::pair<Position, Path>& startPositionAndPath,
        const Position& positionToFound,
        std::queue<std::pair<Position, Path>>& queue,
        bool isStartFromCol = false);

bool isFoundNextPositionsInColsAndRowsByValue(
        const Matrix& matrix,
        const std::pair<Position, Path>& startPositionAndPath,
        unsigned char value,
        std::stack<std::pair<Position, Path>>& stack,
        bool isStartFromCol = false);

bool isFoundTwoPositionsForWastedMoves(const std::vector<Position>& positions, const Position& currPosition, const int maxColumnCount, Path& outPathOfTwoPositions);

}
}

#endif // POSITIONUTILS_H
