!PUZZLE_SRC_PRI{
CONFIG += PUZZLE_SRC_PRI

INCLUDEPATH *= $$clean_path($$PWD/../)

SOURCES += \
        $$PWD/Matrix.cpp \
        $$PWD/Path.cpp \
        $$PWD/PathFinder.cpp \
        $$PWD/Position.cpp \
        $$PWD/Sequence.cpp \
        $$PWD/Utils.cpp \
        $$PWD/Search.cpp \
        $$PWD/MatrixUtils.cpp \
        $$PWD/PathUtils.cpp \
        $$PWD/PositionUtils.cpp \
        $$PWD/SequenceUtils.cpp \


HEADERS += \
    $$PWD/Common.h \
    $$PWD/InvalidArgumentError.h \
    $$PWD/Matrix.h \
    $$PWD/Path.h \
    $$PWD/PathFinder.h \
    $$PWD/PathNotFoundError.h \
    $$PWD/Position.h \
    $$PWD/Sequence.h \
    $$PWD/Utils.h \
    $$PWD/Search.h \
    $$PWD/MatrixUtils.h \
    $$PWD/PathUtils.h \
    $$PWD/PositionUtils.h \
    $$PWD/SequenceUtils.h

}
