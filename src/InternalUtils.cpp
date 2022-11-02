#include "InternalUtils.h"


std::vector<Path> InternalUtils::DFS(
        const Matrix& matrix,
        const Sequence& sequence,
        const Position& startPosition,
        std::size_t maxLengthPath)
{
    if (sequence.codes().size() == 1)
        return std::vector<Path>{Path(std::vector<Position>{startPosition})};

    std::vector<Path> possiblePaths;
    if (sequence.codes().size() >= maxLengthPath)
        return possiblePaths;

    Matrix isVisitedMatrix = createIsVisitedMatrix(matrix.rowCount(), matrix.columnCount(), startPosition);
    bool isStartFromCol = true;
    auto seqIt = std::next(sequence.codes().begin());
    std::vector<Position> foundPositions;
    foundPositions.reserve(matrix.columnCount());
    std::stack<std::pair<Position, Path>> stack;

    if (isFoundInRow(matrix, startPosition, *seqIt, foundPositions) | isFoundInCol(matrix, startPosition, *seqIt, foundPositions))
        for (const Position& position: foundPositions)
            stack.push(std::make_pair(position, Path(std::vector<Position>{startPosition, position})));

    while (!stack.empty()) {
        std::pair<Position, Path> positionAndPath = stack.top();
        stack.pop();
        Position currPosition = positionAndPath.first;
        Path possiblePath = positionAndPath.second;

        if (!isValid(currPosition, isVisitedMatrix, matrix, *seqIt))
            continue;

        isVisitedMatrix.setValue(currPosition, 1);
        seqIt = sequence.codes().begin() + possiblePath.positions().size();

        if (seqIt == sequence.codes().end()) {
            possiblePaths.push_back(Path(possiblePath));
            isVisitedMatrix = createIsVisitedMatrix(matrix.rowCount(), matrix.columnCount(), startPosition);
            if (!stack.empty())
                setVisitedPositions(isVisitedMatrix, stack.top().second);
            continue;
        }

        isStartFromCol = !(currPosition.row() - possiblePath.positions()[possiblePath.positions().size() - 2].row());
        if (!isFoundNextPositionsInColsAndRowsByValue(matrix, positionAndPath, *seqIt, stack, isStartFromCol))
            isVisitedMatrix.setValue(currPosition, 0);
    }

    return possiblePaths;
}


std::vector<Path> InternalUtils::BFS(
        const Matrix& matrix,
        const Position& endPositionCurrSeq,
        const Position& startPositionNextSeq,
        bool isNextSeqStartByCol,
        bool isStartFromCol)
{
    std::vector<Path> possiblePaths;

    Matrix isVisitedMatrix = createIsVisitedMatrix(matrix.rowCount(), matrix.columnCount(), endPositionCurrSeq);
    std::queue<std::pair<Position, Path>> queue;

    Path currPath({endPositionCurrSeq});
    queue.push(std::make_pair( endPositionCurrSeq, currPath));

    isFoundNextPositionsInColsAndRowsByPosition(matrix, std::make_pair(endPositionCurrSeq, currPath), startPositionNextSeq, queue, isStartFromCol);
    queue.pop();

    while (!queue.empty()) {
        std::pair<Position, Path> positionAndPath = queue.front();
        queue.pop();

        Position currPosition = positionAndPath.first;
        Path possiblePath = positionAndPath.second;

        if (isVisitedMatrix.value(currPosition))
            continue;

        if (currPosition == startPositionNextSeq) {
            bool isCurrPathEndByCol = (currPosition.row() - possiblePath.positions()[possiblePath.positions().size() - 2].row());
            if (isCurrPathEndByCol != isNextSeqStartByCol) {
                std::vector<Position> intermediatePath;
                for (size_t idx = 1; idx < possiblePath.positions().size() - 1; ++idx)
                    intermediatePath.push_back(possiblePath.positions()[idx]);
                possiblePaths.push_back(Path(intermediatePath));
                isVisitedMatrix = createIsVisitedMatrix(matrix.rowCount(), matrix.columnCount(), endPositionCurrSeq);
            }
            if (!queue.empty())
                    setVisitedPositions(isVisitedMatrix, Path({startPositionNextSeq}));
            continue;
        }

        if (possiblePath.positions().size() > 3) {
            isVisitedMatrix.setValue(currPosition, 1);
            continue;
        }

        isStartFromCol = !(currPosition.row() - possiblePath.positions()[possiblePath.positions().size() - 2].row());
        isFoundNextPositionsInColsAndRowsByPosition(matrix, positionAndPath, startPositionNextSeq, queue, isStartFromCol);
    }

    return possiblePaths;
}

