#ifndef TOOLBARWIDGET_H
#define TOOLBARWIDGET_H

#include "CanvasWidget.h"

#include <QColor>
#include <QSignalMapper>
#include <QWidget>

namespace Widgets {

namespace Ui {
class ToolbarWidget;
}

class ToolbarWidget : public QWidget
{
    Q_OBJECT

public:
    ToolbarWidget(Widgets::CanvasWidget &widget, QWidget *parent = 0);
    ~ToolbarWidget();
    void setColor(const QColor &currentColor);

private slots:
    void onCurrentColorButtonPressed();
    void onToolChanged(int toolId);

private:
    void updateColor();

private:
    Ui::ToolbarWidget *ui;
    Widgets::CanvasWidget &mCanvas;
    QSignalMapper mToolMapper;

    QColor mCurrentColor;
};

}

#endif // TOOLBARWIDGET_H
