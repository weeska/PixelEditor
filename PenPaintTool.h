#ifndef PENPAINTTOOL_H
#define PENPAINTTOOL_H

#include "PaintTool.h"

class PenPaintTool : public PaintTool
{
public:
    void begin(const QPoint &point, QPainter &painter);
    void move(const QPoint &point, QPainter &painter);
};

#endif // PENPAINTTOOL_H
