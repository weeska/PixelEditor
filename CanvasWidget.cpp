#include "CanvasWidget.h"
#include "PenPaintTool.h"

#include "ui_CanvasWidget.h"

#include <QDebug>
#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>
#include <QMouseEvent>

CanvasWidget::CanvasWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CanvasWidget),
    mPixmapItem(nullptr),
    mIsToolActive(false),
    mCurrentTool(new PenPaintTool)
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

    Q_ASSERT(mCurrentTool);
    if(!mCurrentTool)
    {
        return;
    }

    mIsToolActive = true;

    const QPointF itemPosF = ui->graphicsView->mapToScene(event->pos());
    const QPoint itemPos(std::floor(itemPosF.x()), std::floor(itemPosF.y()));

    this->beginTool(itemPos);

}

void CanvasWidget::beginTool(const QPoint &pos)
{
    auto pixmap = mPixmapItem->pixmap();
    QPainter painter(&pixmap);
    painter.setBrush(QBrush(QColor(Qt::blue)));

    mCurrentTool->begin(pos, painter);

    mPixmapItem->setPixmap(pixmap);
}

void CanvasWidget::moveTool(const QPoint &pos)
{
    auto pixmap = mPixmapItem->pixmap();
    QPainter painter(&pixmap);
    painter.setBrush(QBrush(QColor(Qt::blue)));

    mCurrentTool->move(pos, painter);

    mPixmapItem->setPixmap(pixmap);
}

