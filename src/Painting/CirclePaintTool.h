#ifndef PAINTING_CIRCLEPAINTTOOL_H
#define PAINTING_CIRCLEPAINTTOOL_H

#include "PaintTool.h"

namespace Painting {

class CirclePaintTool : public Painting::PaintTool
{
public:
    void begin(const QPoint &point, QPainter &painter);
    void move(const QPoint &point, QPainter &painter);

private:
    QPoint mStart;
};

} // namespace Painting

#endif // PAINTING_CIRCLEPAINTTOOL_H
