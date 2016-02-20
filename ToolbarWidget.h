#ifndef TOOLBARWIDGET_H
#define TOOLBARWIDGET_H

#include <QWidget>

namespace Ui {
class ToolbarWidget;
}

class ToolbarWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ToolbarWidget(QWidget *parent = 0);
    ~ToolbarWidget();

private:
    Ui::ToolbarWidget *ui;
};

#endif // TOOLBARWIDGET_H
