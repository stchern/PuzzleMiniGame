#include "SequenceUtils.h"
#include "PositionUtils.h"
#include "PathUtils.h"
#include "Search.h"


bool InternalUtils::USequence::isPossibleAddWastedMovesBetweenSequences(const Path& lhsPath, const Path& rhsPath, const Matrix& matrix, const size_t maxLengthPath, std::vector<Path>& outPaths)
{
    size_t sizeFirst = lhsPath.positions().size();
    size_t sizeSecond = rhsPath.positions().size();

    if (sizeFirst + sizeSecond > maxLengthPath)
        return false;

    Position lastPosOfPathFirst = lhsPath.positions()[sizeFirst - 1];
    Position firstPosOfPathSecond = rhsPath.positions()[0];

    bool isFinishByColFirst = !(lastPosOfPathFirst.column() - lhsPath.positions()[sizeFirst - 2].column());
    bool isStartByColSecond = !(firstPosOfPathSecond.column() - rhsPath.positions()[1].column());

    std::vector<Path> intermediatePaths;
    std::vector<Path> possibleIntermediatePaths = Search::BFS(matrix, lastPosOfPathFirst, firstPosOfPathSecond, isStartByColSecond, !isFinishByColFirst);
    for (const Path& possibleIntermediatePath: possibleIntermediatePaths) {
        bool value = true;
        for (const Position& position: possibleIntermediatePath.positions())
            if (InternalUtils::UPosition::isPositionInPath(lhsPath.positions(), position) ||
                    InternalUtils::UPosition::isPositionInPath(rhsPath.positions(), position))
                value = false;
        if (value && sizeFirst + sizeSecond + possibleIntermediatePath.positions().size() <= maxLengthPath)
            intermediatePaths.push_back(possibleIntermediatePath);
    }

    for (const Path& intermediatePath: intermediatePaths)
        if (sizeFirst + sizeSecond + intermediatePath.positions().size() <= maxLengthPath) {
            Path resultPath = InternalUtils::UPath::concatenatePaths(lhsPath, intermediatePath);
            outPaths.push_back(InternalUtils::UPath::concatenatePaths(resultPath, rhsPath));
        }

    return !outPaths.empty();
}

bool InternalUtils::USequence::isPossibleAddWastedMovesBeforeFirstSequences(const Path& path, const int maxColumnCount, const size_t maxLengthPath, std::vector<Path>& outPaths)
{
    if (path.positions().size() > maxLengthPath || path.positions().size() == 0)
        return false;

    Position firstPathPosition = path.positions()[0];

    if (firstPathPosition.row() == 0) {
        outPaths.push_back(path);
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
                if (path.positions().size() + 2 <= maxLengthPath)
                    return addTwoWastedMovesBeforeFirstSequence(path, maxColumnCount, outPaths);
            }
            else {
                if (path.positions().size() + 1 <= maxLengthPath)
                    return addOneWastedMoveBeforeFirstSequence(path, outPaths);
            }
        }
        else {
            if (path.positions().size() + 1 <= maxLengthPath)
                return addOneWastedMoveBeforeFirstSequence(path, outPaths);
        }
    }

    return false;
}

bool InternalUtils::USequence::addOneWastedMoveBeforeFirstSequence(const Path& path, std::vector<Path>& outPaths)
{
    Position firstPathPosition = path.positions()[0];
    Position possibleFirstPathPosition(0, firstPathPosition.column());

    if (InternalUtils::UPosition::isPositionInPath(path.positions(), possibleFirstPathPosition))
        return false;

    outPaths.push_back(InternalUtils::UPath::concatenatePaths(Path(std::vector<Position>({possibleFirstPathPosition})), path));
    return true;
}

bool InternalUtils::USequence::addTwoWastedMovesBeforeFirstSequence(const Path& path, const int maxColumnCount, std::vector<Path>& outPaths)
{
    Position firstPathPosition = path.positions()[0];
    std::vector<Path> possibleTwoWastedMoves;
    if (InternalUtils::UPosition::isFoundTwoPositionsForWastedMoves(path.positions(), firstPathPosition, maxColumnCount, possibleTwoWastedMoves))
        for (const Path& twoWastedMoves: possibleTwoWastedMoves)
            outPaths.push_back(InternalUtils::UPath::concatenatePaths(twoWastedMoves, path));

    return !possibleTwoWastedMoves.empty();
}
