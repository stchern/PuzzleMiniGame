#include "PathUtils.h"
#include "SequenceUtils.h"

std::vector<std::pair<Path, int>> InternalUtils::UPath::combinePurePath(
        const std::vector<std::vector<Path>>& purePaths,
        const Path& currPath,
        const Sequence& currSequence,
        std::vector<bool>& isVisitedSequence,
        const std::vector<Sequence>& sequences,
        const Matrix& matrix, size_t maxLengthPath, int score)
{
    int currScore = score;
    std::vector<std::pair<Path, int>> possiblePathsAndScore;

    for (size_t seqIdx = 0; seqIdx < purePaths.size(); ++seqIdx) {
        if (isVisitedSequence[seqIdx])
            continue;
        isVisitedSequence[seqIdx] = true;
        int nextScore = sequences[seqIdx].score();
        Sequence nextSequence = sequences[seqIdx];
        for (size_t pathIdx = 0; pathIdx < purePaths[seqIdx].size(); ++pathIdx) {
            std::vector<Path> resultPaths;
            if (isCreatedPathsAfterCurrent(currPath, purePaths[seqIdx][pathIdx], currSequence, nextSequence, matrix, maxLengthPath, resultPaths)) {

                for (const Path& path: resultPaths) {
                    possiblePathsAndScore.push_back(std::pair(path, currScore + nextScore));
                    std::vector<std::pair<Path, int>> currPathAndScore = combinePurePath(
                                purePaths, path,
                                matrix.sequenceByPath(path), isVisitedSequence,
                                sequences, matrix,
                                maxLengthPath, currScore + nextScore);
                }
            }

        }
        isVisitedSequence[seqIdx] = false;
    }

    return possiblePathsAndScore;
}


bool InternalUtils::UPath::isCreatedPathsAfterCurrent(
        const Path& currPath,
        const Path& nextPath,
        const Sequence& currSequence,
        const Sequence& nextSequence,
        const Matrix& matrix,
        size_t maxLengthPath,
        std::vector<Path>& outPaths)
{
    if (currPath.positions().size() + nextPath.positions().size() > maxLengthPath)
        return false;
    if (hasIntersection(currPath, nextPath))
        return false;

    //    Position specificPosition = nextPath.positions()[0];
    size_t overlapLength = 0;
    if (hasOverlapping(currSequence, nextSequence, overlapLength)) {
        Path partOfNextPathForConcatenation(std::vector<Position>(std::begin(nextPath.positions()) + overlapLength, std::end(nextPath.positions())));
        //find by dfs part of path

        outPaths.push_back(concatenatePaths(currPath, partOfNextPathForConcatenation));
        return true;
    }
    if (InternalUtils::USequence::isPossibleAddWastedMovesBetweenSequences(currPath, nextPath, matrix, maxLengthPath, outPaths))
        return true;
    return false;
}

bool InternalUtils::UPath::hasOverlapping(const Sequence& rhsSeq, const Sequence& lhsSeq, size_t& overlapLength)
{

    auto beginIt = std::begin(lhsSeq.codes());
    auto endIt = std::end(lhsSeq.codes());

    while (endIt != beginIt) {
        auto it = std::search(std::begin(rhsSeq.codes()), std::end(rhsSeq.codes()), std::begin(lhsSeq.codes()), std::end(lhsSeq.codes()));
        if (it != std::end(rhsSeq.codes())) {
            overlapLength = endIt - beginIt;
            return true;
        }
        overlapLength = endIt - beginIt;
        return true;
    }
    return false;
}

bool InternalUtils::UPath::hasIntersection(const Path& rhsPath, const Path& lhsPath)
{
    std::vector<Position> rhs = rhsPath.positions();
    std::vector<Position> lhs = lhsPath.positions();
    std::sort(std::begin(rhs), std::end(rhs));
    std::sort(std::begin(lhs), std::end(lhs));
    std::vector<Position> intersection(rhs.size() + lhs.size());
    std::set_intersection(std::begin(rhs), std::end(rhs), std::begin(lhs), std::end(lhs), std::begin(intersection));

    if (intersection.empty())
        return false;

    std::vector<Position>::iterator lhsFirstInRhs = std::find(std::begin(intersection), std::end(intersection), lhs[0]);
    if (lhsFirstInRhs == std::end(intersection))
        return true;

    lhsFirstInRhs = std::find(std::begin(rhs), std::end(rhs), lhs[0]);
    std::vector<Position>::iterator trueLhs = std::begin(lhs);

    if (lhsFirstInRhs == std::end(rhs)) {
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
    return false;
}

Path InternalUtils::UPath::concatenatePaths(const Path& rhsPath, const Path& lhsPath)
{
    Path resultPath;
    for (const Position& position: rhsPath.positions())
        resultPath.push_back(position);
    for (const Position& position: lhsPath.positions())
        resultPath.push_back(position);

    return resultPath;
}

