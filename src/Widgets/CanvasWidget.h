#ifndef CANVASWIDGET_H
#define CANVASWIDGET_H

#include "Painting/PaintTool.h"

#include <QColor>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QPixmap>
#include <QScopedPointer>
#include <QWidget>

#include <Painting/Layer.h>
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

    /// Resets the canvas to its default color
    void clear();

    QImage grabImage() const;
    void initWithImage(const QImage &image);

    /// Sets the tool that is used to paint
    void setCurrentTool(Painting::PaintTool *tool);
    /// Sets the outline color that is used to paint
    void setPaintColor(const QColor &currentColor);
    void setBackgroundColor(const QColor &backgroundColor);

protected:
    void mousePressEvent(QMouseEvent *);
    void mouseReleaseEvent(QMouseEvent *);
    void mouseMoveEvent(QMouseEvent *);

    void resizeEvent(QResizeEvent *);
    void showEvent(QShowEvent *);

private:
    void beginTool(const QPoint &pos);
    void moveTool(const QPoint &pos);
    void endTool();

    void fillCanvasWithPixmap();
    void removeLayers();
    void initLayers();

private:
    Ui::CanvasWidget *ui;

    bool mIsToolActive;
    QGraphicsScene mScene;
    QRect mBaseRect;
    QScopedPointer<Painting::Layer> mDisplayLayer;
    QScopedPointer<Painting::Layer> mPaintLayer;
    Painting::PaintTool *mCurrentTool;

    /* TODO: both colors are also in Toolbar, move them to a context? */
    QColor mPaintColor;
    QColor mBackgroundColor;
};

}

#endif // CANVASWIDGET_H
