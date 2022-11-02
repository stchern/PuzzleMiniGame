QT -= gui

CONFIG += c++11 console
CONFIG -= app_bundle

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        ../src/Matrix.cpp \
        ../src/Path.cpp \
        ../src/PathFinder.cpp \
        ../src/Position.cpp \
        ../src/Sequence.cpp \
        ../src/Utils.cpp \
        ../src/InternalUtils.cpp

HEADERS += \
    ../src/Common.h \
    ../src/InvalidArgumentError.h \
    ../src/Matrix.h \
    ../src/Path.h \
    ../src/PathFinder.h \
    ../src/PathNotFoundError.h \
    ../src/Position.h \
    ../src/Sequence.h \
    ../src/Utils.h \
    ../src/InternalUtils.h
