#include "Utils.h"
#include "MatrixUtils.h"
#include "Search.h"
#include "SequenceUtils.h"
#include "PathUtils.h"
#include <QDebug>

using namespace InternalUtils;

std::vector<std::vector<Position>> Utils::beginningSequencesList(const Matrix& matrix, const std::vector<Sequence>& sequences)
{
    std::vector<std::vector<Position>> beginningSequencesList(sequences.size());
    for (size_t seqIdx = 0; seqIdx < sequences.size(); ++seqIdx)
        for (size_t row = 0; row < matrix.rowCount(); ++row) {
            std::vector<Position> startPositionsForSequence;
            if (InternalUtils::UMatrix::isFoundInRow(matrix, Position(row, -1), sequences[seqIdx].codes()[0], startPositionsForSequence))
                for (const Position& pos: startPositionsForSequence)
                    beginningSequencesList[seqIdx].push_back(pos);
        }

    return beginningSequencesList;
}

std::vector<std::vector<Path>> Utils::findAllPurePaths(
        const Matrix& matrix,
        const std::vector<Sequence>& sequences,
        const std::vector<std::vector<Position>>& adjacencyMatrix,
        size_t maxLengthPath)
{
    std::vector<std::vector<Path>> possiblePurePaths(sequences.size());

    for (size_t seqIdx = 0; seqIdx < adjacencyMatrix.size(); ++seqIdx)
        for (size_t currStartPosIdx = 0; currStartPosIdx < adjacencyMatrix[seqIdx].size(); ++currStartPosIdx) {
            std::vector<Path> purePathForCurr = Search::DFS(matrix, sequences[seqIdx], adjacencyMatrix[seqIdx][currStartPosIdx], maxLengthPath);
            if (!purePathForCurr.empty())
                for (const Path& path: purePathForCurr)
                    possiblePurePaths[seqIdx].push_back(path);
        }

    return possiblePurePaths;
}

std::vector<std::vector<std::pair<Path, int>>> Utils::combinePurePaths(
        const std::vector<std::vector<Path>>& purePaths,
        const Matrix& matrix,
        const std::vector<Sequence>& sequences,
        const size_t maxLengthPath)
{
    std::vector<bool> isVisitedSequence(purePaths.size(), false);
    std::vector<std::vector<std::pair<Path, int>>> possiblePathsAndScore;
    possiblePathsAndScore.reserve(purePaths.size());

    for (size_t currSeqIdx = 0; currSeqIdx < purePaths.size(); ++currSeqIdx) {
        isVisitedSequence[currSeqIdx] = true;

        for (size_t pathIdx = 0; pathIdx < purePaths[currSeqIdx].size(); ++pathIdx) {
            std::vector<Path> currPaths;
            if (InternalUtils::USequence::isPossibleAddWastedMovesBeforeFirstSequences(purePaths[currSeqIdx][pathIdx], matrix.columnCount(), maxLengthPath, currPaths)) {
                std::vector<std::pair<Path, int>> possiblePathsForCurrent;
                for (const Path& currPath: currPaths) {
                    possiblePathsForCurrent.push_back(std::make_pair(currPath, sequences[currSeqIdx].score()));
                    InternalUtils::UPath::combinePurePath(
                                purePaths, currPath,
                                sequences, matrix,
                                maxLengthPath, sequences[currSeqIdx].score(),
                                isVisitedSequence, possiblePathsForCurrent);
                }
                possiblePathsAndScore.push_back(possiblePathsForCurrent);
            }
        }
        isVisitedSequence[currSeqIdx] = false;
    }

    return possiblePathsAndScore;
}


Path Utils::findBestPath(const std::vector<std::vector<std::pair<Path, int>>>& allPaths)
{
    Path bestPath(std::vector<Position>({}));
    int maxScore = -INFINITY;
    int length = INFINITY;

    for (const std::vector<std::pair<Path, int>>& paths: allPaths) {
        for (const std::pair<Path, int>& path: paths) {
            if (path.second == maxScore && path.first.positions().size() < length) {
                maxScore = path.second;
                length = path.first.positions().size();
                bestPath = path.first;
            }
            if (path.second > maxScore) {
                maxScore = path.second;
                length = path.first.positions().size();
                bestPath = path.first;
            }
        }
    }
    return bestPath;
}

