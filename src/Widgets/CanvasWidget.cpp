#include "CanvasWidget.h"
#include "ui_CanvasWidget.h"

#include "Painting/PenPaintTool.h"

#include <QDebug>
#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>
#include <QMouseEvent>

using namespace Widgets;

CanvasWidget::CanvasWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CanvasWidget),
    mIsToolActive(false),
    mBaseRect(0, 0, 32, 32),
    mPaintLayer(nullptr),
    mCurrentTool(new Painting::PenPaintTool)
{
    ui->setupUi(this);

    ui->graphicsView->setScene(&mScene);

    mPaintLayer = new Painting::Layer(QSize(32, 32), Qt::white);
    mScene.addItem(mPaintLayer);

    qApp->installEventFilter(this);
}

CanvasWidget::~CanvasWidget()
{
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

bool CanvasWidget::eventFilter(QObject *obj, QEvent *event)
{
    if (event->type() == QEvent::MouseMove)
    {
        if (obj->objectName() != "Widgets__MainWindowWindow" && obj->objectName() != "ToolBarWindow")
        {
            if (mIsToolActive) {
                const QPointF itemPosF = ui->graphicsView->mapToScene(static_cast<QMouseEvent*>(event)->pos());
                const QPoint itemPos(std::floor(itemPosF.x()), std::floor(itemPosF.y()));

                this->moveTool(itemPos);
            }
        }
    }
    if (event->type () == QEvent::MouseButtonRelease)
    {
        mIsToolActive = false;
        this->endTool();
    }
    return QObject::eventFilter(obj, event);
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
    auto pixmap = mPaintLayer->pixmap();
    QPainter painter(&pixmap);
    painter.setBrush(QBrush(QColor(Qt::blue)));

    mCurrentTool->begin(pos, painter);

    mPaintLayer->setPixmap(pixmap);
}

void CanvasWidget::moveTool(const QPoint &pos)
{
    auto pixmap = mPaintLayer->pixmap();
    QPainter painter(&pixmap);
    painter.setBrush(QBrush(QColor(Qt::blue)));

    mCurrentTool->move(pos, painter);

    mPaintLayer->setPixmap(pixmap);
}

void CanvasWidget::endTool()
{
}

