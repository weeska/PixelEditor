#include "CirclePaintTool.h"

#include <QPainter>

namespace Painting {

void CirclePaintTool::begin(const QPoint &point, QPainter &painter)
{
    mStart = point;
    painter.drawEllipse(point, 1, 1);
}

void CirclePaintTool::move(const QPoint &point, QPainter &painter)
{
    painter.drawEllipse(QRect(mStart, point));
}

} // namespace Painting
