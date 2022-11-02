#include "src/Utils.h"
#include "testUtils.h"


void TestUtils::testAdjacencyMatrix01()
{
    const std::vector<std::vector<unsigned char>> values{{10, 20, 25, 25}, {5, 3, 3, 2}, {1, 3, 4, 5}};
    Matrix matrix(values);
    const std::vector<Sequence> sequences{Sequence({20, 3, 1, 5}, 10), Sequence({3, 2}, 10), Sequence({ 25, 4, 3, 20}, 5)};

    std::vector<std::vector<Position>> positions = Utils::adjacencyMatrix(matrix, sequences);
    std::vector<std::vector<Position>> ansPositions{{Position(0, 1)}, {Position(1, 1), Position(1, 2), Position(2, 1)}, {Position(0, 2), Position(0, 3)}};

    QVERIFY(isEqualsVectorOfVector(positions, ansPositions));

}

void TestUtils::testAdjacencyMatrix02()
{
    const std::vector<std::vector<unsigned char>> values{{10, 20, 25, 25}, {5, 4, 6, 3}, {1, 3, 5, 1}};
    Matrix matrix(values);
    const std::vector<Sequence> sequences{Sequence({20, 3, 1, 5}, 10), Sequence({3, 1, 5, 6}, 10), Sequence({1, 3}, 5)};

    std::vector<std::vector<Position>> positions = Utils::adjacencyMatrix(matrix, sequences);
    std::vector<std::vector<Position>> ansPositions{{Position(0, 1)}, {Position(1, 3), Position(2, 1)}, {Position(2, 0), Position(2, 3)}};

    QVERIFY(isEqualsVectorOfVector(positions, ansPositions));
}

void TestUtils::testAdjacencyMatrix03()
{
    const std::vector<std::vector<unsigned char>> values{{10, 20, 25, 25}, {5, 3, 3, 2}, {1, 3, 4, 5}};
    Matrix matrix(values);
    const std::vector<Sequence> sequences{ Sequence({30, 20, 25}, 10), Sequence({11, 2}, 10), Sequence({ 26, 4, 3, 20}, 5)};

    std::vector<std::vector<Position>> positions = Utils::adjacencyMatrix(matrix, sequences);
    std::vector<std::vector<Position>> ansPositions{{}, {}, {}};

   QVERIFY(isEqualsVectorOfVector(positions, ansPositions));
}


void TestUtils::testfindAllPurePaths()
{
    size_t maxLengthPath = 10;
    const std::vector<std::vector<unsigned char>> values{{10, 20, 25, 25}, {5, 4, 6, 3}, {1, 3, 5, 1}};
    Matrix matrix(values);
    const std::vector<Sequence> sequences({Sequence({20, 3, 1, 5}, 10), Sequence({3, 1, 5, 6}, 10), Sequence({25}, 1), Sequence({3, 1}, 5), Sequence({40, 1}, 5)});
    const std::vector<std::vector<Position>> adjacencyMatrix{
        {Position(0, 1)},
        {Position(1, 3), Position(2, 1)},
        {Position(0, 2), Position(0, 3)},
        {Position(1, 3), Position(2, 1)},
        {}
    };

    std::vector<std::vector<Path>> purePaths = Utils::findAllPurePaths(matrix, sequences, adjacencyMatrix, maxLengthPath);
    std::vector<std::vector<Path>> ansPurePaths{
        {Path(std::vector<Position>{Position(0, 1), Position(2, 1), Position(2, 0), Position( 1, 0)})},
        {
             Path(std::vector<Position>{Position(1, 3), Position(2, 3), Position(2, 2), Position( 1, 2)}),
             Path(std::vector<Position>{Position(2, 1), Position(2, 0), Position(1, 0), Position( 1, 2)})
        },
        {

            Path(std::vector<Position>{Position(0, 2)}),
            Path(std::vector<Position>{Position(0, 3)})

        },
        {
            Path(std::vector<Position>{Position(1, 3), Position(2, 3)}),
            Path(std::vector<Position>{Position(2, 1), Position(2, 3)}),
            Path(std::vector<Position>{Position(2, 1), Position(2, 0)})
        },
        {}
    };

    QVERIFY(isEqualsVectorOfVector(purePaths, ansPurePaths));
}
