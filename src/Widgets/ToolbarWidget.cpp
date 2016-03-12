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
    mPaintColor(Qt::black)
{
    ui->setupUi(this);

    mToolGroup.setExclusive(true);
    mToolGroup.addButton(ui->penButton, Pen);
    mToolGroup.addButton(ui->lineButton, Line);
    mToolGroup.addButton(ui->fillButton, Fill);
    mToolGroup.addButton(ui->circleButton, Circle);

    this->connect(ui->lineButton, SIGNAL(pressed()), &mToolMapper, SLOT(map()));
    this->connect(ui->circleButton, SIGNAL(pressed()), &mToolMapper, SLOT(map()));
    this->connect(ui->fillButton, SIGNAL(pressed()), &mToolMapper, SLOT(map()));
    this->connect(ui->penButton, SIGNAL(pressed()), &mToolMapper, SLOT(map()));

    mToolMapper.setMapping(ui->circleButton, static_cast<int>(ToolType::Circle));
    mToolMapper.setMapping(ui->lineButton, static_cast<int>(ToolType::Line));
    mToolMapper.setMapping(ui->penButton, static_cast<int>(ToolType::Pen));
    mToolMapper.setMapping(ui->fillButton, static_cast<int>(ToolType::Fill));

    this->connect(&mToolMapper, SIGNAL(mapped(int)), SLOT(onToolChanged(int)));
    this->onToolChanged(ToolType::Pen);

    this->connect(ui->paintColorButton, SIGNAL(pressed()), SLOT(onPaintColorButtonPressed()));
    this->connect(ui->backgroundColorButton, SIGNAL(pressed()), SLOT(onBackgroundColorButtonPressed()));

    this->setPaintColor(Qt::black);
    this->setBackgroundColor(Qt::white);
}

ToolbarWidget::~ToolbarWidget()
{
    delete ui;
}

void ToolbarWidget::setPaintColor(const QColor &paintColor)
{
    mPaintColor = paintColor;

    this->updatePaintColorLabel();

    mCanvas.context().setPaintColor(mPaintColor);
}

void ToolbarWidget::setBackgroundColor(const QColor &backgroundColor)
{
    mBackgroundColor = backgroundColor;

    this->updateBackgroundColorLabel();

    mCanvas.context().setBackgroundColor(mBackgroundColor);
}

void ToolbarWidget::onToolChanged(int toolId)
{
    auto tool = ToolsByType.value(toolId);
    Q_ASSERT(tool);
    if(tool)
    {
        mCanvas.setCurrentTool(tool.data());
    }

    auto button = mToolGroup.button(toolId);
    Q_ASSERT(button);
    if(button)
    {
        button->setCheckable(true);
        button->setChecked(true);
    }
}

void ToolbarWidget::updatePaintColorLabel()
{
    QPixmap currentColorMap(32, 32);
    currentColorMap.fill(mPaintColor);
    ui->paintColorButton->setIcon(QIcon(currentColorMap));
}

void ToolbarWidget::updateBackgroundColorLabel()
{
    QPixmap currentColorMap(32, 32);
    currentColorMap.fill(mBackgroundColor);
    ui->backgroundColorButton->setIcon(QIcon(currentColorMap));

}

void ToolbarWidget::onPaintColorButtonPressed()
{
    QColorDialog colorPicker(mPaintColor, this);
    const auto &color = colorPicker.getColor(mPaintColor, this);
    this->setPaintColor(color);
}

void ToolbarWidget::onBackgroundColorButtonPressed()
{
    QColorDialog colorPicker(mBackgroundColor, this);
    const auto &color = colorPicker.getColor(mBackgroundColor, this);

    this->setBackgroundColor(color);
}
