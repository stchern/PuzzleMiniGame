#ifndef PUZZLE_INTERNAL_UTILS_TEST_H
#define PUZZLE_INTERNAL_UTILS_TEST_H

#include <QTest>

class TestMatrixUtils: public QObject{

    Q_OBJECT
public:

    explicit TestMatrixUtils(QObject *parent = 0): QObject(parent){
    };


private slots:

    void testIsFoundInRow01();
    void testIsFoundInRow02();
    void testIsFoundInRow03();
    void testIsFoundInRow04();
    void testIsFoundInRow05();

    void testIsFoundInCol01();
    void testIsFoundInCol02();
    void testIsFoundInCol03();

    void testCreateIsVisitedMatrix01();

    void testSetVisitedPositions01();
};

#endif
