#ifndef PAINTING_LAYERPAINTER_H
#define PAINTING_LAYERPAINTER_H

#include "Context.h"
#include "Layer.h"



namespace Painting {

class LayerPainter
{
public:
    LayerPainter(Context &context, Layer &layer);

    /**
     * @brief Initiates a painting operation.
     *
     * Saves the initial state and begins painting
     * operation.
     */
    void begin(const QPoint &position);

    /**
     * @brief Continues/refines a painting operation.
     *
     * Uses the saved state as a basis to paint.
     */
    void move(const QPoint &position);

    /**
     * @brief Ends the painting operation.
     *
     * Ends the operation by drawing the painted
     * pixmap over the inital one.
     */
    void end();

private:
    Context &mContext;
    Layer &mLayer;
    QPixmap mInitialPixmap;
    QPixmap mPaintingPixmap;
};

} // namespace Painting

#endif // PAINTING_LAYERPAINTER_H
