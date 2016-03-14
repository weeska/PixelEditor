QT       += core gui
CONFIG   += c++11

mingw|gcc: QMAKE_CXXFLAGS += -Wall
msvc: QMAKE_CXXFLAGS += /W3

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = PixelEditor
TEMPLATE = app

PRECOMPILED_HEADER = Stable.h

SOURCES += \
    main.cpp \
    Widgets/CanvasGraphicsView.cpp \
    Widgets/CanvasWidget.cpp \
    Widgets/MainWindow.cpp \
    Widgets/PreviewWidget.cpp \
    Widgets/ToolbarWidget.cpp \
    Painting/CircleTool.cpp \
    Painting/Layer.cpp \
    Painting/FillTool.cpp \
    Painting/LineTool.cpp \
    Painting/PenTool.cpp \
    Painting/Context.cpp \
    Painting/LayerPainter.cpp

HEADERS  += \
    Widgets/MainWindow.h \
    Widgets/ToolbarWidget.h \
    Widgets/CanvasWidget.h \
    Painting/PaintTool.h \
    Widgets/PreviewWidget.h \
    Widgets/CanvasGraphicsView.h \
    Painting/Layer.h \
    Painting/FillTool.h \
    Painting/CircleTool.h \
    Painting/LineTool.h \
    Painting/PenTool.h \
    Painting/Context.h \
    Painting/LayerPainter.h

FORMS += \
    Widgets/MainWindow.ui \
    Widgets/ToolbarWidget.ui \
    Widgets/CanvasWidget.ui \
    Widgets/PreviewWidget.ui

RESOURCES += \
    Resources.qrc
