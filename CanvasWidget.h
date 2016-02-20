#ifndef CANVASWIDGET_H
#define CANVASWIDGET_H

#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QPixmap>
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
    void resizeEvent(QResizeEvent *);
    void showEvent(QShowEvent *);

private slots:
    void fillCanvasWithPixmap();

private:
    Ui::CanvasWidget *ui;

    QGraphicsScene mScene;
    QGraphicsPixmapItem *mPixmapItem;

};

#endif // CANVASWIDGET_H
