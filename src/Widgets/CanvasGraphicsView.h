#ifndef WIDGETS_CANVASGRAPHICSVIEW_H
#define WIDGETS_CANVASGRAPHICSVIEW_H

#include <QGraphicsView>

namespace Widgets {

class CanvasGraphicsView : public QGraphicsView
{
public:
    explicit CanvasGraphicsView(QWidget *parent = 0);

protected:
    void mouseMoveEvent(QMouseEvent *);
    void mouseReleaseEvent(QMouseEvent *);
};

} // namespace Widgets

#endif // WIDGETS_CANVASGRAPHICSVIEW_H
