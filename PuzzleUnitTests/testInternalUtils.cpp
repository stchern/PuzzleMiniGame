#include "src/InternalUtils.h"
#include "testInternalUtils.h"

using namespace InternalUtils;

void TestInternalUtils::testIsFoundInRow01()
{
    std::vector<unsigned char> values{10, 20, 25, 255, 3, 3, 21, 3, 4, 5};
    Matrix matrix(std::vector<std::vector<unsigned char>>{values});
    std::vector<Position> positions;
    isFoundInRow(matrix, Position(0, -1), 3, positions);
    std::vector<Position> ansPositions{Position(0, 4), Position(0, 5), Position(0, 7)};

    QVERIFY(isEqualsVector(positions, ansPositions));
}

void TestInternalUtils::testIsFoundInRow02()
{
    std::vector<unsigned char> values{10, 20, 25, 255, 3, 3, 21, 3, 4, 5};
    Matrix matrix(std::vector<std::vector<unsigned char>>{values});
    std::vector<Position> positions;
    isFoundInRow(matrix, Position(0, -1), 3, positions);
    std::vector<Position> ansPositions{Position(0, 4), Position(0, 5), Position(0, 7)};

    QVERIFY(isEqualsVector(positions, ansPositions));
}


void TestInternalUtils::testIsFoundInRow03()
{
    const std::vector<std::vector<unsigned char>> values{{10, 20, 25, 25}, {5, 3, 3, 2}, {1, 3, 4, 5}};
    Matrix matrix(values);
    int row = 1;

    std::vector<Position> positions;
    isFoundInRow(matrix, Position(row, -1), 3, positions);
    std::vector<Position> ansPositions{Position(row, 1), Position(row, 2)};

    QVERIFY(isEqualsVector(positions, ansPositions));
}

void TestInternalUtils::testIsFoundInRow04()
{
    const std::vector<std::vector<unsigned char>> values{{10, 20, 25, 25}, {5, 3, 3, 2}, {1, 3, 4, 5}};
    Matrix matrix(values);
    int row = 2;
    std::vector<Position> positions;
    isFoundInRow(matrix, Position(row, -1), 5, positions);
    std::vector<Position> ansPositions{Position(row, 3)};

    QVERIFY(isEqualsVector(positions, ansPositions));
}


void TestInternalUtils::testDFSForMatrix01()

{
    int maxLengthPath = 10;
    const std::vector<std::vector<unsigned char>> values{{10, 20, 25, 25}, {5, 3, 3, 2}, {1, 3, 4, 5}};
    Matrix matrix(values);
    const Sequence sequence({20, 3, 1, 5}, 10);
    const Position startPosition(0, 1);
    std::vector<Path> possiblePath = DFS(matrix, sequence, startPosition, maxLengthPath);
    std::vector<Path> ansPossiblePath{Path(std::vector<Position>{Position(0, 1), Position(2, 1), Position(2, 0), Position( 1, 0)})};

    QVERIFY(isEqualsVector(possiblePath, ansPossiblePath));
}

void TestInternalUtils::testDFSForMatrix02()
{
    int maxLengthPath = 10;
    const std::vector<std::vector<unsigned char>> values{{10, 20, 25, 25}, {5, 4, 3, 2}, {1, 3, 4, 5}};
    Matrix matrix(values);
    const Sequence sequence({3, 4, 5, 25}, 10);
    const Position startPosition(1, 2);
    std::vector<Path> possiblePath = DFS(matrix, sequence, startPosition, maxLengthPath);
    std::vector<Path> ansPossiblePath{Path(std::vector<Position>{Position(1, 2), Position(2, 2), Position(2, 3), Position( 0, 3)})};

    QVERIFY(isEqualsVector(possiblePath, ansPossiblePath));
}

void TestInternalUtils::testDFSForMatrix03()
{
    int maxLengthPath = 10;
    const std::vector<std::vector<unsigned char>> values{{2, 5, 5}, {4, 3, 2}};
    Matrix matrix(values);
    const Sequence sequence({5, 5}, 10);
    const Position startPosition(0, 1);
    std::vector<Path> possiblePath = DFS(matrix, sequence, startPosition, maxLengthPath);
    std::vector<Path> ansPossiblePath{Path(std::vector<Position>{Position(0, 1), Position(0, 2)})};

    QVERIFY(isEqualsVector(possiblePath, ansPossiblePath));
}


void TestInternalUtils::testDFSForMatrix04()
{
    int maxLengthPath = 10;
    const std::vector<std::vector<unsigned char>> values{{10, 20, 25, 25}, {5, 4, 3, 2}, {1, 3, 4, 5}};
    Matrix matrix(values);
    const Sequence sequence({4}, 10);
    const Position startPosition(1, 1);
    std::vector<Path> possiblePath = DFS(matrix, sequence, startPosition, maxLengthPath);
    std::vector<Path> ansPossiblePath{Path(std::vector<Position>{Position(1, 1)})};

    QVERIFY(isEqualsVector(possiblePath, ansPossiblePath));
}

