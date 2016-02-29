#ifndef CANVASWIDGET_H
#define CANVASWIDGET_H

#include "Painting/PaintTool.h"

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

    void setCurrentTool(Painting::PaintTool *tool);

protected:
    bool eventFilter(QObject *obj, QEvent *event);
    void mousePressEvent(QMouseEvent *);

    void resizeEvent(QResizeEvent *);
    void showEvent(QShowEvent *);

private:
    void beginTool(const QPoint &pos);
    void moveTool(const QPoint &pos);
    void endTool();

    void fillCanvasWithPixmap();

private:
    Ui::CanvasWidget *ui;

    bool mIsToolActive;
    QGraphicsScene mScene;
    QRect mBaseRect;
    Painting::Layer *mDisplayLayer;
    Painting::Layer *mPaintLayer;
    QScopedPointer<Painting::PaintTool> mCurrentTool;
};

}

#endif // CANVASWIDGET_H
