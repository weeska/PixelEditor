#include "ToolbarWidget.h"
#include "ui_ToolbarWidget.h"

#include <QHash>
#include <QIcon>
#include <QDebug>
#include <QColorDialog>

#include <Painting/CircleTool.h>
#include <Painting/LineTool.h>
#include <Painting/PenTool.h>
#include <Painting/FillTool.h>

using namespace Widgets;

namespace
{
enum ToolType
{
    Pen,
    Circle,
    Line,
    Fill
};

const QHash<int, QSharedPointer<Painting::PaintTool> > ToolsByType{
    {Pen, QSharedPointer<Painting::PenTool>::create()},
    {Circle, QSharedPointer<Painting::CircleTool>::create()},
    {Line, QSharedPointer<Painting::LineTool>::create()},
    {Fill, QSharedPointer<Painting::FillTool>::create()}
};

}

ToolbarWidget::ToolbarWidget(Widgets::CanvasWidget &canvas, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ToolbarWidget),
    mCanvas(canvas),
    mCurrentColor(Qt::black)
{
    ui->setupUi(this);

    this->connect(ui->circleButton, SIGNAL(pressed()), &mToolMapper, SLOT(map()));
    this->connect(ui->lineButton, SIGNAL(pressed()), &mToolMapper, SLOT(map()));
    this->connect(ui->penButton, SIGNAL(pressed()), &mToolMapper, SLOT(map()));
    this->connect(ui->fillButton, SIGNAL(pressed()), &mToolMapper, SLOT(map()));

    mToolMapper.setMapping(ui->circleButton, static_cast<int>(ToolType::Circle));
    mToolMapper.setMapping(ui->lineButton, static_cast<int>(ToolType::Line));
    mToolMapper.setMapping(ui->penButton, static_cast<int>(ToolType::Pen));
    mToolMapper.setMapping(ui->fillButton, static_cast<int>(ToolType::Fill));

    this->connect(&mToolMapper, SIGNAL(mapped(int)), SLOT(onToolChanged(int)));
    this->onToolChanged(ToolType::Pen);

    this->connect(ui->currentColorButton, SIGNAL(pressed()), SLOT(onCurrentColorButtonPressed()));
    this->updateColor();
}

ToolbarWidget::~ToolbarWidget()
{
    delete ui;
}

void ToolbarWidget::setColor(const QColor &currentColor)
{
    mCurrentColor = currentColor;

    updateColor();
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

void ToolbarWidget::updateColor()
{
    QPixmap currentColorMap(32, 32);
    currentColorMap.fill(mCurrentColor);
    ui->currentColorButton->setIcon(QIcon(currentColorMap));

    mCanvas.setCurrentColor(mCurrentColor);
}

void ToolbarWidget::onCurrentColorButtonPressed()
{
    QColorDialog colorPicker(mCurrentColor, this);
    mCurrentColor = colorPicker.getColor(mCurrentColor, this);

    this->updateColor();
}
