QT       += core gui
CONFIG   += c++11

mingw|gcc: QMAKE_CXXFLAGS += -Wall
msvc: QMAKE_CXXFLAGS += /W3

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = PixelEditor
TEMPLATE = app

SOURCES += \
    main.cpp \
    Widgets/MainWindow.cpp \
    Widgets/ToolbarWidget.cpp \
    Widgets/CanvasWidget.cpp \
    Painting/Layer.cpp \
    Widgets/CanvasGraphicsView.cpp \
    Painting/FillTool.cpp \
    Painting/CircleTool.cpp \
    Painting/LineTool.cpp \
    Painting/PenTool.cpp

HEADERS  += \
    Widgets/MainWindow.h \
    Widgets/ToolbarWidget.h \
    Widgets/CanvasWidget.h \
    Painting/PaintTool.h \
    Painting/Layer.h \
    Widgets/CanvasGraphicsView.h \
    Painting/FillTool.h \
    Painting/CircleTool.h \
    Painting/LineTool.h \
    Painting/PenTool.h

FORMS += \
    Widgets/MainWindow.ui \
    Widgets/ToolbarWidget.ui \
    Widgets/CanvasWidget.ui

RESOURCES += \
    Resources.qrc
