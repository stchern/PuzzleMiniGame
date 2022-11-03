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

    void testIsFoundNextPositionsInColsAndRowsByPosition01();

    void testIsFoundInRowByPosition01();

    void testIsFoundInColByPosition01();

    void testIsFoundNextPositionsInColsAndRowsByValue01();

    void testIsFoundTwoPositionsForWastedMoves01();

};

#endif
