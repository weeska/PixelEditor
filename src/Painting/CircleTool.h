#ifndef PAINTING_CIRCLETOOL_H
#define PAINTING_CIRCLETOOL_H

#include "PaintTool.h"

namespace Painting {

/**
 * @brief Paints a cirle.
 *
 * The circle is painted inside the bounding box of the mouse movement.
 */

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
