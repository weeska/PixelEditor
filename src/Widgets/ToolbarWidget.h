#ifndef TOOLBARWIDGET_H
#define TOOLBARWIDGET_H

#include "CanvasWidget.h"

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

private slots:

    void onToolChanged(int toolId);

private:
    Ui::ToolbarWidget *ui;
    Widgets::CanvasWidget &mCanvas;
    QSignalMapper mToolMapper;
};

}

#endif // TOOLBARWIDGET_H
