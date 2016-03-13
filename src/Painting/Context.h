#ifndef PAINTING_CONTEXT_H
#define PAINTING_CONTEXT_H

#include "PaintTool.h"

#include <QColor>

namespace Painting {

class Context
{
public:

    const QColor &backgroundColor() const;
    const QColor &paintColor() const;

    void setBackgroundColor(const QColor &backgroundColor);
    void setPaintColor(const QColor &paintColor);

    PaintTool *paintTool() const;
    void setPaintTool(PaintTool *paintTool);

private:
    PaintTool *mPaintTool;
    QColor mPaintColor;
    QColor mBackgroundColor;
};

} // namespace Painting

#endif // PAINTING_CONTEXT_H
