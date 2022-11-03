#include "SequenceUtils.h"
#include "PositionUtils.h"
#include "PathUtils.h"
#include "Search.h"


bool InternalUtils::USequence::isPossibleAddWastedMovesBetweenSequences(const Path& rhsPath, const Path& lhsPath, const Matrix& matrix, const size_t maxLengthPath, std::vector<Path>& outPaths)
{
    size_t sizeFirst = rhsPath.positions().size();
    size_t sizeSecond = lhsPath.positions().size();

    if (sizeFirst + sizeSecond > maxLengthPath)
        return false;

    Position lastPosOfPathFirst = rhsPath.positions()[sizeFirst - 1];
    Position firstPosOfPathSecond = lhsPath.positions()[0];
    std::vector<Path> intermediatePaths;
    if (sizeFirst > 1 && sizeSecond > 1) {
        bool isFinishByColFirst = !(lastPosOfPathFirst.column() - rhsPath.positions()[sizeFirst - 2].column());
        bool isStartByColSecond = !(firstPosOfPathSecond.column() - lhsPath.positions()[1].column());

        if (isFinishByColFirst != isStartByColSecond) {
            Position intersectionPoint(0, 0);
            if (isFinishByColFirst)
                intersectionPoint = Position(lastPosOfPathFirst.row(), firstPosOfPathSecond.column());

            if (isStartByColSecond)
                intersectionPoint = Position(firstPosOfPathSecond.row(), lastPosOfPathFirst.column());

            if (!InternalUtils::UPosition::isPositionInPath(rhsPath.positions(), intersectionPoint) &&
                    !InternalUtils::UPosition::isPositionInPath(lhsPath.positions(), intersectionPoint) && sizeFirst + sizeSecond + 1 <= maxLengthPath)
                intermediatePaths.push_back(Path(std::vector<Position>({intersectionPoint})));
        }
        else {
            if (firstPosOfPathSecond.row() == lastPosOfPathFirst.row() || firstPosOfPathSecond.column() == lastPosOfPathFirst.column()) {
                outPaths.push_back(InternalUtils::UPath::concatenatePaths(rhsPath, lhsPath));
                return true;
            }
                std::vector<Path> possibleIntermediatePaths = Search::BFS(matrix, lastPosOfPathFirst, firstPosOfPathSecond, isStartByColSecond, !isFinishByColFirst);
                for (const Path& possibleIntermediatePath: possibleIntermediatePaths) {
                    bool value = true;
                    for (const Position& position: possibleIntermediatePath.positions())
                        if (InternalUtils::UPosition::isPositionInPath(rhsPath.positions(), position) ||
                                InternalUtils::UPosition::isPositionInPath(lhsPath.positions(), position))
                                    value = false;
                    if (value && sizeFirst + sizeSecond + possibleIntermediatePath.positions().size() <= maxLengthPath)
                        intermediatePaths.push_back(possibleIntermediatePath);
                }
        }


        if (intermediatePaths.empty())
            return false;

        for (const Path& intermediatePath: intermediatePaths)
            if (sizeFirst + sizeSecond + intermediatePath.positions().size() <= maxLengthPath) {
                Path resultPath = InternalUtils::UPath::concatenatePaths(rhsPath, intermediatePath);
                outPaths.push_back(InternalUtils::UPath::concatenatePaths(resultPath, lhsPath));
            }

        return true;
    }
    else
    {
        if (sizeFirst == 1 && sizeSecond == 1)
            if (firstPosOfPathSecond.row() == lastPosOfPathFirst.row() || firstPosOfPathSecond.column() == lastPosOfPathFirst.column()) {
                outPaths.push_back(InternalUtils::UPath::concatenatePaths(rhsPath, lhsPath));
                return true;
            }

        std::vector<std::vector<Path>> possibleIntermediatePaths;
        if (sizeFirst == 1)
        {
            bool isStartByColSecond = !(firstPosOfPathSecond.column() - lhsPath.positions()[1].column());
            possibleIntermediatePaths.push_back(Search::BFS(matrix, lastPosOfPathFirst, firstPosOfPathSecond, isStartByColSecond, true));
            possibleIntermediatePaths.push_back(Search::BFS(matrix, lastPosOfPathFirst, firstPosOfPathSecond, isStartByColSecond, false));
        }
        else
        {
            bool isFinishByColFirst = !(lastPosOfPathFirst.column() - rhsPath.positions()[sizeFirst - 2].column());
            possibleIntermediatePaths.push_back(Search::BFS(matrix, lastPosOfPathFirst, firstPosOfPathSecond, true, !isFinishByColFirst));
            possibleIntermediatePaths.push_back(Search::BFS(matrix, lastPosOfPathFirst, firstPosOfPathSecond, false, !isFinishByColFirst));
        }

        for (const std::vector<Path>& intermediatePaths: possibleIntermediatePaths)
            if (!intermediatePaths.empty())
                for (const Path& intermediatePath: intermediatePaths) {
                    bool value = true;
                    for (const Position& position: intermediatePath.positions())
                        if (InternalUtils::UPosition::isPositionInPath(rhsPath.positions(), position) ||
                                InternalUtils::UPosition::isPositionInPath(lhsPath.positions(), position))
                                    value = false;
                    if (value && sizeFirst + sizeSecond + intermediatePath.positions().size() <= maxLengthPath) {
                        Path resultPath = InternalUtils::UPath::concatenatePaths(rhsPath, intermediatePath);
                        outPaths.push_back(InternalUtils::UPath::concatenatePaths(resultPath, lhsPath));
                    }
            }
        if (!outPaths.empty())
            return true;
    }
    return false;
}

