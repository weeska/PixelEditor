#include "CanvasGraphicsView.h"
#include <QEvent>
#include <QDebug>
#include <QMouseEvent>

namespace Widgets {

CanvasGraphicsView::CanvasGraphicsView(QWidget *parent) :  QGraphicsView(parent)
{
}

void Widgets::CanvasGraphicsView::mouseMoveEvent(QMouseEvent *event)
{
    event->ignore();
}

void CanvasGraphicsView::mouseReleaseEvent(QMouseEvent *event)
{
    event->ignore();
}

} // namespace Widgets


