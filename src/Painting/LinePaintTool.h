#ifndef PAINTING_LINEPAINTTOOL_H
#define PAINTING_LINEPAINTTOOL_H

#include "PaintTool.h"

namespace Painting {

class LinePaintTool : public Painting::PaintTool
{
public:
    void begin(const QPoint &point, QPainter &painter);
    void move(const QPoint &point, QPainter &painter);

private:
    QPoint mStart;
};

} // namespace Painting

#endif // PAINTING_LINEPAINTTOOL_H
