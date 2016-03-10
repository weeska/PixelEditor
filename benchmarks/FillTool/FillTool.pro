TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG += qt core gui

PixelEditorPath = ../../src

INCLUDEPATH += $$PixelEditorPath

SOURCES += main.cpp \
    $$PixelEditorPath/Painting/FillTool.cpp

HEADERS += \
    $$PixelEditorPath/Painting/FillTool.h
