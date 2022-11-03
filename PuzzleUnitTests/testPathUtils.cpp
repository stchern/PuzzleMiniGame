#include "testPathUtils.h"
#include "src/PathUtils.h"
#include "utils.h"

using namespace InternalUtils::UPath;

void TestPathUtils::testCombinePurePath01()
{
    const std::vector<std::vector<Path>> purePaths;



}

void TestPathUtils::testCombinePurePath02()
{

}

void TestPathUtils::testCombinePurePath03()
{

}

void TestPathUtils::testIsCreatedPathsAfterCurrent01()
{
    const std::vector<std::vector<unsigned char>> values{{10, 20, 25, 25}, {5, 3, 3, 2}, {1, 3, 4, 5}};
    Matrix matrix(values);
    const Path rhsPath({
                        Position(0, 1), Position(2, 1), Position(2, 0), Position(1, 0)
                       });
    const Path lhsPath({
                        Position(1, 2), Position(2, 2), Position(2, 3), Position(0, 3)
                       });
    const size_t maxLengthPath = 5;
    std::vector<Path> outPaths;

    bool value = isCreatedPathsAfterCurrent(rhsPath, lhsPath, matrix, maxLengthPath, outPaths);

    QVERIFY(!value);
    QVERIFY(outPaths.empty());

}

void TestPathUtils::testIsCreatedPathsAfterCurrent02()
{
    const std::vector<std::vector<unsigned char>> values{{10, 20, 25, 25}, {5, 3, 3, 2}, {1, 3, 4, 5}};
    Matrix matrix(values);
    const Path rhsPath({
                        Position(0, 1), Position(2, 1), Position(2, 0), Position(1, 0)
                       });
    const Path lhsPath({
                        Position(1, 2), Position(2, 2), Position(2, 1), Position(0, 3)
                       });
    const size_t maxLengthPath = 8;
    std::vector<Path> outPaths;

    bool value = isCreatedPathsAfterCurrent(rhsPath, lhsPath, matrix, maxLengthPath, outPaths);

    QVERIFY(!value);
    QVERIFY(outPaths.empty());
}

void TestPathUtils::testIsCreatedPathsAfterCurrent03()
{
    const std::vector<std::vector<unsigned char>> values{{10, 20, 25, 25}, {5, 3, 3, 2}, {1, 3, 4, 5}};
    Matrix matrix(values);
    const Path rhsPath({
                        Position(0, 1), Position(2, 1), Position(2, 0), Position(1, 0)
                       });
    const Path lhsPath({
                        Position(2, 0), Position(1, 0), Position(1, 2)
                       });
    const size_t maxLengthPath = 8;
    std::vector<Path> outPaths;

    bool value = isCreatedPathsAfterCurrent(rhsPath, lhsPath, matrix, maxLengthPath, outPaths);
    const std::vector<Path> ansOutPaths({
                           Path({
                            Position(0, 1), Position(2, 1), Position(2, 0), Position(1, 0),
                                          Position(1, 2)
                           })
                       });

    QVERIFY(value);
    QVERIFY(UtilsUnitTests::isEqualsVector(outPaths, ansOutPaths));
}

void TestPathUtils::testIsCreatedPathsAfterCurrent04()
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

    bool value = isCreatedPathsAfterCurrent(rhsPath, lhsPath, matrix, maxLengthPath, outPaths);
    std::vector<Path> ansPaths = {
         Path({
            Position(0, 1), Position(2, 1), Position(2, 0), Position(1, 0),
            Position(1, 2), Position(2, 2), Position(2, 3), Position(0, 3)
        }),
    };


    QVERIFY(value);
    QVERIFY(UtilsUnitTests::isEqualsVector(outPaths, ansPaths));
}

void TestPathUtils::testIsCreatedPathsAfterCurrent05()
{
    const std::vector<std::vector<unsigned char>> values{{10, 20, 25, 25}, {5, 3, 3, 2}, {1, 3, 4, 5}};
    Matrix matrix(values);
    const Path rhsPath({
                        Position(0, 1), Position(2, 1), Position(2, 0), Position(1, 0)
                       });
    const Path lhsPath({
                        Position(2, 3), Position(0, 3)
                       });
    const size_t maxLengthPath = 10;
    std::vector<Path> outPaths;
    bool value = isCreatedPathsAfterCurrent(rhsPath, lhsPath, matrix, maxLengthPath, outPaths);
    std::vector<Path> ansPaths = {
         Path({
            Position(0, 1), Position(2, 1), Position(2, 0), Position(1, 0), Position(0, 3)
        })
    };

    QVERIFY(value);
    QVERIFY(UtilsUnitTests::isEqualsVector(outPaths, ansPaths));
}

