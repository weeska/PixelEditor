#-------------------------------------------------
#
# Project created by QtCreator 2016-02-20T20:50:55
#
#-------------------------------------------------

QT       += core gui
CONFIG   += c++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = PixelEditor
TEMPLATE = app


SOURCES += main.cpp\
        MainWindow.cpp \
    ToolbarWidget.cpp \
    CanvasWidget.cpp \
    PenPaintTool.cpp

HEADERS  += MainWindow.h \
    ToolbarWidget.h \
    CanvasWidget.h \
    PaintTool.h \
    PenPaintTool.h

FORMS    += MainWindow.ui \
    ToolbarWidget.ui \
    CanvasWidget.ui