bool InternalUtils::isFoundNextPositionsInColsAndRowsByPosition(
        const Matrix& matrix,
        const std::pair<Position, Path>& startPositionAndPath,
        const Position& positionToFound,
        std::queue<std::pair<Position, Path>>& stack,
        bool isStartFromCol)
{

    size_t currRow = startPositionAndPath.first.row();
    size_t currCol = startPositionAndPath.first.column();

    if (isStartFromCol) {
        if (currCol == positionToFound.column()) {
            Path newPath = startPositionAndPath.second;
            newPath.push_back(positionToFound);
            stack.push(std::make_pair(positionToFound, newPath));
        }
        else  {
            for (size_t row = 0; row < matrix.rowCount(); ++row)
                if (row != currRow) {
                    Path newPath = startPositionAndPath.second;
                    newPath.push_back(Position(row, currCol));
                    stack.push(std::make_pair(Position(row, currCol), newPath));
                }
        }

    }
    else {
        if (currRow == positionToFound.row()) {
            Path newPath = startPositionAndPath.second;
            newPath.push_back(positionToFound);
            stack.push(std::make_pair(positionToFound, newPath));
        }
        else {
            for (size_t col = 0; col < matrix.columnCount(); ++col)
                if (col != currCol) {
                    Path newPath = startPositionAndPath.second;
                    newPath.push_back(Position(currRow, col));
                    stack.push(std::make_pair(Position(currRow, col), newPath));
                }
        }

    }
}

bool InternalUtils::isValid(const Position& currPosition, const Matrix& isVisitedMatrix, const Matrix& matrix, unsigned char seqValue)
{
    if (isVisitedMatrix.value(currPosition))
        return false;
    return true;

}

bool InternalUtils::isFoundNextPositionsInColsAndRowsByValue(
        const Matrix& matrix,
        const std::pair<Position, Path>& startPositionAndPath,
        unsigned char value,
        std::stack<std::pair<Position, Path>>& stack,
        bool isStartFromCol)
{
    Position startPosition(startPositionAndPath.first);
    std::vector<Position> resultVector;
    bool isFound = false;

    if (!isStartFromCol)
        isFound = isFoundInRow(matrix, startPosition, value, resultVector);
    else
        isFound = isFoundInCol(matrix, startPosition, value, resultVector);

    if (isFound)
        for (const Position& position: resultVector) {
            Path currPath = startPositionAndPath.second;
            currPath.push_back(position);
            stack.push(std::pair(position, currPath));
        }
    return isFound;

}

bool InternalUtils::isFoundInRow(const Matrix& matrix,  const Position& startPosition, unsigned char value, std::vector<Position>& outVector)
{
    size_t startRow = startPosition.row();
    size_t startCol = startPosition.column();
    std::vector<Position> resultVector;

    for(std::size_t col = 0; col < matrix.values()[startRow].size(); ++col)
        if (col != startCol)
            if (matrix.values()[startRow][col] == value)
                resultVector.push_back(Position(startRow, col));

    if (resultVector.empty())
        return false;
    for (const Position& position: resultVector)
        outVector.push_back(position);
    return true;
}

bool InternalUtils::isFoundInCol(const Matrix& matrix,  const Position& startPosition, unsigned char value, std::vector<Position>& outVector)
{

    size_t startRow = startPosition.row();
    size_t startCol = startPosition.column();
    std::vector<Position> resultVector;

    for (size_t row = 0; row < matrix.rowCount(); ++row)
        if (row != startRow)
            if (matrix.values()[row][startCol] == value)
                resultVector.push_back(Position(row, startCol));

    if (resultVector.empty())
        return false;
    for (const Position& position: resultVector)
        outVector.push_back(position);
    return true;
}