void TestInternalUtils::testDFSForMatrix05()
{
    int maxLengthPath = 10;
    const std::vector<std::vector<unsigned char>> values{{10, 20, 25, 25}, {5, 2, 3, 2}, {1, 5, 4, 5}};
    Matrix matrix(values);
    const Sequence sequence({3, 2, 5, 1}, 10);
    const Position startPosition(1, 2);
    std::vector<Path> possiblePath = DFS(matrix, sequence, startPosition, maxLengthPath);
    std::vector<Path> ansPossiblePath{
        Path(std::vector<Position>{Position(1, 2), Position(1, 3), Position(2, 3), Position(2, 0)}),
                Path(std::vector<Position>{Position(1, 2), Position(1, 1), Position(2, 1), Position(2, 0)})
    };

    QVERIFY(isEqualsVector(possiblePath, ansPossiblePath));
}

void TestInternalUtils::testDFSForMatrix06()
{
    int maxLengthPath = 10;
    const std::vector<std::vector<unsigned char>> values{{10, 20, 25, 25}, {5, 2, 3, 2}, {1, 5, 4, 5}};
    Matrix matrix(values);
    const Sequence sequence({3, 2, 5, 1, 4}, 10);
    const Position startPosition(1, 2);
    std::vector<Path> possiblePath = DFS(matrix, sequence, startPosition, maxLengthPath);

    QVERIFY(possiblePath.empty());
}

void TestInternalUtils::testDFSForMatrix07()
{
    int maxLengthPath = 10;
    const std::vector<std::vector<unsigned char>> values{{10, 20, 25, 25}, {5, 2, 3, 2}, {1, 5, 4, 5}};
    Matrix matrix(values);
    const Sequence sequence({3, 10}, 10);
    const Position startPosition(1, 2);
    std::vector<Path> possiblePath = DFS(matrix, sequence, startPosition, maxLengthPath);

    QVERIFY(possiblePath.empty());
}

void TestInternalUtils::testDFSForMatrix08()
{
    int maxLengthPath = 3;
    const std::vector<std::vector<unsigned char>> values{{10, 20, 25, 25}, {5, 4, 3, 2}, {1, 3, 4, 5}};
    Matrix matrix(values);
    const Sequence sequence({3, 4, 5, 25}, 10);
    const Position startPosition(1, 2);
    std::vector<Path> possiblePath = DFS(matrix, sequence, startPosition, maxLengthPath);
    std::vector<Path> ansPossiblePath{Path(std::vector<Position>{Position(1, 2), Position(2, 2), Position(2, 3), Position( 0, 3)})};

    QVERIFY(possiblePath.empty());
}

void TestInternalUtils::testDFSForMatrix09()
{
    int maxLengthPath = 10;
    const std::vector<std::vector<unsigned char>> values{{1, 20, 1}, {20, 6, 20}, {1, 20, 1}};
    Matrix matrix(values);
    const Sequence sequence({6, 20, 1}, 10);
    const Position startPosition(1, 1);
    std::vector<Path> possiblePath = DFS(matrix, sequence, startPosition, maxLengthPath);
    std::vector<Path> ansPossiblePath{
        Path(std::vector<Position>{Position(1, 1), Position(2, 1), Position(2, 2)}),
                Path(std::vector<Position>{Position(1, 1), Position(2, 1), Position(2, 0)}),
                Path(std::vector<Position>{Position(1, 1), Position(0, 1), Position(0, 2)}),
                Path(std::vector<Position>{Position(1, 1), Position(0, 1), Position(0, 0)}),
                Path(std::vector<Position>{Position(1, 1), Position(1, 2), Position(2, 2)}),
                Path(std::vector<Position>{Position(1, 1), Position(1, 2), Position(0, 2)}),
                Path(std::vector<Position>{Position(1, 1), Position(1, 0), Position(2, 0)}),
                Path(std::vector<Position>{Position(1, 1), Position(1, 0), Position(0, 0)})
    };

    QVERIFY(isEqualsVector(possiblePath, ansPossiblePath));
}


void TestInternalUtils::testBFSForMatrix01()
{
    const std::vector<std::vector<unsigned char>> values{{10, 20, 25, 25}, {5, 2, 3, 2}, {1, 5, 4, 5}};
    Matrix matrix(values);
    const Position endPositionCurrSeq(0, 2);
    const Position startPositionNextSeq(2, 3);
    bool isStartFromCol = true;
    std::vector<Path> possiblePath = BFS(matrix, endPositionCurrSeq, startPositionNextSeq, true, isStartFromCol);
    std::vector<Path> ansPossiblePath{
        Path(std::vector<Position>{Position(2, 2)})
    };

    QVERIFY(isEqualsVector(possiblePath, ansPossiblePath));
}


