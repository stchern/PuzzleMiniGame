#include <vector>
#include "Position.h"
#include "Sequence.h"
#include "Matrix.h"
#include "Path.h"
#include<stack>
#include <queue>

namespace Utils
{

std::vector<std::vector<std::pair<Path, int>>> combinePurePaths(const std::vector<std::vector<Path>>& purePaths, const Matrix& matrix, const std::vector<Sequence>& sequences, size_t maxLengthPath);
Path findBestPath(const std::vector<std::vector<std::pair<Path, int>>>& allPaths);
std::vector<std::vector<Position>> adjacencyMatrix(const Matrix& matrix, const std::vector<Sequence>& sequences);
std::vector<std::vector<Path>> findAllPurePaths(
        const Matrix& matrix,
        const std::vector<Sequence>& sequences,
        const std::vector<std::vector<Position>>& adjacencyMatrix,
        size_t maxLengthPath);


namespace Internal {

std::vector<Path> BFS(
        const Matrix& matrix,
        const Position& endPosition,
        const Position& startPosition,
        bool isNextSeqStartByCol,
        bool isStartFromCol);

std::vector<Path> DFS(const Matrix& matrix, const Sequence& sequences, const Position& startPosition, std::size_t maxLengthPath);

std::vector<std::pair<Path, int>> combinePurePath(
        const std::vector<std::vector<Path>>& purePaths,
        const Path& currPath,
        const Sequence& currSequence,
        std::vector<bool>& isVisitedSequence,
        const std::vector<Sequence>& sequences,
        const Matrix& matrix, size_t maxLengthPath, int score);

bool isCreatedPathsAfterCurrent(
        const Path& currPath,
        const Path& nextPath,
        const Sequence& currSequence,
        const Sequence& nextSequence,
        const Matrix& matrix,
        size_t maxLengthPath,
        std::vector<Path>& outPaths);
Path concatenatePaths(const Path& rhsPath, const Path& lhsPath);
bool hasOverlapping(const Sequence& rhsPath, const Sequence& lhsPath, size_t& overlapLength);
bool hasIntersection(const Path& rhsPath, const Path& lhsPath);
bool isPossibleAddWastedMovesBetweenSequences(const Path& rhsPath, const Path& lhsPath, const Matrix& matrix, size_t maxLengthPath, std::vector<Path>& outPaths);
bool isPossibleAddWastedMovesBeforeFirstSequences(const Path& path, int maxColumnCount, size_t maxLengthPath, Path& outPath);
bool addOneWastedMoveBeforeFirstSequence(const Path& path, Path& outPath);
bool addTwoWastedMovesBeforeFirstSequence(const Path& path, int maxColumnCount, Path& outPath);
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


bool isValid(const Position& currPosition, const Matrix& isVisitedMatrix, const Matrix& matrix, unsigned char seqValue);
bool isFoundNextPositionsInColsAndRowsByValue(
        const Matrix& matrix,
        const std::pair<Position, Path>& startPositionAndPath,
        unsigned char value,
        std::stack<std::pair<Position, Path>>& stack,
        bool isStartFromCol = false);
bool isFoundInRow(const Matrix& matrix,  const Position& startPosition, unsigned char value, std::vector<Position>& outVector);
bool isFoundInCol(const Matrix& matrix,  const Position& startPosition, unsigned char value, std::vector<Position>& outVector);
Matrix createIsVisitedMatrix(int row, int col, const Position& startPosition);
void setVisitedPositions(Matrix& isVisitedMatrix, const Path& visitedPath = Path(std::vector<Position>{}));


}
}
