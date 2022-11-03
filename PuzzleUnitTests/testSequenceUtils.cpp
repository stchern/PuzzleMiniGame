#include "testSequenceUtils.h"
#include "src/SequenceUtils.h"

using namespace InternalUtils::USequence;

void TestSequenceUtils::testHasOverlapping01()
{
    const Sequence rhsSeq(std::vector<unsigned char>({5, 10, 20, 30}), 10);
    const Sequence lhsSeq(std::vector<unsigned char>({10, 20, 30}), 10);
    size_t overlapLength;

    bool value = hasOverlapping(rhsSeq, lhsSeq, overlapLength);
    size_t ansOverlapLength = 3;

    QVERIFY(value);
    QVERIFY(overlapLength == ansOverlapLength);
}

void TestSequenceUtils::testHasOverlapping02()
{
    const Sequence rhsSeq(std::vector<unsigned char>({5, 10, 20, 30}), 10);
    const Sequence lhsSeq(std::vector<unsigned char>({10, 20}), 10);
    size_t overlapLength;

    bool value = hasOverlapping(rhsSeq, lhsSeq, overlapLength);
    size_t ansOverlapLength = 2;

    QVERIFY(value);
    QVERIFY(overlapLength == ansOverlapLength);
}

void TestSequenceUtils::testHasOverlapping03()
{
    const Sequence rhsSeq(std::vector<unsigned char>({5, 10, 10, 20}), 10);
    const Sequence lhsSeq(std::vector<unsigned char>({10, 20, 30}), 10);
    size_t overlapLength;

    bool value = hasOverlapping(rhsSeq, lhsSeq, overlapLength);
    size_t ansOverlapLength = 2;

    QVERIFY(value);
    QVERIFY(overlapLength == ansOverlapLength);
}

void TestSequenceUtils::testHasOverlapping04()
{
    const Sequence rhsSeq(std::vector<unsigned char>({5, 10, 10, 10}), 10);
    const Sequence lhsSeq(std::vector<unsigned char>({10, 20, 30}), 10);
    size_t overlapLength;

    bool value = hasOverlapping(rhsSeq, lhsSeq, overlapLength);
    size_t ansOverlapLength = 1;

    QVERIFY(value);
    QVERIFY(overlapLength == ansOverlapLength);
}

void TestSequenceUtils::testHasOverlapping05()
{
    const Sequence rhsSeq(std::vector<unsigned char>({5, 10, 20, 40}), 10);
    const Sequence lhsSeq(std::vector<unsigned char>({10, 20, 30}), 10);
    size_t overlapLength;

    bool value = hasOverlapping(rhsSeq, lhsSeq, overlapLength);
    size_t ansOverlapLength = 0;

    QVERIFY(!value);
    QVERIFY(overlapLength == ansOverlapLength);
}

void TestSequenceUtils::testHasOverlapping06()
{
    const Sequence rhsSeq(std::vector<unsigned char>({5, 10, 10, 20}), 10);
    const Sequence lhsSeq(std::vector<unsigned char>({5, 20, 30}), 10);
    size_t overlapLength;

    bool value = hasOverlapping(rhsSeq, lhsSeq, overlapLength);
    size_t ansOverlapLength = 0;

    QVERIFY(!value);
    QVERIFY(overlapLength == ansOverlapLength);
}


void TestSequenceUtils::testHasOverlapping07()
{
    const Sequence rhsSeq(std::vector<unsigned char>({5, 10, 10, 20}), 10);
    const Sequence lhsSeq(std::vector<unsigned char>({6, 40, 30}), 10);
    size_t overlapLength;

    bool value = hasOverlapping(rhsSeq, lhsSeq, overlapLength);
    size_t ansOverlapLength = 0;

    QVERIFY(!value);
    QVERIFY(overlapLength == ansOverlapLength);
}
