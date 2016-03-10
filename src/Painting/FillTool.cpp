#include "FillTool.h"

#include <qDebug>
#include <QQueue>

void Painting::FillTool::begin(const QPoint &point, QPainter &painter, const QPixmap &pixmap)
{
    QImage image = pixmap.toImage();
    const QRect pixmapRect = pixmap.rect();

    const QRgb oldColor = image.pixel(point);
    const QRgb newColor = painter.pen().color().rgb();

    if (oldColor == newColor)
    {
        return;
    }

    QQueue<QPoint> neighbours;
    neighbours.enqueue(point);

    while(!neighbours.isEmpty())
    {
        const QPoint currentPoint = neighbours.dequeue();
        if (pixmapRect.contains(currentPoint))
        {
            const QRgb currentColor = image.pixel(currentPoint);
            if (currentColor == oldColor)
            {
                image.setPixel(currentPoint, newColor);

                neighbours.enqueue(QPoint(currentPoint.x() - 1, currentPoint.y()));
                neighbours.enqueue(QPoint(currentPoint.x() + 1, currentPoint.y()));
                neighbours.enqueue(QPoint(currentPoint.x(), currentPoint.y() - 1));
                neighbours.enqueue(QPoint(currentPoint.x(), currentPoint.y() + 1));
            }
        }
    }
    painter.drawImage(QPoint(), image);
}

void Painting::FillTool::move(const QPoint &point, QPainter &painter, const QPixmap &pixmap)
{
    this->begin(point, painter, pixmap);
}
