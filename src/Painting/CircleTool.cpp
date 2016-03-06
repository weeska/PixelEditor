#include "CircleTool.h"

#include <QPainter>

namespace Painting {

void CircleTool::begin(const QPoint &point, QPainter &painter, const QPixmap &pixmap)
{
    mStart = point;
    this->move(mStart, painter, pixmap);
}

void CircleTool::move(const QPoint &point, QPainter &painter, const QPixmap &pixmap)
{
    Q_UNUSED(pixmap);
    painter.drawEllipse(QRect(mStart, point));
}

} // namespace Painting
