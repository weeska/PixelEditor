#include "ToolbarWidget.h"
#include "ui_ToolbarWidget.h"

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
