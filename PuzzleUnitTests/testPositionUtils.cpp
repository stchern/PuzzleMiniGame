#include "testPositionUtils.h"
#include "src/PositionUtils.h"

using namespace InternalUtils::UPosition;

void TestPositionUtils::testIsPositionInPath01()
{
    const std::vector<Position> pathPositions{
        Position(0, 1), Position(2, 1), Position(2, 0), Position(1, 0),
                      Position(1, 2), Position(2, 2), Position(2, 3), Position(0, 3)
        };
    const Position position(2, 1);
    bool value = isPositionInPath(pathPositions, position);

    QVERIFY(value);
}


void TestPositionUtils::testIsPositionInPath02()
{
    const std::vector<Position> pathPositions{
        Position(0, 1), Position(2, 1), Position(2, 0), Position(1, 0),
                      Position(1, 2), Position(2, 2), Position(2, 3), Position(0, 3)
        };
    const Position position(3, 1);
    bool value = isPositionInPath(pathPositions, position);

    QVERIFY(!value);
}


void TestPositionUtils::testIsFoundNextPositionsInColsAndRowsByPosition01()
{
    const std::vector<std::vector<unsigned char>> values{{10, 20, 25, 25}, {5, 3, 3, 2}, {1, 3, 4, 5}};
    Matrix matrix(values);

    const Position startPosition(0, 1);
    const std::pair<Position, Path> startPositionAndPath(startPosition, Path({startPosition}));
    const Position positionToFound(0, 3);
    std::queue<std::pair<Position, Path>> queue;
    bool isStartFromCol = true;

    nextPositionsInColsOrRows(matrix, startPositionAndPath, positionToFound, queue, isStartFromCol);
    std::queue<std::pair<Position, Path>> ansQueue;
    ansQueue.push(std::make_pair(Position(1, 1), Path({startPosition, Position(1, 1)})));
    ansQueue.push(std::make_pair(Position(2, 1), Path({startPosition, Position(2, 1)})));

    QVERIFY(queue == ansQueue);
}

void TestPositionUtils::testIsFoundNextPositionsInColsAndRowsByPosition02()
{
    const std::vector<std::vector<unsigned char>> values{{10, 20, 25, 25}, {5, 3, 3, 2}, {1, 3, 4, 5}};
    Matrix matrix(values);

    const Position startPosition(0, 1);
    const std::pair<Position, Path> startPositionAndPath(startPosition, Path({startPosition}));
    const Position positionToFound(0, 3);
    std::queue<std::pair<Position, Path>> queue;
    bool isStartFromCol = false;

    nextPositionsInColsOrRows(matrix, startPositionAndPath, positionToFound, queue, isStartFromCol);
    std::queue<std::pair<Position, Path>> ansQueue;
    ansQueue.push(std::make_pair(Position(0, 3), Path({startPosition, Position(0, 3)})));

    QVERIFY(queue == ansQueue);

}

void TestPositionUtils::testIsFoundNextPositionsInColsAndRowsByPosition03()
{
    const std::vector<std::vector<unsigned char>> values{{10, 20, 25, 25}, {5, 3, 3, 2}, {1, 3, 4, 5}};
    Matrix matrix(values);

    const Position startPosition(0, 1);
    const std::pair<Position, Path> startPositionAndPath(startPosition, Path({startPosition}));
    const Position positionToFound(1, 3);
    std::queue<std::pair<Position, Path>> queue;
    bool isStartFromCol = false;

    nextPositionsInColsOrRows(matrix, startPositionAndPath, positionToFound, queue, isStartFromCol);
    std::queue<std::pair<Position, Path>> ansQueue;
    ansQueue.push(std::make_pair(Position(0, 0), Path({startPosition, Position(0, 0)})));
    ansQueue.push(std::make_pair(Position(0, 2), Path({startPosition, Position(0, 2)})));
    ansQueue.push(std::make_pair(Position(0, 3), Path({startPosition, Position(0, 3)})));

    QVERIFY(queue == ansQueue);
}

void TestPositionUtils::testIsFoundNextPositionsInColsAndRowsByPosition04()
{
    const std::vector<std::vector<unsigned char>> values{{10, 20, 25, 25}, {5, 3, 3, 2}, {1, 3, 4, 5}};
    Matrix matrix(values);

    const Position startPosition(0, 1);
    const std::pair<Position, Path> startPositionAndPath(startPosition, Path({startPosition}));
    const Position positionToFound(1, 1);
    std::queue<std::pair<Position, Path>> queue;
    bool isStartFromCol = true;

    nextPositionsInColsOrRows(matrix, startPositionAndPath, positionToFound, queue, isStartFromCol);
    std::queue<std::pair<Position, Path>> ansQueue;
    ansQueue.push(std::make_pair(Position(1, 1), Path({startPosition, Position(1, 1)})));

    QVERIFY(queue == ansQueue);
}

