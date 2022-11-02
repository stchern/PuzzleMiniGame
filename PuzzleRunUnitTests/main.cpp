#include <QCoreApplication>
#include "PuzzleUnitTests/testUtils.h"
#include "PuzzleUnitTests/testInternalUtils.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    TestUtils testUtils;
    TestInternalUtils testInternalUtils;

    QStringList args;
    args << "" << "-silent";
    QTest::qExec(&testUtils, args);
    QTest::qExec(&testInternalUtils, args);

    return 0;
}
