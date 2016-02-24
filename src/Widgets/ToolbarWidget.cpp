#include "ToolbarWidget.h"
#include "ui_ToolbarWidget.h"

using namespace Widgets;

ToolbarWidget::ToolbarWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ToolbarWidget)
{
    ui->setupUi(this);
}

ToolbarWidget::~ToolbarWidget()
{
    delete ui;
}
