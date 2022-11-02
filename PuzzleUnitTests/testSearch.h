#ifndef TEST_SEARCH_H
#define TEST_SEARCH_H

#include <QTest>

class TestSearch: public QObject{

    Q_OBJECT
public:

    explicit TestSearch(QObject *parent = 0): QObject(parent){
    };

private slots:

    void testDFS01();
    void testDFS02();
    void testDFS03();
    void testDFS04();
    void testDFS05();
    void testDFS06();
    void testDFS07();
    void testDFS08();
    void testDFS09();

    void testBFS01();
    void testBFS02();
    void testBFS03();
    void testBFS04();
    void testBFS05();
    void testBFS06();
    void testBFS07();
};
#endif // TESTSEARCH_H
