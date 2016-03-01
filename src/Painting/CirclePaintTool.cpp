#include "CirclePaintTool.h"

#include <QPainter>

namespace Painting {

void CirclePaintTool::begin(const QPoint &point, QPainter &painter)
{
    mStart = point;
    this->move(mStart, painter);
}

void CirclePaintTool::move(const QPoint &point, QPainter &painter)
{
    painter.drawEllipse(QRect(mStart, point));
}

} // namespace Painting