void TestPathUtils::testHasIntersection01()
{
    const Path rhsPath({
                           Position(0, 1), Position(2, 1), Position(2, 0)
                       });
    const Path lhsPath({
                           Position(1, 2), Position(2, 2), Position(2, 3), Position(0, 3)
                       });

    bool value = hasIntersection(rhsPath, lhsPath);

    QVERIFY(!value);
}

void TestPathUtils::testHasIntersection02()
{
    const Path rhsPath({
                           Position(0, 1), Position(2, 1), Position(2, 0)
                       });
    const Path lhsPath({
                           Position(2, 1), Position(2, 0), Position(2, 3), Position(0, 3)
                       });

    bool value = hasIntersection(rhsPath, lhsPath);

    QVERIFY(!value);
}

void TestPathUtils::testHasIntersection03()
{
    const Path rhsPath({
                           Position(0, 1), Position(2, 1), Position(2, 0)
                       });
    const Path lhsPath({
                           Position(2, 1), Position(3, 1), Position(2, 3), Position(0, 3)
                       });

    bool value = hasIntersection(rhsPath, lhsPath);

    QVERIFY(value);
}

void TestPathUtils::testHasIntersection04()
{
    const Path rhsPath({
                           Position(0, 1), Position(2, 1), Position(2, 0)
                       });
    const Path lhsPath({
                           Position(2, 0), Position(2, 1), Position(2, 3), Position(0, 3)
                       });

    bool value = hasIntersection(rhsPath, lhsPath);

    QVERIFY(!value);
}

void TestPathUtils::testHasIntersection05()
{
    const Path rhsPath({
                           Position(0, 1), Position(2, 1), Position(2, 3)
                       });
    const Path lhsPath({
                           Position(2, 0), Position(2, 1), Position(0, 1), Position(0, 3)
                       });

    bool value = hasIntersection(rhsPath, lhsPath);

    QVERIFY(value);
}

void TestPathUtils::testHasIntersection06()
{

    const Path rhsPath({
                    Position(0, 1), Position(2, 1), Position(2, 0), Position(1, 0)
                   });
    const Path lhsPath({
                    Position(2, 0), Position(1, 0), Position(2, 1), Position(0, 3)
                   });
    bool value = hasIntersection(rhsPath, lhsPath);

    QVERIFY(value); // WARNING!! THIS IS NOT CORRECT
}

void TestPathUtils::testConcatenatePath01()
{
    const Path rhsPath({
                           Position(0, 1), Position(2, 1), Position(2, 3)
                       });
    const Path lhsPath({
                           Position(2, 0), Position(3, 0)
                       });
    Path outPath = concatenatePaths(rhsPath, lhsPath);
    const Path ansOutPath({
                              Position(0, 1), Position(2, 1), Position(2, 3), Position(2, 0), Position(3, 0)
                          });

    QVERIFY(outPath == ansOutPath);
}

void TestPathUtils::testConcatenatePath02()
{
    const Path rhsPath({
                           Position(0, 1)
                       });
    const Path lhsPath({
                           Position(2, 0), Position(3, 0)
                       });
    Path outPath = concatenatePaths(rhsPath, lhsPath);
    const Path ansOutPath({
                              Position(0, 1), Position(2, 0), Position(3, 0)
                          });

    QVERIFY(outPath == ansOutPath);
}

void TestPathUtils::testConcatenatePath03()
{
    const Path lhsPath({
                           Position(0, 1)
                       });
    const Path rhsPath({
                           Position(2, 0), Position(3, 0)
                       });
    Path outPath = concatenatePaths(rhsPath, lhsPath);
    const Path ansOutPath({
                              Position(2, 0), Position(3, 0), Position(0, 1)
                          });

    QVERIFY(outPath == ansOutPath);
}
