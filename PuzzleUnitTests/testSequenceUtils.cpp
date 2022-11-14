#include "testSequenceUtils.h"
#include "src/SequenceUtils.h"
#include "utils.h"

using namespace InternalUtils::USequence;


//void TestSequenceUtils::testAddOneWastedMoveBeforeFirstSequence01()
//{
//    const Path path(std::vector<Position>({
//                                              Position(1, 2),
//                                              Position(1, 3),
//                                              Position(2, 3),
//                                          }));
//    Path outPath;
//    bool value = addOneWastedMoveBeforeFirstSequence(path, outPath);
//    const Path ansPath(std::vector<Position>({
//                                              Position(0, 2),
//                                              Position(1, 2),
//                                              Position(1, 3),
//                                              Position(2, 3),
//                                          }));
//    QVERIFY(value);
//    QVERIFY(outPath == ansPath);
//}

//void TestSequenceUtils::testAddOneWastedMoveBeforeFirstSequence02()
//{
//    const Path path(std::vector<Position>({
//                                              Position(3, 3)
//                                          }));
//    Path outPath;
//    bool value = addOneWastedMoveBeforeFirstSequence(path, outPath);
//    const Path ansPath(std::vector<Position>({
//                                              Position(0, 3),
//                                              Position(3, 3)
//                                          }));
//    QVERIFY(value);
//    QVERIFY(outPath == ansPath);
//}

//void TestSequenceUtils::testAddOneWastedMoveBeforeFirstSequence03()
//{
//    const Path path(std::vector<Position>({
//                                              Position(1, 2),
//                                              Position(1, 3),
//                                              Position(0, 3),
//                                              Position(0, 2)
//                                          }));
//    Path outPath;
//    bool value = addOneWastedMoveBeforeFirstSequence(path, outPath);
//    QVERIFY(!value);
//    QVERIFY(outPath.positions().empty());
//}

//void TestSequenceUtils::testAddTwoWastedMoveBeforeFirstSequence01()
//{
//    const Path path(std::vector<Position>({
//                                              Position(1, 2),
//                                              Position(1, 3),
//                                              Position(2, 3),
//                                          }));
//    int maxColoumnCount = 4;
//    Path outPath;
//    bool value = addTwoWastedMovesBeforeFirstSequence(path, maxColoumnCount, outPath);
//    const Path ansPath(std::vector<Position>({
//                                                 Position(0, 0),
//                                                 Position(1, 0),
//                                                 Position(1, 2),
//                                                 Position(1, 3),
//                                                 Position(2, 3),
//                                          }));
//    QVERIFY(value);
//    QVERIFY(outPath == ansPath);
//}

//void TestSequenceUtils::testAddTwoWastedMoveBeforeFirstSequence02()
//{
//    const Path path(std::vector<Position>({
//                                              Position(1, 0),
//                                              Position(1, 1),
//                                              Position(2, 1),
//                                          }));
//    int maxColoumnCount = 2;
//    Path outPath;
//    bool value = addTwoWastedMovesBeforeFirstSequence(path, maxColoumnCount, outPath);
//    QVERIFY(!value);
//    QVERIFY(outPath.positions().empty());
//}

//void TestSequenceUtils::testAddTwoWastedMoveBeforeFirstSequence03()
//{
//    const Path path(std::vector<Position>({
//                                              Position(1, 0),
//                                              Position(2, 0),
//                                              Position(2, 1),
//                                              Position(1, 1),
//                                              Position(1, 2),
//                                              Position(2, 2),
//                                              Position(2, 3),
//                                              Position(1, 3),
//                                          }));
//    int maxColoumnCount = 4;
//    Path outPath;
//    bool value = addTwoWastedMovesBeforeFirstSequence(path, maxColoumnCount, outPath);
//    QVERIFY(!value);
//    QVERIFY(outPath.positions().empty());
//}


//void TestSequenceUtils::testAddTwoWastedMoveBeforeFirstSequence04()
//{
//    const Path path(std::vector<Position>({
//                                              Position(1, 0),
//                                              Position(2, 0),
//                                              Position(2, 1),
//                                              Position(1, 1),
//                                              Position(1, 2),
//                                              Position(2, 2),
//                                          }));
//    int maxColoumnCount = 4;
//    Path outPath;
//    bool value = addTwoWastedMovesBeforeFirstSequence(path, maxColoumnCount, outPath);
//    const Path ansPath(std::vector<Position>({
//                                                 Position(0, 3),
//                                                 Position(1, 3),
//                                                 Position(1, 0),
//                                                 Position(2, 0),
//                                                 Position(2, 1),
//                                                 Position(1, 1),
//                                                 Position(1, 2),
//                                                 Position(2, 2),
//                                          }));
//    QVERIFY(value);
//    QVERIFY(outPath == ansPath);
//}