void TestPositionUtils::testIsFoundNextPositionsInColsAndRowsByValue01()
{
    const std::vector<std::vector<unsigned char>> values{{10, 20, 25, 25}, {5, 3, 3, 2}, {1, 3, 4, 5}};
    Matrix matrix(values);

    const Position startPosition(0, 1);
    const std::pair<Position, Path> startPositionAndPath(startPosition, Path({startPosition}));
    unsigned char value = 25;
    std::stack<std::pair<Position, Path>> stack;
    bool isStartFromCol = true;

    bool returnedValue = isFoundNextPositionsInColsAndRowsByValue(matrix, startPositionAndPath, value, stack, isStartFromCol);
    std::stack<std::pair<Position, Path>> ansStack;


    QVERIFY(!returnedValue);
    QVERIFY(stack.empty());
}

void TestPositionUtils::testIsFoundNextPositionsInColsAndRowsByValue02()
{
    const std::vector<std::vector<unsigned char>> values{{10, 20, 25, 25}, {5, 3, 3, 2}, {1, 3, 4, 5}};
    Matrix matrix(values);

    const Position startPosition(0, 1);
    const std::pair<Position, Path> startPositionAndPath(startPosition, Path({startPosition}));
    unsigned char value = 3;
    std::stack<std::pair<Position, Path>> stack;
    bool isStartFromCol = true;

    bool returnedValue = isFoundNextPositionsInColsAndRowsByValue(matrix, startPositionAndPath, value, stack, isStartFromCol);
    std::stack<std::pair<Position, Path>> ansStack;
    ansStack.push(std::make_pair(Position(1, 1), Path({startPosition, Position(1, 1)})));
    ansStack.push(std::make_pair(Position(2, 1), Path({startPosition, Position(2, 1)})));

    QVERIFY(returnedValue);
    QVERIFY(stack == ansStack);
}

void TestPositionUtils::testIsFoundNextPositionsInColsAndRowsByValue03()
{
    const std::vector<std::vector<unsigned char>> values{{10, 20, 25, 25}, {5, 3, 3, 2}, {1, 3, 4, 5}};
    Matrix matrix(values);

    const Position startPosition(0, 1);
    const std::pair<Position, Path> startPositionAndPath(startPosition, Path({startPosition}));
    unsigned char value = 25;
    std::stack<std::pair<Position, Path>> stack;
    bool isStartFromCol = false;

    bool returnedValue = isFoundNextPositionsInColsAndRowsByValue(matrix, startPositionAndPath, value, stack, isStartFromCol);
    std::stack<std::pair<Position, Path>> ansStack;
    ansStack.push(std::make_pair(Position(0, 2), Path({startPosition, Position(0, 2)})));
    ansStack.push(std::make_pair(Position(0, 3), Path({startPosition, Position(0, 3)})));

    QVERIFY(returnedValue);
    QVERIFY(stack == ansStack);
}

void TestPositionUtils::testIsFoundNextPositionsInColsAndRowsByValue04()
{
    const std::vector<std::vector<unsigned char>> values{{10, 20, 25, 25}, {5, 3, 3, 2}, {1, 3, 4, 5}};
    Matrix matrix(values);

    const Position startPosition(0, 1);
    const std::pair<Position, Path> startPositionAndPath(startPosition, Path({startPosition}));
    unsigned char value = 26;
    std::stack<std::pair<Position, Path>> stack;
    bool isStartFromCol = false;

    bool returnedValue = isFoundNextPositionsInColsAndRowsByValue(matrix, startPositionAndPath, value, stack, isStartFromCol);

    QVERIFY(!returnedValue);
    QVERIFY(stack.empty());
}

void TestPositionUtils::testIsFoundTwoPositionsForWastedMoves01()
{
    const std::vector<Position> pathPositions{
         Position(2, 0), Position(1, 0),
                      Position(1, 2), Position(2, 2), Position(2, 3), Position(0, 3)
        };
    const Position position(2, 0);
    const int maxColumnCount = 4;
    Path outPathOfTwoPositions;
    bool value = isFoundTwoPositionsForWastedMoves(pathPositions, position, maxColumnCount, outPathOfTwoPositions);

    const std::vector<Position> ansPathPositions{
         Position(0, 1), Position(2, 1)
        };
    QVERIFY(value);
    QVERIFY(outPathOfTwoPositions == ansPathPositions);
}


void TestPositionUtils::testIsFoundTwoPositionsForWastedMoves02()
{
    const std::vector<Position> pathPositions{
         Position(1, 0), Position(2, 0),
                       Position(2, 2),  Position(1, 2), Position(1, 3), Position(0, 3), Position(0, 1)
        };
    const Position position(2, 0);
    const int maxColumnCount = 4;
    Path outPathOfTwoPositions;
    bool value = isFoundTwoPositionsForWastedMoves(pathPositions, position, maxColumnCount, outPathOfTwoPositions);

    QVERIFY(!value);
    QVERIFY(outPathOfTwoPositions.positions().empty());
}


