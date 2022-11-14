!PUZZLE_UNIT_TEST_PRI{
CONFIG += PUZZLE_UNIT_TEST_PRI

INCLUDEPATH *= $$clean_path($$PWD/../)

include($$PWD/../src/Puzzle.pri)

HEADERS += \
    $$PWD/testMatrixUtils.h \
    $$PWD/testUtils.h \
    $$PWD/testPathUtils.h \
    $$PWD/testPositionUtils.h \
    $$PWD/testSearch.h \
    $$PWD/testSequenceUtils.h \
    $$PWD/utils.h


SOURCES += \
    $$PWD/testMatrixUtils.cpp \
    $$PWD/testUtils.cpp \
    $$PWD/testPathUtils.cpp \
    $$PWD/testPositionUtils.cpp \
    $$PWD/testSearch.cpp \
    $$PWD/testSequenceUtils.cpp

}
