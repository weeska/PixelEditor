#include "Layer.h"

namespace Painting {

Layer::Layer(const QSize &size, const QColor &fillColor, QGraphicsItem *parent)
    : QGraphicsPixmapItem(parent)
    , mPixmap(size)

{
    mPixmap.fill(fillColor);
    this->setPixmap(mPixmap);
}

} // namespace Painting
