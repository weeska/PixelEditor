#ifndef PAINTING_LINETOOL_H
#define PAINTING_LINETOOL_H

#include "PaintTool.h"

namespace Painting {

class LineTool : public Painting::PaintTool
{
public:
    void begin(const QPoint &point, QPainter &painter, const QPixmap &pixmap);
    void move(const QPoint &point, QPainter &painter, const QPixmap &pixmap);

private:
    QPoint mStart;
};

} // namespace Painting

#endif // PAINTING_LINETOOL_H
