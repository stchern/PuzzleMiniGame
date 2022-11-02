#ifndef TEST_PUZZLE_UTILS_H
#define TEST_PUZZLE_UTILS_H


#include <QTest>

class TestUtils: public QObject{

    Q_OBJECT
public:

    explicit TestUtils(QObject *parent = 0): QObject(parent){
    };

private slots:

    void testAdjacencyMatrix01();
    void testAdjacencyMatrix02();
    void testAdjacencyMatrix03();
    void testfindAllPurePaths();

};


#endif // TESTUTILS_H
