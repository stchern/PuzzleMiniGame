#ifndef POSITIONUTILS_H
#define POSITIONUTILS_H

#include <stack>
#include <queue>
#include "Position.h"
#include "Matrix.h"
#include "Path.h"

namespace InternalUtils {

namespace UPosition {

//bool isFoundNotVisitedPositionInRow(
//        const std::vector<Position>& row,
//        const Position& currPosition,
//        const std::vector<bool>& isVisitedCol,
//        int maxColumnCount, int& notVisitedCol);
bool isPositionInPath(const std::vector<Position>& pathPositions, const Position& position);
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

bool isFoundTwoPositionsForWastedMoves(const std::vector<Position>& positions, const Position& currPosition, const int maxColumnCount, Path& outPathOfTwoPositions);

}
}

#endif // POSITIONUTILS_H
