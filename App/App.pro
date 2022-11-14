QT -= gui

CONFIG += c++17 console
CONFIG -= app_bundle

INCLUDEPATH *= $$clean_path($$PWD/../)

include($$PWD/../src/Puzzle.pri)

SOURCES += \
        $$PWD/Application.cpp \
        $$PWD/main.cpp


HEADERS += \
    $$PWD/Application.h
