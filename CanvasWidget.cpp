#include "CanvasWidget.h"
#include "ui_CanvasWidget.h"

#include <QDebug>
#include <QGraphicsPixmapItem>
#include <QMouseEvent>

CanvasWidget::CanvasWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CanvasWidget),
    mPixmapItem(nullptr)
{
    ui->setupUi(this);

    QPixmap base(32, 32);
    base.fill(Qt::white);

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

void CanvasWidget::mousePressEvent(QMouseEvent *event)
{
    if(event->button() != Qt::LeftButton)
    {
        return;
    }
    const QPointF itemPosF = ui->graphicsView->mapToScene(event->pos());
    const QPoint itemPos(std::floor(itemPosF.x()), std::floor(itemPosF.y()));
    auto pixmap = mPixmapItem->pixmap();

    QPainter painter(&pixmap);
    painter.setBrush(QBrush(QColor(Qt::blue)));
    painter.drawPoint(itemPos);

    mPixmapItem->setPixmap(pixmap);
}

void CanvasWidget::mouseReleaseEvent(QMouseEvent *)
{
}

void CanvasWidget::mouseMoveEvent(QMouseEvent *)
{
}
