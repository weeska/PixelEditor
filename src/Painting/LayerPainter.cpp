#include "LayerPainter.h"

namespace Painting {

LayerPainter::LayerPainter(Context &context, Layer &layer)
    : mContext(context)
    , mLayer(layer)
{

}

void LayerPainter::begin(const QPoint &position)
{
    mInitialPixmap = mLayer.pixmap();
    mPaintingPixmap = mLayer.pixmap();

    QPainter painter(&mPaintingPixmap);
    painter.setPen(mContext.paintColor());
    painter.setBrush(QBrush(QColor(Qt::transparent)));

    PaintTool *tool = mContext.paintTool();
    Q_ASSERT(tool);
    if(tool)
    {
        tool->begin(position, painter, mPaintingPixmap);
    }

    mLayer.setPixmap(mPaintingPixmap);
}

void LayerPainter::move(const QPoint &position)
{
    mPaintingPixmap = mInitialPixmap;

    QPainter painter(&mPaintingPixmap);
    painter.setPen(mContext.paintColor());
    painter.setBrush(QBrush(QColor(Qt::transparent)));

    PaintTool *tool = mContext.paintTool();
    Q_ASSERT(tool);
    if(tool)
    {
        tool->move(position, painter, mPaintingPixmap);
    }

    mLayer.setPixmap(mPaintingPixmap);
}

void LayerPainter::end()
{
    mLayer.setPixmap(mPaintingPixmap);
}

} // namespace Painting
