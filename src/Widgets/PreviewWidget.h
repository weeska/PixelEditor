#ifndef WIDGETS_PREVIEWWIDGET_H
#define WIDGETS_PREVIEWWIDGET_H

#include "CanvasWidget.h"

#include <QPixmap>
#include <QWidget>

namespace Widgets {

namespace Ui {
class PreviewWidget;
}

class PreviewWidget : public QWidget
{
    Q_OBJECT

public:
    explicit PreviewWidget(Widgets::CanvasWidget &canvas, QWidget *parent = 0);
    ~PreviewWidget();

public slots:
    void updatePixmap(const QPixmap &pixmap);

private:
    void fillCanvasWithPixmap();

private:
    Ui::PreviewWidget *ui;
    Widgets::CanvasWidget &mCanvas;

    QGraphicsPixmapItem *mPixmapItem;
    QRect mBaseRect;
};


} // namespace Widgets
#endif // WIDGETS_PREVIEWWIDGET_H
