#include "PenPaintTool.h"

using namespace Painting;

void PenPaintTool::begin(const QPoint &point, QPainter &painter)
{
    painter.drawPoint(point);
}

void PenPaintTool::move(const QPoint &point, QPainter &painter)
{
    painter.drawPoint(point);
}
