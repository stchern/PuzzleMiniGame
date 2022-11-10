#ifndef PUZZLE_SEQUENCE_UTILS_TEST_H
#define PUZZLE_SEQUENCE_UTILS_TEST_H

#include <QTest>

class TestSequenceUtils: public QObject{

    Q_OBJECT
public:

    explicit TestSequenceUtils(QObject *parent = 0): QObject(parent){
    };


private slots:

//    void testHasOverlapping01();
//    void testHasOverlapping02();
//    void testHasOverlapping03();
//    void testHasOverlapping04();
//    void testHasOverlapping05();
//    void testHasOverlapping06();
//    void testHasOverlapping07();

    void testAddOneWastedMoveBeforeFirstSequence01();
    void testAddOneWastedMoveBeforeFirstSequence02();
    void testAddOneWastedMoveBeforeFirstSequence03();

    void testAddTwoWastedMoveBeforeFirstSequence01();
    void testAddTwoWastedMoveBeforeFirstSequence02();
    void testAddTwoWastedMoveBeforeFirstSequence03();
    void testAddTwoWastedMoveBeforeFirstSequence04();

    void testIsPossibleAddWastedMovesBeforeFirstSequences01();
    void testIsPossibleAddWastedMovesBeforeFirstSequences02();
    void testIsPossibleAddWastedMovesBeforeFirstSequences03();
    void testIsPossibleAddWastedMovesBeforeFirstSequences04();
    void testIsPossibleAddWastedMovesBeforeFirstSequences05();

    void testIsPossibleAddWastedMovesBetweenSequences01();
    void testIsPossibleAddWastedMovesBetweenSequences02();
    void testIsPossibleAddWastedMovesBetweenSequences03();
    void testIsPossibleAddWastedMovesBetweenSequences04();
    void testIsPossibleAddWastedMovesBetweenSequences05();
    void testIsPossibleAddWastedMovesBetweenSequences06();
    void testIsPossibleAddWastedMovesBetweenSequences07();
    void testIsPossibleAddWastedMovesBetweenSequences08();
    void testIsPossibleAddWastedMovesBetweenSequences09();


};

#endif
