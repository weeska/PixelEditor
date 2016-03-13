#ifndef CANVASWIDGET_H
#define CANVASWIDGET_H

#include "Painting/PaintTool.h"

#include <QColor>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QPixmap>
#include <QScopedPointer>
#include <QWidget>

#include <Painting/Context.h>
#include <Painting/Layer.h>
#include <Painting/LayerPainter.h>
#include <Painting/PaintTool.h>

namespace Widgets {

namespace Ui {
class CanvasWidget;
}

class CanvasWidget : public QWidget
{
    Q_OBJECT

public:
    explicit CanvasWidget(QWidget *parent = 0);
    ~CanvasWidget();

    Painting::Context &context();

    /// Resets the canvas to its default color
    void clear();

    QImage grabImage() const;
    void initWithImage(const QImage &image);

    /// Sets the tool that is used to paint
    void setCurrentTool(Painting::PaintTool *tool);

signals:
    void pixmapChanged(const QPixmap &pixmap);

protected:
    void mousePressEvent(QMouseEvent *);
    void mouseReleaseEvent(QMouseEvent *);
    void mouseMoveEvent(QMouseEvent *);

    void resizeEvent(QResizeEvent *);
    void showEvent(QShowEvent *);

private:
    void fillCanvasWithPixmap();
    void removeLayers();
    void initLayers();

private:
    Ui::CanvasWidget *ui;

    QRect mBaseRect;
    Painting::Context mContext;
    QGraphicsScene mScene;

    QScopedPointer<Painting::Layer> mLayer;
    QScopedPointer<Painting::LayerPainter> mCurrentPainter;
};

}

#endif // CANVASWIDGET_H
