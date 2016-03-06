#include "FillTool.h"

#include <qDebug>
#include <QQueue>

void Painting::FillTool::begin(const QPoint &point, QPainter &painter, const QPixmap &pixmap)
{
    QRgb oldColor = pixmap.toImage().pixel(point);
    QRect pixmapRect = pixmap.rect();

    if (QColor(oldColor) == painter.pen().color())
    {
        return;
    }

    QQueue<QPoint> neighbours;
    neighbours.enqueue(point);

    while(!neighbours.isEmpty())
    {
        QPoint currentPoint = neighbours.dequeue();
        if (pixmapRect.contains(currentPoint))
        {
            QRgb currentColor = pixmap.toImage().pixel(currentPoint);
            if (currentColor == oldColor)
            {
                painter.drawPoint(currentPoint);

                neighbours.enqueue(QPoint(currentPoint.x() - 1, currentPoint.y()));
                neighbours.enqueue(QPoint(currentPoint.x() + 1, currentPoint.y()));
                neighbours.enqueue(QPoint(currentPoint.x(), currentPoint.y() - 1));
                neighbours.enqueue(QPoint(currentPoint.x(), currentPoint.y() + 1));
            }
        }
    }
}

void Painting::FillTool::move(const QPoint &point, QPainter &painter, const QPixmap &pixmap)
{
    this->begin(point, painter, pixmap);
}
