#include "LineTool.h"

namespace Painting {

void LineTool::begin(const QPoint &point, QPainter &painter, const QPixmap &pixmap)
{
    mStart = point;
    this->move(point, painter, pixmap);
}

void LineTool::move(const QPoint &point, QPainter &painter, const QPixmap &pixmap)
{
    Q_UNUSED(pixmap);
    painter.drawLine(mStart,point);
}

} // namespace Painting
