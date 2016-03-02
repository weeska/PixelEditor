#include "CanvasWidget.h"
#include "ui_CanvasWidget.h"

#include "Painting/PenPaintTool.h"

#include <QDebug>
#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>
#include <QMouseEvent>

using namespace Widgets;

namespace {
const QRect defaultRect(0, 0, 32, 32);
}

CanvasWidget::CanvasWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CanvasWidget),
    mIsToolActive(false),
    mBaseRect(::defaultRect),
    mPaintLayer(nullptr),
    mCurrentTool(new Painting::PenPaintTool)
{
    ui->setupUi(this);

    ui->graphicsView->setScene(&mScene);

    mPaintLayer.reset(new Painting::Layer(::defaultRect.size(), Qt::transparent));
    mDisplayLayer.reset(new Painting::Layer(::defaultRect.size(), Qt::white));

    mDisplayLayer->setZValue(0);
    mPaintLayer->setZValue(1);

    mScene.addItem(mPaintLayer.data());
    mScene.addItem(mDisplayLayer.data());
}

CanvasWidget::~CanvasWidget()
{
    mScene.removeItem(mDisplayLayer.data());
    mScene.removeItem(mPaintLayer.data());
    delete ui;
}

void CanvasWidget::fillCanvasWithPixmap()
{
    ui->graphicsView->fitInView(mBaseRect, Qt::KeepAspectRatio);
}

void CanvasWidget::resizeEvent(QResizeEvent *)
{
    this->fillCanvasWithPixmap();
}

void CanvasWidget::showEvent(QShowEvent *)
{
    this->fillCanvasWithPixmap();
}

void CanvasWidget::setCurrentTool(Painting::PaintTool *tool)
{
    mCurrentTool.reset(tool);
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

void CanvasWidget::mouseReleaseEvent(QMouseEvent *)
{
    mIsToolActive = false;
    this->endTool();
}

void CanvasWidget::mouseMoveEvent(QMouseEvent *event)
{
    if (mIsToolActive) {
        const QPointF itemPosF = ui->graphicsView->mapToScene(static_cast<QMouseEvent*>(event)->pos());
        const QPoint itemPos(std::floor(itemPosF.x()), std::floor(itemPosF.y()));

        this->moveTool(itemPos);
    }
}

void CanvasWidget::beginTool(const QPoint &pos)
{
    auto pixmap = mDisplayLayer->pixmap();

    QPainter painter(&pixmap);
    painter.setBrush(QBrush(QColor(Qt::transparent)));

    mCurrentTool->begin(pos, painter);
    mPaintLayer->setPixmap(pixmap);
}

void CanvasWidget::moveTool(const QPoint &pos)
{
    auto pixmap = mDisplayLayer->pixmap();

    QPainter painter(&pixmap);
    painter.setBrush(QBrush(QColor(Qt::transparent)));

    mCurrentTool->move(pos, painter);
    mPaintLayer->setPixmap(pixmap);
}

void CanvasWidget::endTool()
{
    const auto &paintPixmap = mPaintLayer->pixmap();
    auto displayPixmap = mDisplayLayer->pixmap();

    QPainter painter(&displayPixmap);

    painter.drawPixmap(QPoint(), paintPixmap);
    mDisplayLayer->setPixmap(displayPixmap);
}