void TestInternalUtils::testBFSForMatrix02()
{
    const std::vector<std::vector<unsigned char>> values{{10, 20, 25, 25}, {5, 3, 3, 2}, {1, 3, 4, 5}};
    Matrix matrix(values);
    const Position endPositionCurrSeq(1, 0);
    const Position startPositionNextSeq(0, 3);
    bool isStartFromCol = false;
    bool isNextSeqStartByCol = true;
    std::vector<Path> possiblePath = BFS(matrix, endPositionCurrSeq, startPositionNextSeq, isNextSeqStartByCol, isStartFromCol);
    std::vector<Path> ansPossiblePath{
        Path(std::vector<Position>{Position(1, 1), Position(0, 1)}),
                Path(std::vector<Position>{Position(1, 2), Position(0, 2)})
    };

    QVERIFY(isEqualsVector(possiblePath, ansPossiblePath));
}

void TestInternalUtils::testBFSForMatrix03()
{
    const std::vector<std::vector<unsigned char>> values{{10, 20, 25, 25}, {5, 2, 3, 2}, {1, 5, 4, 5}};
    Matrix matrix(values);
    const Position endPositionCurrSeq(0, 1);
    const Position startPositionNextSeq(2, 1);
    bool isStartFromCol = true;
    bool isNextSeqStartByCol = true;
    std::vector<Path> possiblePath = BFS(matrix, endPositionCurrSeq, startPositionNextSeq, isNextSeqStartByCol, isStartFromCol);

    QVERIFY(possiblePath.empty());
}

void TestInternalUtils::testBFSForMatrix04()
{
    const std::vector<std::vector<unsigned char>> values{{10, 20, 25, 25}, {5, 3, 3, 2}, {1, 3, 4, 5}};
    Matrix matrix(values);
    const Position endPositionCurrSeq(1, 0);
    const Position startPositionNextSeq(0, 3);
    bool isStartFromCol = true;
    bool isNextSeqStartByCol = false;
    std::vector<Path> possiblePath = BFS(matrix, endPositionCurrSeq, startPositionNextSeq, isNextSeqStartByCol, isStartFromCol);
    std::vector<Path> ansPossiblePath{
        Path(std::vector<Position>{Position(2, 0), Position(2, 3)})
    };

    QVERIFY(isEqualsVector(possiblePath, ansPossiblePath));
}

void TestInternalUtils::testBFSForMatrix05()
{
    const std::vector<std::vector<unsigned char>> values{{10, 20, 25, 25}, {5, 3, 3, 2}, {1, 3, 4, 5}};
    Matrix matrix(values);
    const Position endPositionCurrSeq(1, 0);
    const Position startPositionNextSeq(0, 3);
    bool isStartFromCol = false;
    bool isNextSeqStartByCol = false;
    std::vector<Path> possiblePath = BFS(matrix, endPositionCurrSeq, startPositionNextSeq, isNextSeqStartByCol, isStartFromCol);
    std::vector<Path> ansPossiblePath{
        Path(std::vector<Position>{Position(1, 3)})
    };

    QVERIFY(isEqualsVector(possiblePath, ansPossiblePath));
}

void TestInternalUtils::testBFSForMatrix06()
{
    const std::vector<std::vector<unsigned char>> values{ {10, 20, 25, 25} ,{10, 20, 25, 25}, {5, 3, 3, 2}, {1, 3, 4, 5}};
    Matrix matrix(values);
    const Position endPositionCurrSeq(2, 0);
    const Position startPositionNextSeq(1, 3);
    bool isStartFromCol = true;
    bool isNextSeqStartByCol = false;
    std::vector<Path> possiblePath = BFS(matrix, endPositionCurrSeq, startPositionNextSeq, isNextSeqStartByCol, isStartFromCol);
    std::vector<Path> ansPossiblePath{
        Path(std::vector<Position>{Position(0, 0), Position(0, 3)}),
                Path(std::vector<Position>{Position(3, 0), Position(3, 3)})
    };

    QVERIFY(isEqualsVector(possiblePath, ansPossiblePath));
}


void TestInternalUtils::testBFSForMatrix07()
{
    const std::vector<std::vector<unsigned char>> values{{0, 10, 20, 25, 25}, {0, 5, 3, 3, 2}, {0, 1, 3, 4, 5}};
    Matrix matrix(values);
    const Position endPositionCurrSeq(1, 1);
    const Position startPositionNextSeq(0, 4);
    bool isStartFromCol = false;
    bool isNextSeqStartByCol = true;
    std::vector<Path> possiblePath = BFS(matrix, endPositionCurrSeq, startPositionNextSeq, isNextSeqStartByCol, isStartFromCol);
    std::vector<Path> ansPossiblePath{
        Path(std::vector<Position>{Position(1, 0), Position(0, 0)}),
                Path(std::vector<Position>{Position(1, 2), Position(0, 2)}),
                Path(std::vector<Position>{Position(1, 3), Position(0, 3)})
    };

    QVERIFY(isEqualsVector(possiblePath, ansPossiblePath));
}

