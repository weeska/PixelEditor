#ifndef PAINTING_CONTEXT_H
#define PAINTING_CONTEXT_H

#include <QColor>

namespace Painting {

class Context
{
public:
    const QColor &backgroundColor() const;
    const QColor &paintColor() const;

    void setBackgroundColor(const QColor &backgroundColor);
    void setPaintColor(const QColor &paintColor);

private:
    QColor mPaintColor;
    QColor mBackgroundColor;
};

} // namespace Painting

#endif // PAINTING_CONTEXT_H
