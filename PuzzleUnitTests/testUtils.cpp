#include "src/Utils.h"
#include "testUtils.h"
#include "utils.h"

using namespace UtilsUnitTests;

void TestUtils::testAdjacencyMatrix01()
{
    const std::vector<std::vector<unsigned char>> values{{10, 20, 25, 25}, {5, 3, 3, 2}, {1, 3, 4, 5}};
    Matrix matrix(values);
    const std::vector<Sequence> sequences{Sequence({20, 3, 1, 5}, 10), Sequence({3, 2}, 10), Sequence({ 25, 4, 3, 20}, 5)};

    std::vector<std::vector<Position>> positions = Utils::adjacencyMatrix(matrix, sequences);
    std::vector<std::vector<Position>> ansPositions{{{0, 1}}, {{1, 1}, {1, 2}, {2, 1}}, {{0, 2}, {0, 3}}};

    QVERIFY(isEqualsVectorOfVector(positions, ansPositions));

}

void TestUtils::testAdjacencyMatrix02()
{
    const std::vector<std::vector<unsigned char>> values{{10, 20, 25, 25}, {5, 4, 6, 3}, {1, 3, 5, 1}};
    Matrix matrix(values);
    const std::vector<Sequence> sequences{Sequence({20, 3, 1, 5}, 10), Sequence({3, 1, 5, 6}, 10), Sequence({1, 3}, 5)};

    std::vector<std::vector<Position>> positions = Utils::adjacencyMatrix(matrix, sequences);
    std::vector<std::vector<Position>> ansPositions{{{0, 1}}, {{1, 3}, {2, 1}}, {{2, 0}, {2, 3}}};

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


void TestUtils::testfindAllPurePaths01()
{
    size_t maxLengthPath = 10;
    const std::vector<std::vector<unsigned char>> values{{10, 20, 25, 25}, {5, 4, 6, 3}, {1, 3, 5, 1}};
    Matrix matrix(values);
    const std::vector<Sequence> sequences({Sequence({20, 3, 1, 5}, 10), Sequence({3, 1, 5, 6}, 10), Sequence({25}, 1), Sequence({3, 1}, 5), Sequence({40, 1}, 5)});
    const std::vector<std::vector<Position>> adjacencyMatrix{
        {{0, 1}},
        {{1, 3}, {2, 1}},
        {{0, 2}, {0, 3}},
        {{1, 3}, {2, 1}},
        {}
    };

    std::vector<std::vector<Path>> purePaths = Utils::findAllPurePaths(matrix, sequences, adjacencyMatrix, maxLengthPath);
    std::vector<std::vector<Path>> ansPurePaths{
        {Path(std::vector<Position>{{0, 1}, {2, 1}, {2, 0}, {1, 0}})},
        {
             Path({{1, 3}, {2, 3}, {2, 2}, {1, 2}}),
            Path({{2, 1}, {2, 0}, {1, 0}, {1, 2}})
        },
        {
            Path({{0, 2}}),
            Path({{0, 3}})
        },
        {
            Path({{1, 3}, {2, 3}}),
            Path({{2, 1}, {2, 3}}),
            Path({{2, 1}, {2, 0}})
        },
        {}
    };

    QVERIFY(isEqualsVectorOfVector(purePaths, ansPurePaths));
}


void TestUtils::testfindAllPurePaths02()
{
    size_t maxLengthPath = 3;
    const std::vector<std::vector<unsigned char>> values{{10, 20, 25, 25}, {5, 4, 6, 3}, {1, 3, 5, 1}};
    Matrix matrix(values);
    const std::vector<Sequence> sequences({Sequence({20, 3, 1, 5}, 10), Sequence({3, 1, 5, 6}, 10), Sequence({25}, 1), Sequence({3, 1}, 5), Sequence({40, 1}, 5)});
    const std::vector<std::vector<Position>> adjacencyMatrix{
        {{0, 1}},
        {{1, 3}, {2, 1}},
        {{0, 2}, {0, 3}},
        {{1, 3}, {2, 1}},
        {}
    };

    std::vector<std::vector<Path>> purePaths = Utils::findAllPurePaths(matrix, sequences, adjacencyMatrix, maxLengthPath);
    std::vector<std::vector<Path>> ansPurePaths{
        {},
        {},
        {
            Path({{0, 2}}),
            Path({{0, 3}})

        },
        {
            Path({{1, 3}, {2, 3}}),
            Path({{2, 1}, {2, 3}}),
            Path({{2, 1}, {2, 0}})
        },
        {}
    };

    QVERIFY(isEqualsVectorOfVector(purePaths, ansPurePaths));
}

void TestUtils::testfindAllPurePaths03()
{
    const Matrix matrix =
    {{
        {0x3A, 0x3A, 0x10, 0x9B, 0x72},
        {0x9B, 0x72, 0x3A, 0x10, 0x72},
        {0x10, 0x4A, 0x4A, 0x4A, 0x10},
        {0x4A, 0x10, 0x4A, 0x9B, 0x72},
        {0x10, 0x10, 0x4A, 0x72, 0x72}
    }};

    const std::vector<Sequence> sequences =
    {
        Sequence({0x3A, 0x10, 0x9B}, 10)
    };

    const int maxPathLength = 3;

    const Path expectedSolution = {{{0, 1}, {3, 1}, {3, 3}}};
    const std::vector<std::vector<Position>> adjacencyMatrix{
        {Position(0, 0), Position(0, 1), Position(1, 2)},
    };

    std::vector<std::vector<Path>> purePaths = Utils::findAllPurePaths(matrix, sequences, adjacencyMatrix, maxPathLength);
    std::vector<std::vector<Path>> ansPurePaths{
        {Path({{0, 1}, {3, 1}, {3, 3}}),
        Path({{1, 2}, {0, 2}, {0, 3}}),
        Path({{1, 2}, {1, 3}, {3, 3}}),
        Path({{1, 2}, {1, 3}, {0, 3}})}
    };

    QVERIFY(isEqualsVectorOfVector(purePaths, ansPurePaths));
}

void TestUtils::testFindBestPath01()
{
    std::vector<std::vector<std::pair<Path, int>>> possiblePathsAndScore {
        {
            std::make_pair(Path({{0, 0}, {1, 0}, {1, 3}, {2, 3}, {2, 2}, {1, 2}}), 10),
            std::make_pair(Path({{0, 0}, {1, 0}, {1, 3}, {2, 3}, {2, 2}, {1, 2}}), 15),
            std::make_pair(Path({{0, 0}, {1, 0}, {1, 3}, {2, 3}, {2, 2}, {1, 2}, {1, 1}, {2, 1}, {2, 0} }), 15),
        },
        {
            std::make_pair(Path({{0, 1}, {2, 1}, {2, 0}, {1, 0}, {1, 2}}), 10),
            std::make_pair(Path({{0, 1}, {2, 1}, {2, 0}, {1, 0}, {1, 2}}), 15)

        },
        {
             std::make_pair(Path({{0, 0}, {1, 0}, {1, 3}, {2, 3}}), 5),
             std::make_pair(Path({{0, 0}, {1, 0}, {1, 3}, {2, 3}, {2, 2}, {1, 2}}), 15)
        },
        {
            std::make_pair(Path({{0, 1}, {2, 1}, {2, 3}}), 5),
        },
        {
            std::make_pair(Path({{0, 1}, {2, 1}, {2, 0}}), 5),
            std::make_pair(Path({{0, 1}, {2, 1}, {2, 0}, {1, 0}, {1, 3}, {2, 3}, {2, 2}, {1, 2}}), 15),
            std::make_pair(Path({{0, 1}, {2, 1}, {2, 0}, {1, 0}, {1, 2}}), 15)
        },
    };

    Path resultPath = Utils::findBestPath(possiblePathsAndScore);
    Path ansResultPath({{0, 1}, {2, 1}, {2, 0}, {1, 0}, {1, 2}});

    QVERIFY(resultPath == ansResultPath);
}

void TestUtils::testFindBestPath02()
{
    std::vector<std::vector<std::pair<Path, int>>> possiblePathsAndScore {
        {
            std::make_pair(Path({Position(0, 1), Position(2, 1), Position(2, 0), Position(1, 0)}), 10),
            std::make_pair(Path({Position(0, 1), Position(2, 1), Position(2, 0), Position(1, 0), Position(1, 3), Position(0, 3), Position(0, 2)}), 11),
            std::make_pair(Path({Position(0, 1), Position(2, 1), Position(2, 0), Position(1, 0), Position(1, 2), Position(0, 2)}), 11),
            std::make_pair(Path({Position(0, 1), Position(2, 1), Position(2, 0), Position(1, 0), Position(1, 2), Position(0, 2), Position(0, 3)}), 11),
            std::make_pair(Path({Position(0, 1), Position(2, 1), Position(2, 0), Position(1, 0), Position(1, 3), Position(0, 3)}), 11),
        },
        {
            std::make_pair(Path({Position(0, 2)}), 1)
        },
        {
            std::make_pair(Path({Position(0, 3)}), 1)
        }
    };

    Path resultPath = Utils::findBestPath(possiblePathsAndScore);
    Path ansResultPath({Position(0, 1), Position(2, 1), Position(2, 0), Position(1, 0), Position(1, 2), Position(0, 2)});

    QVERIFY(resultPath == ansResultPath);
}

void TestUtils::testFindBestPath03()
{
    std::vector<std::vector<std::pair<Path, int>>> possiblePathsAndScore {
        {},
        {},
        {},
        {},
        {},
    };

    Path resultPath = Utils::findBestPath(possiblePathsAndScore);
    QVERIFY(resultPath.positions().empty());
}


void TestUtils::testCombinePurePaths01()
{
    size_t maxLengthPath = 20;
    const std::vector<std::vector<unsigned char>> values{{10, 20, 25, 25}, {5, 4, 6, 3}, {1, 3, 5, 1}};
    Matrix matrix(values);
    const std::vector<Sequence> sequences({Sequence({20, 3, 1, 5}, 10), Sequence({3, 1, 5, 6}, 5)});
    const std::vector<std::vector<Position>> adjacencyMatrix{
        {Position(0, 1)},
        {Position(1, 3), Position(2, 1)}
    };
    std::vector<std::vector<Path>> purePaths{
        {    Path({Position(0, 1), Position(2, 1), Position(2, 0), Position(1, 0)})},
        {
             Path({Position(1, 3), Position(2, 3), Position(2, 2), Position(1, 2)}),
             Path({Position(2, 1), Position(2, 0), Position(1, 0), Position(1, 2)})
        },
    };

    std::vector<std::vector<std::pair<Path, int>>> possiblePathsAndScore = Utils::combinePurePaths(purePaths, matrix, sequences, maxLengthPath);

    std::vector<std::vector<std::pair<Path, int>>> ansPossiblePathsAndScore {
        {
            std::make_pair(Path({Position(0, 1), Position(2, 1), Position(2, 0), Position(1, 0)}), 10),
            std::make_pair(Path({Position(0, 1), Position(2, 1), Position(2, 0), Position(1, 0),
                                 Position(1, 3), Position(2, 3), Position(2, 2), Position(1, 2)}), 15),
            std::make_pair(Path({Position(0, 1), Position(2, 1), Position(2, 0), Position(1, 0), Position(1, 2)}), 15)
        },
        {
            std::make_pair(Path({Position(0, 0), Position(1, 0), Position(1, 3), Position(2, 3), Position(2, 2), Position(1, 2)}), 5),
        },
        {
            std::make_pair(Path({Position(0, 1), Position(2, 1), Position(2, 0), Position(1, 0), Position(1, 2)}), 5),
            std::make_pair(Path({Position(0, 1), Position(2, 1), Position(2, 0), Position(1, 0), Position(1, 2)}), 15)
        }
    };

    QVERIFY(isEqualsVectorOfVector(possiblePathsAndScore, ansPossiblePathsAndScore));
}

void TestUtils::testCombinePurePaths02()
{
    size_t maxLengthPath = 20;
    const std::vector<std::vector<unsigned char>> values{{10, 20, 25, 25}, {5, 4, 6, 3}, {1, 3, 5, 1}};
    Matrix matrix(values);
    const std::vector<Sequence> sequences({Sequence({20, 3, 1, 5}, 10), Sequence({25}, 1), Sequence({40, 1}, 5)});
    const std::vector<std::vector<Position>> adjacencyMatrix{
        {Position(0, 1)},
        {Position(0, 2), Position(0, 3)},
        {}
    };
    std::vector<std::vector<Path>> purePaths{
        {    Path({Position(0, 1), Position(2, 1), Position(2, 0), Position(1, 0)})},
        {
            Path({Position(0, 2)}),
            Path({Position(0, 3)})
        },
        {}
    };

    std::vector<std::vector<std::pair<Path, int>>> possiblePathsAndScore = Utils::combinePurePaths(purePaths, matrix, sequences, maxLengthPath);

    std::vector<std::vector<std::pair<Path, int>>> ansPossiblePathsAndScore {
        {
            std::make_pair(Path({Position(0, 1), Position(2, 1), Position(2, 0), Position(1, 0)}), 10),
            std::make_pair(Path({Position(0, 1), Position(2, 1), Position(2, 0), Position(1, 0), Position(1, 3), Position(0, 3), Position(0, 2)}), 11),
            std::make_pair(Path({Position(0, 1), Position(2, 1), Position(2, 0), Position(1, 0), Position(1, 2), Position(0, 2)}), 11),
            std::make_pair(Path({Position(0, 1), Position(2, 1), Position(2, 0), Position(1, 0), Position(1, 2), Position(0, 2), Position(0, 3)}), 11),
            std::make_pair(Path({Position(0, 1), Position(2, 1), Position(2, 0), Position(1, 0), Position(1, 3), Position(0, 3)}), 11),
        },
        {
            std::make_pair(Path({Position(0, 2)}), 1)
        },
        {
            std::make_pair(Path({Position(0, 3)}), 1)
        }
    };

    QVERIFY(isEqualsVectorOfVector(possiblePathsAndScore, ansPossiblePathsAndScore));
}

void TestUtils::testCombinePurePaths03()
{
    size_t maxLengthPath = 20;
    const std::vector<std::vector<unsigned char>> values{{10, 20, 25, 25}, {5, 4, 6, 3}, {1, 3, 5, 1}};
    Matrix matrix(values);
    const std::vector<Sequence> sequences({Sequence({3, 1, 5, 6}, 10), Sequence({3, 1}, 5), Sequence({40, 1}, 5)});
    const std::vector<std::vector<Position>> adjacencyMatrix{
        {Position(1, 3), Position(2, 1)},
        {Position(1, 3), Position(2, 1)},
        {}
    };
    std::vector<std::vector<Path>> purePaths{
        {
             Path({Position(1, 3), Position(2, 3), Position(2, 2), Position(1, 2)}),
             Path({Position(2, 1), Position(2, 0), Position(1, 0), Position(1, 2)})
        },
        {
            Path({Position(1, 3), Position(2, 3)}),
            Path({Position(2, 1), Position(2, 3)}),
            Path({Position(2, 1), Position(2, 0)})
        },
        {}
    };

    std::vector<std::vector<std::pair<Path, int>>> possiblePathsAndScore = Utils::combinePurePaths(purePaths, matrix, sequences, maxLengthPath);

    std::vector<std::vector<std::pair<Path, int>>> ansPossiblePathsAndScore {
        {
            std::make_pair(Path({Position(0, 0), Position(1, 0), Position(1, 3), Position(2, 3), Position(2, 2), Position(1, 2)}), 10),
            std::make_pair(Path({Position(0, 0), Position(1, 0), Position(1, 3), Position(2, 3), Position(2, 2), Position(1, 2)}), 15),
            std::make_pair(Path({Position(0, 0), Position(1, 0), Position(1, 3), Position(2, 3), Position(2, 2), Position(1, 2), Position(1, 1), Position(2, 1), Position(2, 0) }), 15),
        },
        {
            std::make_pair(Path({Position(0, 1), Position(2, 1), Position(2, 0), Position(1, 0), Position(1, 2)}), 10),
            std::make_pair(Path({Position(0, 1), Position(2, 1), Position(2, 0), Position(1, 0), Position(1, 2)}), 15)

        },
        {
             std::make_pair(Path({Position(0, 0), Position(1, 0), Position(1, 3), Position(2, 3)}), 5),
             std::make_pair(Path({Position(0, 0), Position(1, 0), Position(1, 3), Position(2, 3), Position(2, 2), Position(1, 2)}), 15)
        },
        {
             std::make_pair(Path({Position(0, 1), Position(2, 1), Position(2, 3)}), 5),
        },
        {
            std::make_pair(Path({Position(0, 1), Position(2, 1), Position(2, 0)}), 5),
            std::make_pair(Path({Position(0, 1), Position(2, 1), Position(2, 0), Position(1, 0), Position(1, 3), Position(2, 3), Position(2, 2), Position(1, 2)}), 15),
            std::make_pair(Path({Position(0, 1), Position(2, 1), Position(2, 0), Position(1, 0), Position(1, 2)}), 15)
        },
    };

    QVERIFY(isEqualsVectorOfVector(possiblePathsAndScore, ansPossiblePathsAndScore));

}
