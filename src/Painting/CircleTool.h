#ifndef PAINTING_CIRCLETOOL_H
#define PAINTING_CIRCLETOOL_H

#include "PaintTool.h"

namespace Painting {

class CircleTool : public Painting::PaintTool
{
public:
    void begin(const QPoint &point, QPainter &painter, const QPixmap &pixmap);
    void move(const QPoint &point, QPainter &painter, const QPixmap &pixmap);

private:
    QPoint mStart;
};

} // namespace Painting

#endif // PAINTING_CIRCLETOOL_H