//void TestSequenceUtils::testIsPossibleAddWastedMovesBeforeFirstSequences01()
//{
//    const Path path(std::vector<Position>({
//                                              Position(1, 0),
//                                              Position(2, 0),
//                                              Position(2, 1),
//                                              Position(1, 1),
//                                              Position(1, 2),
//                                              Position(2, 2),
//                                          }));
//    const int maxColumnCount = 4;
//    const size_t maxLengthPath = 5;
//    Path outPath;

//    bool value = isPossibleAddWastedMovesBeforeFirstSequences(path, maxColumnCount, maxLengthPath, outPath);
//    QVERIFY(!value);
//    QVERIFY(outPath.positions().empty());
//}

//void TestSequenceUtils::testIsPossibleAddWastedMovesBeforeFirstSequences02()
//{
//    const Path path(std::vector<Position>({
//                                              Position(1, 0),
//                                              Position(2, 0),
//                                              Position(2, 1),
//                                              Position(1, 1),
//                                              Position(1, 2),
//                                              Position(2, 2),
//                                          }));
//    const int maxColumnCount = 4;
//    const size_t maxLengthPath = 8;
//    Path outPath;

//    bool value = isPossibleAddWastedMovesBeforeFirstSequences(path, maxColumnCount, maxLengthPath, outPath);
//    const Path ansPath(std::vector<Position>({
//                                                 Position(0, 3),
//                                                 Position(1, 3),
//                                                 Position(1, 0),
//                                                 Position(2, 0),
//                                                 Position(2, 1),
//                                                 Position(1, 1),
//                                                 Position(1, 2),
//                                                 Position(2, 2),
//                                          }));
//    QVERIFY(value);
//    QVERIFY(outPath == ansPath);
//}

//void TestSequenceUtils::testIsPossibleAddWastedMovesBeforeFirstSequences03()
//{
//    const Path path(std::vector<Position>({
//                                              Position(0, 0),
//                                              Position(1, 0),
//                                              Position(1, 1),
//                                              Position(2, 1),
//                                              Position(2, 2),
//                                          }));
//    const int maxColumnCount = 4;
//    const size_t maxLengthPath = 5;
//    Path outPath;

//    bool value = isPossibleAddWastedMovesBeforeFirstSequences(path, maxColumnCount, maxLengthPath, outPath);
//    const Path ansPath(std::vector<Position>({
//                                                 Position(0, 0),
//                                                 Position(1, 0),
//                                                 Position(1, 1),
//                                                 Position(2, 1),
//                                                 Position(2, 2),
//                                          }));
//    QVERIFY(value);
//    QVERIFY(outPath == ansPath);
//}

//void TestSequenceUtils::testIsPossibleAddWastedMovesBeforeFirstSequences04()
//{
//    const Path path(std::vector<Position>({
//                                              Position(3, 3)
//                                          }));
//    const int maxColumnCount = 4;
//    const size_t maxLengthPath = 2;
//    Path outPath;

//    bool value = isPossibleAddWastedMovesBeforeFirstSequences(path, maxColumnCount, maxLengthPath, outPath);
//    const Path ansPath(std::vector<Position>({
//                                              Position(0, 3),
//                                              Position(3, 3)
//                                          }));
//    QVERIFY(value);
//    QVERIFY(outPath == ansPath);
//}

//void TestSequenceUtils::testIsPossibleAddWastedMovesBeforeFirstSequences05()
//{
//    const Path path(std::vector<Position>({
//                                              Position(1, 2),
//                                              Position(1, 3),
//                                              Position(2, 3)
//                                          }));
//    const int maxColumnCount = 4;
//    const size_t maxLengthPath = 4;
//    Path outPath;

//    bool value = isPossibleAddWastedMovesBeforeFirstSequences(path, maxColumnCount, maxLengthPath, outPath);
//    const Path ansPath(std::vector<Position>({
//                                              Position(0, 2),
//                                              Position(1, 2),
//                                              Position(1, 3),
//                                              Position(2, 3)
//                                          }));
//    QVERIFY(value);
//    QVERIFY(outPath == ansPath);
//}

