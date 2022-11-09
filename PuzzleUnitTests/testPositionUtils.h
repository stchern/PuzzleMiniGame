#ifndef PUZZLE_POSITION_UTILS_TEST_H
#define PUZZLE_POSITION_UTILS_TEST_H

#include <QTest>

class TestPositionUtils: public QObject{

    Q_OBJECT
public:

    explicit TestPositionUtils(QObject *parent = 0): QObject(parent){
    };


private slots:

    void testIsPositionInPath01();
    void testIsPositionInPath02();

    void testIsFoundNextPositionsInColsAndRowsByPosition01();
    void testIsFoundNextPositionsInColsAndRowsByPosition02();
    void testIsFoundNextPositionsInColsAndRowsByPosition03();
    void testIsFoundNextPositionsInColsAndRowsByPosition04();

    void testIsFoundNextPositionsInColsAndRowsByValue01();
    void testIsFoundNextPositionsInColsAndRowsByValue02();
    void testIsFoundNextPositionsInColsAndRowsByValue03();
    void testIsFoundNextPositionsInColsAndRowsByValue04();

    void testIsFoundTwoPositionsForWastedMoves01();
    void testIsFoundTwoPositionsForWastedMoves02();
    void testIsFoundTwoPositionsForWastedMoves03();

};

#endif
