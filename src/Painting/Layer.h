#ifndef PAINTING_LAYER_H
#define PAINTING_LAYER_H

#include <QGraphicsPixmapItem>

namespace Painting {

class Layer : public QGraphicsPixmapItem
{
public:
    Layer(const QSize &size,
          const QColor &fillColor,
          QGraphicsItem *parent = nullptr);

private:
    QPixmap mPixmap;
};

} // namespace Painting

#endif // PAINTING_LAYER_H