//void TestSequenceUtils::testIsPossibleAddWastedMovesBeforeFirstSequences06() {
////    const Matrix matrix =
////    {{
////        {0x9B, 0x9B, 0x72, 0x9B, 0xD4},
////        {0x10, 0xD4, 0xD4, 0x9B, 0x10},
////        {0x72, 0x9B, 0x3A, 0x10, 0x9B},
////        {0x3A, 0xD4, 0x9B, 0x3A, 0x9B},
////        {0x72, 0x10, 0x10, 0xD4, 0x10}
////    }};

//    const Path path
//    {
//        {{2, 2}, {2, 3}, {4, 3}, {4, 0}, {2, 0}}
//    };

//    const int maxPathLength = 7;
//    const int maxColumnCount = 4;
//    Path outPath;
//    bool value = isPossibleAddWastedMovesBeforeFirstSequences(path, maxColumnCount, maxPathLength, outPath);
//    const Path expectedSolution = {{{0, 2}, {2, 2}, {2, 3}, {4, 3}, {4, 0}, {2, 0}}};

//    QVERIFY(value);
//    QVERIFY(outPath == expectedSolution);
//}

//void TestSequenceUtils::testIsPossibleAddWastedMovesBetweenSequences01()
//{
//    const std::vector<std::vector<unsigned char>> values{{10, 20, 25, 25}, {5, 3, 3, 2}, {1, 3, 4, 5}};
//    Matrix matrix(values);
//    const Path rhsPath({
//                        Position(0, 1), Position(2, 1), Position(2, 0), Position(1, 0)
//                       });
//    const Path lhsPath({
//                        Position(1, 2), Position(2, 2), Position(2, 3), Position(0, 3)
//                       });
//    const size_t maxLengthPath = 10;
//    std::vector<Path> outPaths;

//    bool value = isPossibleAddWastedMovesBetweenSequences(rhsPath, lhsPath, matrix, maxLengthPath, outPaths);
//    std::vector<Path> ansPaths = {
//         Path({
//            Position(0, 1), Position(2, 1), Position(2, 0), Position(1, 0),
//            Position(1, 2), Position(2, 2), Position(2, 3), Position(0, 3)
//        }),
//    };

//    QVERIFY(value);
//    QVERIFY(UtilsUnitTests::isEqualsVector(outPaths, ansPaths));

//}

void TestSequenceUtils::testIsPossibleAddWastedMovesBetweenSequences02()
{
    const std::vector<std::vector<unsigned char>> values{{10, 20, 25, 25}, {5, 3, 3, 2}, {1, 3, 4, 5}};
    Matrix matrix(values);
    const Path rhsPath({
                        Position(0, 1), Position(2, 1), Position(2, 0), Position(1, 0)
                       });
    const Path lhsPath({
                        Position(2, 2), Position(2, 3), Position(0, 3)
                       });
    const size_t maxLengthPath = 10;
    std::vector<Path> outPaths;

    bool value = isPossibleAddWastedMovesBetweenSequences(rhsPath, lhsPath, matrix, maxLengthPath, outPaths);
    std::vector<Path> ansPaths = {
         Path({
            Position(0, 1), Position(2, 1), Position(2, 0), Position(1, 0),
            Position(1, 2), Position(2, 2), Position(2, 3), Position(0, 3)
        }),
    };

    QVERIFY(value);
    QVERIFY(UtilsUnitTests::isEqualsVector(outPaths, ansPaths));
}

void TestSequenceUtils::testIsPossibleAddWastedMovesBetweenSequences03()
{
    const std::vector<std::vector<unsigned char>> values{{10, 20, 25, 25}, {5, 3, 3, 2}, {1, 3, 4, 5}};
    Matrix matrix(values);
    const Path lhsPath({
                        Position(0, 1), Position(2, 1), Position(2, 0), Position(1, 0)  // 20  3 1 5
                       });
    const Path rhsPath({
                        Position(2, 3), Position(0, 3)  //5 25
                       });
    const size_t maxLengthPath = 10;
    std::vector<Path> outPaths;

    bool value = isPossibleAddWastedMovesBetweenSequences(lhsPath, rhsPath, matrix, maxLengthPath, outPaths);
    std::vector<Path> ansPaths = {
         Path({
            Position(0, 1), Position(2, 1), Position(2, 0), Position(1, 0),
            Position(1, 2), Position(2, 2), Position(2, 3), Position(0, 3)
        })
    };

    QVERIFY(value);
    QVERIFY(UtilsUnitTests::isEqualsVector(outPaths, ansPaths));
}

