#ifndef PAINTTOOL_H
#define PAINTTOOL_H

#include <QPainter>
#include <QPoint>

namespace Painting {

class PaintTool
{
public:
    virtual ~PaintTool() {}

    virtual void begin(const QPoint &point, QPainter &painter) = 0;
    virtual void move(const QPoint &point, QPainter &painter) = 0;
};

}

#endif // PAINTTOOL_H
