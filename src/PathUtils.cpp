#include "PathUtils.h"
#include "SequenceUtils.h"


std::vector<std::pair<Path, int>> InternalUtils::UPath::combinePurePath(
        const std::vector<std::vector<Path>>& purePaths,
        const Path& currPath,
        const std::vector<Sequence>& sequences,
        const Matrix& matrix, size_t maxLengthPath, int score,
        std::vector<bool>& outIsVisitedSequence)
{
    int currScore = score;
    std::vector<std::pair<Path, int>> possiblePathsAndScore;

    for (size_t seqIdx = 0; seqIdx < purePaths.size(); ++seqIdx) {
        if (outIsVisitedSequence[seqIdx])
            continue;
        outIsVisitedSequence[seqIdx] = true;
        int nextScore = sequences[seqIdx].score();
        for (size_t pathIdx = 0; pathIdx < purePaths[seqIdx].size(); ++pathIdx) {
            std::vector<Path> resultPaths;
              if (isCreatedPathsAfterCurrent(currPath, purePaths[seqIdx][pathIdx], matrix, maxLengthPath, resultPaths)) {

                for (const Path& path: resultPaths) {
                    possiblePathsAndScore.push_back(std::pair(path, currScore + nextScore));
                    std::vector<std::pair<Path, int>> currPathAndScore = combinePurePath(
                                purePaths, path,
                                sequences, matrix,
                                maxLengthPath, currScore + nextScore,
                                outIsVisitedSequence);
                }
            }

        }
        outIsVisitedSequence[seqIdx] = false;
    }

    return possiblePathsAndScore;
}


bool InternalUtils::UPath::isCreatedPathsAfterCurrent(
        const Path& currPath,
        const Path& nextPath,
        const Matrix& matrix,
        const size_t maxLengthPath,
        std::vector<Path>& outPaths)
{
    if (currPath.length() + nextPath.length() > maxLengthPath)
        return false;
    if (hasIntersection(currPath, nextPath))
        return false;

    size_t overlapLength = 0;
    const Sequence currSequence = matrix.sequenceByPath(currPath);
    const Sequence nextSequence = matrix.sequenceByPath(nextPath);

    if (InternalUtils::USequence::hasOverlapping(currSequence, nextSequence, overlapLength)) {
        Path partOfNextPathForConcatenation(std::vector<Position>(std::begin(nextPath.positions()) + overlapLength, std::end(nextPath.positions())));
        outPaths.push_back(concatenatePaths(currPath, partOfNextPathForConcatenation));
        return true;
    }
    if (InternalUtils::USequence::isPossibleAddWastedMovesBetweenSequences(currPath, nextPath, matrix, maxLengthPath, outPaths))
        return true;
    return false;
}


bool InternalUtils::UPath::hasIntersection(const Path& rhsPath, const Path& lhsPath)
{
    std::vector<Position> rhs = rhsPath.positions();
    std::vector<Position> lhs = lhsPath.positions();
    std::sort(std::begin(rhs), std::end(rhs));
    std::sort(std::begin(lhs), std::end(lhs));
    std::vector<Position> intersection;
    std::set_intersection(std::begin(rhs), std::end(rhs), std::begin(lhs), std::end(lhs), std::back_inserter(intersection));

    if (intersection.empty())
        return false;

    rhs = rhsPath.positions();
    lhs = lhsPath.positions();
    std::vector<Position>::iterator lhsFirstInRhs = std::find(std::begin(intersection), std::end(intersection), lhs[0]);
    if (lhsFirstInRhs == std::end(intersection))
        return true;

    lhsFirstInRhs = std::find(std::begin(rhs), std::end(rhs), lhs[0]);
    std::vector<Position>::iterator trueLhs = std::begin(lhs);

    while (lhsFirstInRhs != std::end(rhs)) {
        if (*lhsFirstInRhs == *trueLhs) {
            ++lhsFirstInRhs;
            ++trueLhs;
        }
        else {
            return true;
        }
    }

    return false;
}

Path InternalUtils::UPath::concatenatePaths(const Path& rhsPath, const Path& lhsPath)
{
    std::vector<Position> resultPosition(std::begin(rhsPath.positions()), std::end(rhsPath.positions()));
    resultPosition.insert(std::end(resultPosition), std::begin(lhsPath.positions()), std::end(lhsPath.positions()));
    return Path(resultPosition);
}

