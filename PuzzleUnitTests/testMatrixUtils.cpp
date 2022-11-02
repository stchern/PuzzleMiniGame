#include "src/InternalUtils.h"
#include "testMatrixUtils.h"
#include "utils.h"


using namespace InternalUtils::UMatrix;
using namespace UtilsUnitTests;

void TestMatrixUtils::testIsFoundInRow01()
{
    const std::vector<unsigned char> values{10, 20, 25, 255, 3, 3, 21, 3, 4, 5};
    const Matrix matrix(std::vector<std::vector<unsigned char>>{values});
    std::vector<Position> positions;
    isFoundInRow(matrix, Position(0, -1), 3, positions);
    const std::vector<Position> ansPositions{Position(0, 4), Position(0, 5), Position(0, 7)};

    QVERIFY(isEqualsVector(positions, ansPositions));
}

void TestMatrixUtils::testIsFoundInRow02()
{
    const std::vector<unsigned char> values{10, 20, 25, 255, 3, 3, 21, 3, 4, 5};
    const Matrix matrix(std::vector<std::vector<unsigned char>>{values});
    std::vector<Position> positions;
    isFoundInRow(matrix, Position(0, -1), 3, positions);
    const std::vector<Position> ansPositions{Position(0, 4), Position(0, 5), Position(0, 7)};

    QVERIFY(isEqualsVector(positions, ansPositions));
}


void TestMatrixUtils::testIsFoundInRow03()
{
    const std::vector<std::vector<unsigned char>> values{{10, 20, 25, 25}, {5, 3, 3, 2}, {1, 3, 4, 5}};
    const Matrix matrix(values);
    const int row = 1;

    std::vector<Position> positions;
    isFoundInRow(matrix, Position(row, -1), 3, positions);
    const std::vector<Position> ansPositions{Position(row, 1), Position(row, 2)};

    QVERIFY(isEqualsVector(positions, ansPositions));
}

void TestMatrixUtils::testIsFoundInRow04()
{
    const std::vector<std::vector<unsigned char>> values{{10, 20, 25, 25}, {5, 3, 3, 2}, {1, 3, 4, 5}};
    const Matrix matrix(values);
    const int row = 2;
    std::vector<Position> positions;
    isFoundInRow(matrix, Position(row, -1), 5, positions);
    const std::vector<Position> ansPositions{Position(row, 3)};

    QVERIFY(isEqualsVector(positions, ansPositions));
}

void TestMatrixUtils::testIsFoundInRow05()
{
    const std::vector<std::vector<unsigned char>> values{{10, 20, 25, 25}, {5, 3, 3, 2}, {1, 3, 4, 5}};
    const Matrix matrix(values);
    const int row = 2;
    std::vector<Position> positions;
    bool returnValue = isFoundInRow(matrix, Position(row, -1), 6, positions);

    QVERIFY(!returnValue);
}


void TestMatrixUtils::testIsFoundInCol01()
{
    const std::vector<std::vector<unsigned char>> values{{10, 20, 25, 25}, {5, 3, 3, 2}, {1, 3, 4, 5}};
    const Matrix matrix(values);
    const int col = 2;
    std::vector<Position> positions;
    unsigned char value = 3;
    isFoundInCol(matrix, Position(-1, col), value, positions);
    const std::vector<Position> ansPositions{Position(1, col)};

    QVERIFY(isEqualsVector(positions, ansPositions));
}

void TestMatrixUtils::testIsFoundInCol02()
{
    const std::vector<std::vector<unsigned char>> values{{10, 20, 25, 25}, {5, 3, 3, 2}, {1, 3, 4, 5}};
    const Matrix matrix(values);
    const int col = 0;
    std::vector<Position> positions;
    unsigned char value = 10;
    isFoundInCol(matrix, Position(-1, col), value, positions);
    const std::vector<Position> ansPositions{Position(0, col)};

    QVERIFY(isEqualsVector(positions, ansPositions));
}

void TestMatrixUtils::testIsFoundInCol03()
{
    const std::vector<std::vector<unsigned char>> values{{10, 20, 25, 25}, {5, 3, 3, 2}, {1, 3, 4, 5}};
    const Matrix matrix(values);
    const int col = 0;
    std::vector<Position> positions;
    const unsigned char value = 11;
    const bool returnValue = isFoundInCol(matrix, Position(-1, col), value, positions);

    QVERIFY(!returnValue);
}


void TestMatrixUtils::testCreateIsVisitedMatrix01()
{
    const int row = 2;
    const int col = 2;
    const Position startPosition(0, 1);
    const Matrix matrix = createIsVisitedMatrix(row, col, startPosition);
    const std::vector<std::vector<unsigned char>> values(row , std::vector<unsigned char>(col, 0));
    Matrix ansMatrix(values);
    ansMatrix.setValue(startPosition, 1);

    QVERIFY(matrix == ansMatrix);
}

void TestMatrixUtils::testSetVisitedPositions01()
{
    const int row = 2;
    const int col = 4;
    const Position startPosition(0, 1);
    Matrix matrix = createIsVisitedMatrix(row, col, startPosition);
    const Path path(std::vector<Position>({Position(0, 2), Position(0, 3)}));
    setVisitedPositions(matrix, path);
    const std::vector<std::vector<unsigned char>> values(row , std::vector<unsigned char>(col, 0));
    Matrix ansMatrix(values);
    ansMatrix.setValue(startPosition, 1);
    ansMatrix.setValue(Position(0, 2), 1);
    ansMatrix.setValue(Position(0, 3), 1);

    QVERIFY(matrix == ansMatrix);
}

