#include "PenPaintTool.h"

using namespace Painting;

void PenPaintTool::drawPoints(QPainter &painter)
{
    painter.drawPoints(mPoints.data(), mPoints.size());
}

void PenPaintTool::begin(const QPoint &point, QPainter &painter)
{
    mPoints.clear();
    this->move(point, painter);
}

void PenPaintTool::move(const QPoint &point, QPainter &painter)
{
    mPoints << point;
    this->drawPoints(painter);
}