Matrix InternalUtils::createIsVisitedMatrix(int row, int col, const Position& startPosition)
{
    Matrix isVisitedMatrix(std::vector<std::vector<unsigned char>>(row, std::vector<unsigned char>(col, 0)));
    isVisitedMatrix.setValue(startPosition, 1);

    return isVisitedMatrix;
}

void InternalUtils::setVisitedPositions(Matrix& isVisitedMatrix, const Path& visitedPath)
{
    if (!visitedPath.positions().empty())
        for (size_t posIdx = 0; posIdx < visitedPath.positions().size() - 1; ++posIdx)
            isVisitedMatrix.setValue(visitedPath.positions()[posIdx], 1);
}

std::vector<std::pair<Path, int>> InternalUtils::combinePurePath(
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


bool InternalUtils::isCreatedPathsAfterCurrent(
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
    if (isPossibleAddWastedMovesBetweenSequences(currPath, nextPath, matrix, maxLengthPath, outPaths))
        return true;
    return false;
}

bool InternalUtils::hasOverlapping(const Sequence& rhsSeq, const Sequence& lhsSeq, size_t& overlapLength)
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

bool InternalUtils::hasIntersection(const Path& rhsPath, const Path& lhsPath)
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

bool InternalUtils::isPossibleAddWastedMovesBetweenSequences(const Path& rhsPath, const Path& lhsPath, const Matrix& matrix, size_t maxLengthPath, std::vector<Path>& outPaths)
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

        if (isFinishByColFirst || !isStartByColSecond) {
            if (firstPosOfPathSecond.row() == lastPosOfPathFirst.row() || firstPosOfPathSecond.column() == lastPosOfPathFirst.column()) {
                outPaths.push_back(concatenatePaths(rhsPath, lhsPath));
                return true;
            }
            Position intersectionPoint(0, 0);
            if (isFinishByColFirst)
                intersectionPoint = Position(firstPosOfPathSecond.row(), lastPosOfPathFirst.column());

            if (isStartByColSecond)
                intersectionPoint = Position(lastPosOfPathFirst.row(), firstPosOfPathSecond.column());

            if (!isPositionIsAnyPaths(rhsPath, lhsPath, intersectionPoint))
                intermediatePaths.push_back(Path(std::vector<Position>({intersectionPoint})));
        }
        else
            intermediatePaths = BFS(matrix, lastPosOfPathFirst, firstPosOfPathSecond, isStartByColSecond, !isFinishByColFirst);

        if (intermediatePaths.empty())
            return false;

        for (const Path& intermediatePath: intermediatePaths) {
            Path resultPath = concatenatePaths(rhsPath, intermediatePath);
            outPaths.push_back(concatenatePaths(resultPath, lhsPath));
        }
        return true;
    }
    else
    {
        if (sizeFirst == 1 && sizeSecond == 1) {
            outPaths.push_back(Path({lastPosOfPathFirst, firstPosOfPathSecond}));
            return true;
        }

        if (firstPosOfPathSecond.row() == lastPosOfPathFirst.row() || firstPosOfPathSecond.column() == lastPosOfPathFirst.column()) {
            outPaths.push_back(concatenatePaths(rhsPath, lhsPath));
            return true;
        }

        std::vector<std::vector<Path>> possibleIntermediatePaths;
        if (sizeFirst == 1)
        {
            bool isStartByColSecond = !(firstPosOfPathSecond.column() - lhsPath.positions()[1].column());
            possibleIntermediatePaths.push_back(BFS(matrix, lastPosOfPathFirst, firstPosOfPathSecond, isStartByColSecond, true));
            possibleIntermediatePaths.push_back(BFS(matrix, lastPosOfPathFirst, firstPosOfPathSecond, isStartByColSecond, false));
        }
        else
        {
            bool isFinishByColFirst = !(lastPosOfPathFirst.column() - rhsPath.positions()[sizeFirst - 2].column());
            possibleIntermediatePaths.push_back(BFS(matrix, lastPosOfPathFirst, firstPosOfPathSecond, true, !isFinishByColFirst));
            possibleIntermediatePaths.push_back(BFS(matrix, lastPosOfPathFirst, firstPosOfPathSecond, false, !isFinishByColFirst));
        }

        for (const std::vector<Path>& intermaediatePaths: possibleIntermediatePaths)
            if (!intermaediatePaths.empty())
                for (const Path& intermediatePath: intermediatePaths) {
                    Path resultPath = concatenatePaths(rhsPath, intermediatePath);
                    outPaths.push_back(concatenatePaths(resultPath, lhsPath));
                }

    }
    return false;
}

