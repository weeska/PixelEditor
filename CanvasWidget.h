#ifndef CANVASWIDGET_H
#define CANVASWIDGET_H

#include "PaintTool.h"

#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QPixmap>
#include <QScopedPointer>
#include <QWidget>

namespace Ui {
class CanvasWidget;
}

class CanvasWidget : public QWidget
{
    Q_OBJECT

public:
    explicit CanvasWidget(QWidget *parent = 0);
    ~CanvasWidget();

protected:
    void mousePressEvent(QMouseEvent *);

    void resizeEvent(QResizeEvent *);
    void showEvent(QShowEvent *);

private:
    void beginTool(const QPoint &pos);
    void moveTool(const QPoint &pos);
    void endTool();

private slots:
    void fillCanvasWithPixmap();

private:
    Ui::CanvasWidget *ui;

    QGraphicsScene mScene;
    QGraphicsPixmapItem *mPixmapItem;

    bool mIsToolActive;
    QScopedPointer<PaintTool> mCurrentTool;
};

#endif // CANVASWIDGET_H
