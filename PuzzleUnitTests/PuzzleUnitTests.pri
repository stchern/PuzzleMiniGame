!INPAINTING_UNIT_TEST_PRI{
CONFIG += INPAINTING_UNIT_TEST_PRI    

INCLUDEPATH *= $$clean_path($$PWD/../)

include($$PWD/../Puzzle/Puzzle.pri)

HEADERS += \
    $$PWD/testMatrixUtils.h \
    $$PWD/testUtils.h \


SOURCES += \
    $$PWD/testMatrixUtils.cpp \
    $$PWD/testUtils.cpp \
}

HEADERS += \
    $$PWD/testPathUtils.h \
    $$PWD/testPositionUtils.h \
    $$PWD/testSearch.h \
    $$PWD/testSequenceUtils.h \
    $$PWD/utils.h

SOURCES += \
    $$PWD/testPathUtils.cpp \
    $$PWD/testPositionUtils.cpp \
    $$PWD/testSearch.cpp \
    $$PWD/testSequenceUtils.cpp
