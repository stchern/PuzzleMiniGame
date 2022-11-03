#include <QCoreApplication>
#include "PuzzleUnitTests/testUtils.h"
#include "PuzzleUnitTests/testPathUtils.h"
#include "PuzzleUnitTests/testMatrixUtils.h"
#include "PuzzleUnitTests/testSequenceUtils.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    TestUtils testUtils;
    TestMatrixUtils testMatrixUtils;
    TestSequenceUtils testSequenceUtils;
    TestPathUtils testPathUtils;

    QStringList args;
    args << "" << "-silent";
//    QTest::qExec(&testUtils, args);
//    QTest::qExec(&testMatrixUtils, args);
//    QTest::qExec(&testSequenceUtils, args);
    QTest::qExec(&testPathUtils, args);

    return 0;
}
