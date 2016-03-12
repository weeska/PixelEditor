#ifndef FILLTOOL_H
#define FILLTOOL_H

#include "PaintTool.h"

namespace Painting {

/**
 * @brief Paints an area in a color.
 *
 * Beginning from the mouse position, the image is filled with a color
 * until there is a boundary.
 */

class FillTool : public PaintTool
{
public:
    void begin(const QPoint &point, QPainter &painter, const QPixmap &pixmap);
    void move(const QPoint &point, QPainter &painter, const QPixmap &pixmap);
};

} // namespace Painting

#endif // FILLTOOL_H
