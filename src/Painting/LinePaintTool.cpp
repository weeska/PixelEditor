#include "LinePaintTool.h"

namespace Painting {

void LinePaintTool::begin(const QPoint &point, QPainter &painter)
{
    mStart = point;
    this->move(point, painter);
}

void LinePaintTool::move(const QPoint &point, QPainter &painter)
{
    painter.drawLine(mStart,point);
}

} // namespace Painting
