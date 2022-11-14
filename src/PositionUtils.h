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
        const std::pair<Position, Path>& startPositionAndPath,
        const Position& positionToFound,
        size_t rowCount, size_t columnCount,
        std::queue<std::pair<Position, Path>>& queue,
        bool isStartFromCol = false);

void nextPositionsInCol(
        const std::pair<Position, Path>& startPositionAndPath,
        const Position& positionToFound,
        size_t rowCount,
        std::queue<std::pair<Position, Path>>& queue);

void nextPositionsInRow(
        const std::pair<Position, Path>& startPositionAndPath,
        const Position& positionToFound,
        size_t columnCount,
        std::queue<std::pair<Position, Path>>& queue);

bool isFoundNextPositionsInColsAndRowsByValue(
        const Matrix& matrix,
        const std::pair<Position, Path>& startPositionAndPath,
        unsigned char value,
        std::stack<std::pair<Position, Path>>& stack,
        bool isStartFromCol = false);

bool isFoundTwoPositionsForWastedMoves(const std::vector<Position>& positions, const Position& currPosition, const int maxColumnCount, std::vector<Path>& outPathsOfTwoPositions);

}
}

#endif // POSITIONUTILS_H