//void TestSequenceUtils::testIsPossibleAddWastedMovesBetweenSequences04()
//{

//    const std::vector<std::vector<unsigned char>> values{{10, 20, 25, 25}, {5, 3, 3, 2}, {1, 3, 4, 5}};
//    Matrix matrix(values);
//    const Path rhsPath({
//                        Position(0, 1), Position(2, 1), Position(2, 0), Position(1, 0)
//                       });
//    const Path lhsPath({
//                        Position(1, 2), Position(2, 2), Position(2, 3), Position(0, 3)
//                       });
//    const size_t maxLengthPath = 5;
//    std::vector<Path> outPaths;

//    bool value = isPossibleAddWastedMovesBetweenSequences(rhsPath, lhsPath, matrix, maxLengthPath, outPaths);
//    std::vector<Path> ansPaths = {
//         Path({
//            Position(0, 1), Position(2, 1), Position(2, 0), Position(1, 0), Position(1, 2), Position(2, 2), Position(2, 3), Position(0, 3)
//        }),
//    };

//    QVERIFY(!value);
//    QVERIFY(outPaths.empty());
//}

//void TestSequenceUtils::testIsPossibleAddWastedMovesBetweenSequences05()
//{
//    const std::vector<std::vector<unsigned char>> values{{10, 20, 25, 25}, {5, 3, 3, 2}, {1, 3, 4, 5}};
//    Matrix matrix(values);
//    const Path rhsPath({
//                        Position(0, 1), Position(2, 1), Position(2, 0)
//                       });
//    const Path lhsPath({
//                        Position(1, 2), Position(2, 2), Position(2, 3), Position(0, 3)
//                       });
//    const size_t maxLengthPath = 10;
//    std::vector<Path> outPaths;

//    bool value = isPossibleAddWastedMovesBetweenSequences(rhsPath, lhsPath, matrix, maxLengthPath, outPaths);
//    std::vector<Path> ansPaths = {
//         Path({
//            Position(0, 1), Position(2, 1), Position(2, 0), Position(1, 0), Position(1, 2), Position(2, 2), Position(2, 3), Position(0, 3)
//        }),
//    };

//    QVERIFY(value);
//    QVERIFY(UtilsUnitTests::isEqualsVector(outPaths, ansPaths));
//}

//void TestSequenceUtils::testIsPossibleAddWastedMovesBetweenSequences06()
//{
//    const std::vector<std::vector<unsigned char>> values{{10, 20, 25, 25}, {5, 3, 3, 2}, {1, 3, 4, 5}};
//    Matrix matrix(values);
//    const Path rhsPath({
//                        Position(0, 1)
//                       });
//    const Path lhsPath({
//                        Position(2, 1)
//                       });
//    const size_t maxLengthPath = 3;
//    std::vector<Path> outPaths;

//    bool value = isPossibleAddWastedMovesBetweenSequences(rhsPath, lhsPath, matrix, maxLengthPath, outPaths);
//    std::vector<Path> ansPaths = {
//         Path({
//            Position(0, 1), Position(2, 1)
//        }),
//    };

//    QVERIFY(value);
//    QVERIFY(UtilsUnitTests::isEqualsVector(outPaths, ansPaths));
//}

//void TestSequenceUtils::testIsPossibleAddWastedMovesBetweenSequences07()
//{
//    const std::vector<std::vector<unsigned char>> values{{10, 20, 25, 25}, {5, 3, 3, 2}, {1, 3, 4, 5}};
//    Matrix matrix(values);
//    const Path rhsPath({
//                        Position(0, 1)
//                       });
//    const Path lhsPath({
//                        Position(1, 2), Position(2, 2), Position(2, 3), Position(0, 3)
//                       });
//    const size_t maxLengthPath = 10;
//    std::vector<Path> outPaths;

//    bool value = isPossibleAddWastedMovesBetweenSequences(rhsPath, lhsPath, matrix, maxLengthPath, outPaths);
//    std::vector<Path> ansPaths = {
//        Path({
//            Position(0, 1), Position(1, 1),  Position(1, 2), Position(2, 2), Position(2, 3), Position(0, 3)
//        })
//    };

