#ifndef PAINTTOOL_H
#define PAINTTOOL_H

#include <QPainter>
#include <QPoint>

namespace Painting {

/**
 * @brief Interface class for a painting tool.
 */

class PaintTool
{
public:
    virtual ~PaintTool() {}

    /**
     * @brief Called when painting with a tool is initiated.
     */
    virtual void begin(const QPoint &point, QPainter &painter, const QPixmap &pixmap) = 0;

    /**
     * @brief Called when painting with a tool goes on.
     *
     * @note There is no method to end a painting operation. It's assumed that each both drawing
     * function complete their respective operations within the call.
     */
    virtual void move(const QPoint &point, QPainter &painter, const QPixmap &pixmap) = 0;
};

}

#endif // PAINTTOOL_H
