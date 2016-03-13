#ifndef PAINTING_LAYERPAINTER_H
#define PAINTING_LAYERPAINTER_H

#include "Context.h"
#include "Layer.h"



namespace Painting {

class LayerPainter
{
public:
    LayerPainter(Context &context, Layer &layer);

    void begin(const QPoint &position);
    void move(const QPoint &position);
    void end();

private:
    Context &mContext;
    Layer &mLayer;
    QPixmap mInitialPixmap;
    QPixmap mPaintingPixmap;
};

} // namespace Painting

#endif // PAINTING_LAYERPAINTER_H