bool InternalUtils::USequence::isPossibleAddWastedMovesBeforeFirstSequences(const Path& path, const int maxColumnCount, const size_t maxLengthPath, Path& outPath)
{
    if (path.positions().size() > maxLengthPath || path.positions().size() == 0)
        return false;

    Position firstPathPosition = path.positions()[0];

    if (firstPathPosition.row() == 0) {
        outPath = path;
        if (path.positions().size() > 1) {
            Position secondPathPosition = path.positions()[1];
            if (secondPathPosition.column() == firstPathPosition.column())
                return true;
            else{
                // option when 3 wasted moves;
            }
        }
        return true;
    }
    else
    {
        if (path.positions().size() > 1) {
            Position secondPathPosition = path.positions()[1];
            bool isStartFromCol = (firstPathPosition.row() - secondPathPosition.row());
            if (isStartFromCol) {
                if (outPath.positions().size() + 2 > maxLengthPath)
                    return false;
                return addTwoWastedMovesBeforeFirstSequence(path, maxColumnCount, outPath);
            }
            else {
                if (outPath.positions().size() + 1 > maxLengthPath)
                    return false;
                return addOneWastedMoveBeforeFirstSequence(path, outPath);
            }
        }
        else {
            if (outPath.positions().size() + 1 > maxLengthPath)
                return false;
            return addOneWastedMoveBeforeFirstSequence(path, outPath);
        }

    }
}

bool InternalUtils::USequence::addOneWastedMoveBeforeFirstSequence(const Path& path, Path& outPath)
{
    Position firstPathPosition = path.positions()[0];
    Position possibleFirstPathPosition(0, firstPathPosition.column());

    if (InternalUtils::UPosition::isPositionInPath(path.positions(), possibleFirstPathPosition))
        return false;

    outPath = InternalUtils::UPath::concatenatePaths(Path(std::vector<Position>({possibleFirstPathPosition})), path);
    return true;
}

bool InternalUtils::USequence::addTwoWastedMovesBeforeFirstSequence(const Path& path, const int maxColumnCount, Path& outPath)
{
    Position firstPathPosition = path.positions()[0];
    Path pathOfTwoPositions;
    if (InternalUtils::UPosition::isFoundTwoPositionsForWastedMoves(path.positions(), firstPathPosition, maxColumnCount, pathOfTwoPositions)) {
                outPath = InternalUtils::UPath::concatenatePaths(pathOfTwoPositions, path);
                return true;
    }
    return false;
}

bool InternalUtils::USequence::hasOverlapping(const Sequence& rhsSeq, const Sequence& lhsSeq, size_t& overlapLength)
{
    overlapLength = 0;
    auto beginIt = std::begin(lhsSeq.codes());
    auto endIt = std::end(lhsSeq.codes());

    while (endIt != beginIt) {

        if (endIt - beginIt == 1)
            if (*beginIt == *(--std::end(rhsSeq.codes()))) {
                overlapLength = 1;
                return true;
            }

        auto it = std::search(std::begin(rhsSeq.codes()), std::end(rhsSeq.codes()), std::begin(lhsSeq.codes()), endIt);
        if (it != std::end(rhsSeq.codes()))
            if (endIt == std::end(lhsSeq.codes()) || it + (endIt - beginIt) == std::end(rhsSeq.codes())) {
                overlapLength = endIt - beginIt;
                return true;
            }

        --endIt;
    }
    return false;
}
