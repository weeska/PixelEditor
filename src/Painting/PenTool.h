#ifndef PENTOOL_H
#define PENTOOL_H

#include "PaintTool.h"

#include <QPainterPath>

namespace Painting {

/**
 * @brief Paints individual pixels.
 */

class PenTool : public PaintTool
{
public:
    void begin(const QPoint &point, QPainter &painter, const QPixmap &pixmap);
    void move(const QPoint &point, QPainter &painter, const QPixmap &pixmap);

private:
    void drawPoints(QPainter &painter);

private:
    QVector<QPoint> mPoints;
};

}

#endif // PENTOOL_H