bool InternalUtils::isPossibleAddWastedMovesBeforeFirstSequences(const Path& path, int maxColumnCount, size_t maxLengthPath, Path& outPath)
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
            bool isStartFromCol = !(firstPathPosition.row() - secondPathPosition.row());
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

bool InternalUtils::addOneWastedMoveBeforeFirstSequence(const Path& path, Path& outPath)
{
    Position firstPathPosition = path.positions()[0];
    Position possibleFirstPathPosition(0, firstPathPosition.column());

    if (isPositionIsAnyPaths(path, path, possibleFirstPathPosition))
        return false;

    outPath = concatenatePaths(Path(std::vector<Position>({possibleFirstPathPosition})), path);
    return true;
}

bool InternalUtils::addTwoWastedMovesBeforeFirstSequence(const Path& path, int maxColumnCount, Path& outPath)
{
    Position firstPathPosition = path.positions()[0];
    std::vector<bool> isVisitedCol(maxColumnCount, false);
    isVisitedCol[firstPathPosition.column()] = true;
    int notVisitedCol;
    while (std::count(std::begin(isVisitedCol), std::end(isVisitedCol), true))
        if (isFoundNotVisitedPositionInRow(path.positions(), firstPathPosition, isVisitedCol, maxColumnCount, notVisitedCol)) {
            Position possibleSecondPathPosition(firstPathPosition.row(), notVisitedCol);
            isVisitedCol[notVisitedCol] = true;

            if (isFoundNotVisitedPositionInRow(path.positions(), possibleSecondPathPosition, isVisitedCol, maxColumnCount, notVisitedCol)) {
                Position possibleFirstPathPosition(0, notVisitedCol);
                outPath = concatenatePaths(Path(std::vector<Position>({possibleFirstPathPosition, possibleSecondPathPosition})), path);
                return true;
            }
        }
    return false;
}

bool InternalUtils::isFoundNotVisitedPositionInRow(const std::vector<Position>& row, const Position& currPosition, const std::vector<bool>& isVisitedCol, int maxColumnCount, int& notVisitedCol)
{
    size_t currentRow = currPosition.row();
    size_t currentCol = currPosition.column();
    for (size_t col = 0; col < maxColumnCount; ++col)
        if (col != currentCol && !isVisitedCol[col]) {
            auto it = std::find(std::begin(row), std::end(row), Position(currentRow, col));
            if (it != std::end(row)) {
                notVisitedCol = col;
                return true;
            }
        }
    return false;
}

bool InternalUtils::isPositionIsAnyPaths(const Path& rhsPath, const Path& lhsPath, const Position& position)
{
    auto it = std::find(std::begin(rhsPath.positions()), std::end(rhsPath.positions()), position);
    if (it != std::end(rhsPath.positions()))
        return true;

    it = std::find(std::begin(lhsPath.positions()), std::end(lhsPath.positions()), position);
    if (it != std::end(lhsPath.positions()))
        return true;
    return false;
}

Path InternalUtils::concatenatePaths(const Path& rhsPath, const Path& lhsPath)
{
    Path resultPath;
    for (const Position& position: rhsPath.positions())
        resultPath.push_back(position);
    for (const Position& position: lhsPath.positions())
        resultPath.push_back(position);

    return resultPath;
}

