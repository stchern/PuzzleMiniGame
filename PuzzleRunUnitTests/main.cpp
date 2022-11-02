#include <QCoreApplication>
#include "PuzzleUnitTests/testUtils.h"
#include "PuzzleUnitTests/testMatrixUtils.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    TestUtils testUtils;
    TestMatrixUtils testMatrixUtils;

    QStringList args;
    args << "" << "-silent";
    QTest::qExec(&testUtils, args);
    QTest::qExec(&testMatrixUtils, args);

    return 0;
}
