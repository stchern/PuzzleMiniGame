!INPAINTING_UNIT_TEST_PRI{
CONFIG += INPAINTING_UNIT_TEST_PRI    

INCLUDEPATH *= $$clean_path($$PWD/../)

include($$PWD/../Puzzle/Puzzle.pri)

HEADERS += \
    $$PWD/testInternalUtils.h \
    $$PWD/testUtils.h \


SOURCES += \
    $$PWD/testInternalUtils.cpp \
    $$PWD/testUtils.cpp \
}
