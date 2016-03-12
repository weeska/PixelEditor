#include "Context.h"

namespace Painting {

const QColor &Context::backgroundColor() const
{
    return mBackgroundColor;
}

void Context::setBackgroundColor(const QColor &backgroundColor)
{
    mBackgroundColor = backgroundColor;
}

const QColor &Context::paintColor() const
{
    return mPaintColor;
}

void Context::setPaintColor(const QColor &paintColor)
{
    mPaintColor = paintColor;
}

} // namespace Painting
