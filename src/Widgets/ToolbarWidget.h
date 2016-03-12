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

    void setPaintColor(const QColor &paintColor);
    void setBackgroundColor(const QColor &backgroundColor);

private slots:
    void onToolChanged(int toolId);
    void onPaintColorButtonPressed();
    void onBackgroundColorButtonPressed();

private:
    void updatePaintColorLabel();
    void updateBackgroundColorLabel();

private:
    Ui::ToolbarWidget *ui;
    Widgets::CanvasWidget &mCanvas;
    QSignalMapper mToolMapper;

    QColor mPaintColor;
    QColor mBackgroundColor;
};

}

#endif // TOOLBARWIDGET_H
