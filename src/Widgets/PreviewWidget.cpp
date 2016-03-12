#include "PreviewWidget.h"
#include "ui_PreviewWidget.h"

namespace Widgets {

PreviewWidget::PreviewWidget(Widgets::CanvasWidget &canvas, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PreviewWidget),
    mCanvas(canvas),
    mPixmapItem(nullptr)
{
    ui->setupUi(this);

    QGraphicsScene *scene = new QGraphicsScene();
    ui->previewView->setScene(scene);
    mPixmapItem = scene->addPixmap(QPixmap());
}

PreviewWidget::~PreviewWidget()
{
    delete ui;
}

void PreviewWidget::updatePixmap(const QPixmap &pixmap)
{
    mPixmapItem->setPixmap(pixmap);

    mBaseRect.setSize(pixmap.size());
    this->fillCanvasWithPixmap();
}

void PreviewWidget::fillCanvasWithPixmap()
{
    ui->previewView->fitInView(mBaseRect, Qt::KeepAspectRatio);
}

} // namespace Widgets
