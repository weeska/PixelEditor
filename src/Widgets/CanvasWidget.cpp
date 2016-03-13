#include "CanvasWidget.h"
#include "ui_CanvasWidget.h"

#include "Painting/PenTool.h"

#include <QDebug>
#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>
#include <QMouseEvent>

#include <Painting/LayerPainter.h>

using namespace Widgets;

namespace {
const QRect defaultRect(0, 0, 32, 32);
}

CanvasWidget::CanvasWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CanvasWidget),
    mBaseRect(::defaultRect)
{
    ui->setupUi(this);

    ui->graphicsView->setScene(&mScene);

    this->initLayers();
}

void CanvasWidget::initLayers()
{
    mLayer.reset(new Painting::Layer(::defaultRect.size(), Qt::white));

    mLayer->setZValue(0);

    mScene.addItem(mLayer.data());
}

void CanvasWidget::removeLayers()
{
    mScene.removeItem(mLayer.data());
}

CanvasWidget::~CanvasWidget()
{
    this->removeLayers();
    delete ui;
}

Painting::Context &CanvasWidget::context()
{
    return mContext;
}

void CanvasWidget::clear()
{
    this->removeLayers();
    this->initLayers();
}

QImage CanvasWidget::grabImage() const
{
    return mLayer->pixmap().toImage();
}

void CanvasWidget::initWithImage(const QImage &image)
{
    auto pixmap = QPixmap::fromImage(image);
    mLayer->setPixmap(pixmap);

    mBaseRect.setSize(pixmap.size());
    this->fillCanvasWithPixmap();
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
    mContext.setPaintTool(tool);
}

void CanvasWidget::mousePressEvent(QMouseEvent *event)
{
    if(event->button() != Qt::LeftButton) {
        return;
    }

    const auto itemPosF = ui->graphicsView->mapToScene(event->pos());
    const QPoint itemPos(std::floor(itemPosF.x()), std::floor(itemPosF.y()));

    mCurrentPainter.reset(new Painting::LayerPainter(mContext, *mLayer));
    mCurrentPainter->begin(itemPos);
}

void CanvasWidget::mouseReleaseEvent(QMouseEvent *)
{
    if(mCurrentPainter) {
        mCurrentPainter->end();
        mCurrentPainter.reset();

        emit pixmapChanged(mLayer->pixmap());
    }
}

void CanvasWidget::mouseMoveEvent(QMouseEvent *event)
{
    if (mCurrentPainter) {
        const auto itemPosF = ui->graphicsView->mapToScene(static_cast<QMouseEvent*>(event)->pos());
        const QPoint itemPos(std::floor(itemPosF.x()), std::floor(itemPosF.y()));

        mCurrentPainter->move(itemPos);
    }
}
