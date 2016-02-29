#include "ToolbarWidget.h"
#include "ui_ToolbarWidget.h"

#include <QHash>

#include <Painting/CirclePaintTool.h>
#include <Painting/PenPaintTool.h>

using namespace Widgets;

namespace
{
enum ToolType
{
    Pen,
    Circle
};

const QHash<int, QSharedPointer<Painting::PaintTool> > ToolsByType{
    {Pen, QSharedPointer<Painting::PenPaintTool>::create()},
    {Circle, QSharedPointer<Painting::CirclePaintTool>::create()}
};

}

ToolbarWidget::ToolbarWidget(Widgets::CanvasWidget &canvas, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ToolbarWidget),
    mCanvas(canvas)
{
    ui->setupUi(this);

    this->connect(ui->circleButton, SIGNAL(pressed()), &mToolMapper, SLOT(map()));
    this->connect(ui->penButton, SIGNAL(pressed()), &mToolMapper, SLOT(map()));

    mToolMapper.setMapping(ui->circleButton, static_cast<int>(ToolType::Circle));
    mToolMapper.setMapping(ui->penButton, static_cast<int>(ToolType::Pen));

    this->connect(&mToolMapper, SIGNAL(mapped(int)), SLOT(onToolChanged(int)));
}

ToolbarWidget::~ToolbarWidget()
{
    delete ui;
}

void ToolbarWidget::onToolChanged(int toolId)
{
    auto tool = ToolsByType.value(toolId);
    Q_ASSERT(tool);
    if(tool)
    {
        mCanvas.setCurrentTool(tool.data());
    }
}
