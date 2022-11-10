#ifndef PUZZLE_PATH_UTILS_TEST_H
#define PUZZLE_PATH_UTILS_TEST_H

#include <QTest>

class TestPathUtils: public QObject{

    Q_OBJECT
public:

    explicit TestPathUtils(QObject *parent = 0): QObject(parent){
    };


private slots:

    void testCombinePurePath01();
    void testCombinePurePath02();
    void testCombinePurePath03();
    void testCombinePurePath04();

    void testIsCreatedPathsAfterCurrent01();
    void testIsCreatedPathsAfterCurrent02();
    void testIsCreatedPathsAfterCurrent03();
    void testIsCreatedPathsAfterCurrent04();
    void testIsCreatedPathsAfterCurrent05();

    void testHasOverlapping01();
    void testHasOverlapping02();
    void testHasOverlapping03();
    void testHasOverlapping04();

    void testHasIntersection01();
    void testHasIntersection02();
    void testHasIntersection03();
    void testHasIntersection04();
    void testHasIntersection05();
    void testHasIntersection06();
    void testHasIntersection07();
    void testHasIntersection08();

    void testConcatenatePath01();
    void testConcatenatePath02();
    void testConcatenatePath03();
};

#endif
