#ifndef PUZZLE_SEQUENCE_UTILS_TEST_H
#define PUZZLE_SEQUENCE_UTILS_TEST_H

#include <QTest>

class TestSequenceUtils: public QObject{

    Q_OBJECT
public:

    explicit TestSequenceUtils(QObject *parent = 0): QObject(parent){
    };


private slots:

    void testHasOverlapping01();
    void testHasOverlapping02();
    void testHasOverlapping03();
    void testHasOverlapping04();
    void testHasOverlapping05();
    void testHasOverlapping06();
    void testHasOverlapping07();

};

#endif
