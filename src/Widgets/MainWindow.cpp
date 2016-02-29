#include "ToolbarWidget.h"

#include "MainWindow.h"
#include "ui_MainWindow.h"

#include <QDockWidget>

using namespace Widgets;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->initializeToolWidget();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initializeToolWidget()
{
    auto toolsDock = new QDockWidget("Tools", this);
    toolsDock->setWidget(new ToolbarWidget(*ui->centralWidget, toolsDock));

    this->addDockWidget(Qt::LeftDockWidgetArea, toolsDock);

}
