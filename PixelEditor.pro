QT       += core gui
CONFIG   += c++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = PixelEditor
TEMPLATE = app

SOURCES += \
    main.cpp \
    Widgets/MainWindow.cpp \
    Widgets/ToolbarWidget.cpp \
    Widgets/CanvasWidget.cpp \
    Painting/PenPaintTool.cpp

HEADERS  += \
    Widgets/MainWindow.h \
    Widgets/ToolbarWidget.h \
    Widgets/CanvasWidget.h \
    Painting/PaintTool.h \
    Painting/PenPaintTool.h

FORMS += \
    Widgets/MainWindow.ui \
    Widgets/ToolbarWidget.ui \
    Widgets/CanvasWidget.ui

RESOURCES += \
    Resources.qrc
