#include <QCoreApplication>
#include "PuzzleUnitTests/testPuzzle.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    TestPuzzle test;

    QStringList args;
    args << "" << "-silent";
    QTest::qExec(&test, args);

    return 0;
}