//    QVERIFY(value);
//    QVERIFY(UtilsUnitTests::isEqualsVector(outPaths, ansPaths));
//}

//void TestSequenceUtils::testIsPossibleAddWastedMovesBetweenSequences08()
//{
//    const std::vector<std::vector<unsigned char>> values{{10, 20, 25, 25}, {5, 3, 3, 2}, {1, 3, 4, 5}};
//    Matrix matrix(values);
//    const Path lhsPath({
//                        Position(1, 1)
//                       });
//    const Path rhsPath({
//                        Position(1, 2), Position(2, 2), Position(2, 3), Position(0, 3)
//                       });
//    const size_t maxLengthPath = 10;
//    std::vector<Path> outPaths;

//    bool value = isPossibleAddWastedMovesBetweenSequences(rhsPath, lhsPath, matrix, maxLengthPath, outPaths);
//    std::vector<Path> ansPaths = {
//        Path({
//           Position(1, 2), Position(2, 2), Position(2, 3), Position(0, 3), Position(0, 0), Position(1, 0), Position(1, 1),
//       }),
//        Path({
//           Position(1, 2), Position(2, 2), Position(2, 3), Position(0, 3), Position(0, 1), Position(1, 1)
//        })
//    };

//    QVERIFY(value);
//    QVERIFY(UtilsUnitTests::isEqualsVector(outPaths, ansPaths));
//}

//void TestSequenceUtils::testIsPossibleAddWastedMovesBetweenSequences09()
//{
//    const std::vector<std::vector<unsigned char>> values{{10, 20, 25, 25}, {5, 3, 3, 2}, {1, 3, 4, 5}};
//    Matrix matrix(values);
//    const Path rhsPath({
//                        Position(0, 1), Position(2, 1), Position(2, 0)
//                       });
//    const Path lhsPath({
//                        Position(1, 2), Position(2, 2), Position(2, 3), Position(0, 3)
//                       });
//    const size_t maxLengthPath = 7;
//    std::vector<Path> outPaths;

//    bool value = isPossibleAddWastedMovesBetweenSequences(rhsPath, lhsPath, matrix, maxLengthPath, outPaths);
//    std::vector<Path> ansPaths = {
//         Path({
//            Position(0, 1), Position(2, 1), Position(2, 0), Position(1, 0), Position(1, 2), Position(2, 2), Position(2, 3), Position(0, 3)
//        }),
//    };

//    QVERIFY(!value);
//    QVERIFY(outPaths.empty());
//}

//void TestSequenceUtils::testIsPossibleAddWastedMovesBetweenSequences10()
//{
//    const Matrix matrix =
//    {{
//        {0x10, 0x10, 0x10, 0x10, 0x10},
//        {0x10, 0x10, 0x10, 0x10, 0x10},
//        {0x3A, 0xD4, 0x10, 0x9B, 0x72},
//        {0x10, 0x10, 0x10, 0x10, 0x10},
//        {0x10, 0x10, 0x10, 0x10, 0x10}
//    }};

//    const std::vector<Sequence> sequences =
//    {
//        Sequence({0x3A, 0x9B}, 10),
//        Sequence({0x72, 0xD4}, 10)
//    };

//    const int maxPathLength = 7;
//    const Path lhsPath({
//                        Position(0, 0), Position(2, 0), Position(2, 3)
//                       });
//    const Path rhsPath({
//                        Position(2, 4), Position(2, 1)
//                       });
//    std::vector<Path> outPaths;

//    bool value = isPossibleAddWastedMovesBetweenSequences(lhsPath, rhsPath, matrix, maxPathLength, outPaths);
//    std::vector<Path> ansPaths = {
//         Path({ {0, 0}, {2, 0}, {2, 3}, {0, 3}, {0, 4}, {2, 4}, {2, 1}}),
//         Path({ {0, 0}, {2, 0}, {2, 3}, {1, 3}, {1, 4}, {2, 4}, {2, 1}}),
//         Path({ {0, 0}, {2, 0}, {2, 3}, {3, 3}, {3, 4}, {2, 4}, {2, 1}}),
//         Path({ {0, 0}, {2, 0}, {2, 3}, {4, 3}, {4, 4}, {2, 4}, {2, 1}}),
//    };

//    QVERIFY(value);
//    QVERIFY(UtilsUnitTests::isEqualsVector(outPaths, ansPaths));
//}















