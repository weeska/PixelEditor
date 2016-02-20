#include "CanvasWidget.h"
#include "ui_CanvasWidget.h"

#include <QGraphicsPixmapItem>

CanvasWidget::CanvasWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CanvasWidget),
    mPixmapItem(nullptr)
{
    ui->setupUi(this);

    QPixmap base(64, 64);
    base.fill(Qt::darkBlue);

    //TODO: who owns mPixmapItem?
    mPixmapItem = mScene.addPixmap(base);
    ui->graphicsView->setScene(&mScene);
}

CanvasWidget::~CanvasWidget()
{
    delete ui;
}

void CanvasWidget::fillCanvasWithPixmap()
{
    ui->graphicsView->fitInView(mPixmapItem, Qt::KeepAspectRatio);
}

void CanvasWidget::resizeEvent(QResizeEvent *)
{
    this->fillCanvasWithPixmap();
}


void CanvasWidget::showEvent(QShowEvent *)
{
    this->fillCanvasWithPixmap();
}
