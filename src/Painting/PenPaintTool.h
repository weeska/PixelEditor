#ifndef PENPAINTTOOL_H
#define PENPAINTTOOL_H

#include "PaintTool.h"

#include <QPainterPath>

namespace Painting {

class PenPaintTool : public PaintTool
{
public:
    void begin(const QPoint &point, QPainter &painter);
    void move(const QPoint &point, QPainter &painter);

private:
    void drawPoints(QPainter &painter);

private:
    QVector<QPoint> mPoints;
};

}

#endif // PENPAINTTOOL_H
