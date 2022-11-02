QT += testlib

CONFIG += c++17 console
CONFIG -= app_bundle

include($$PWD/../PuzzleUnitTests/PuzzleUnitTests.pri)

SOURCES += \
        main.cpp
