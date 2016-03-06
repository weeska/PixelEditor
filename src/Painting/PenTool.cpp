#include "PenTool.h"

using namespace Painting;

void PenTool::drawPoints(QPainter &painter)
{
    painter.drawPoints(mPoints.data(), mPoints.size());
}

void PenTool::begin(const QPoint &point, QPainter &painter, const QPixmap &pixmap)
{
    mPoints.clear();
    this->move(point, painter, pixmap);
}

void PenTool::move(const QPoint &point, QPainter &painter, const QPixmap &pixmap)
{
    Q_UNUSED(pixmap);
    mPoints << point;
    this->drawPoints(painter);
}
