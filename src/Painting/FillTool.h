#ifndef FILLTOOL_H
#define FILLTOOL_H

#include "PaintTool.h"

namespace Painting {

class FillTool : public PaintTool
{
public:
    void begin(const QPoint &point, QPainter &painter, const QPixmap &pixmap);
    void move(const QPoint &point, QPainter &painter, const QPixmap &pixmap);
};

} // namespace Painting

#endif // FILLTOOL_H
