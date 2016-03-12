#include "ToolbarWidget.h"
#include "PreviewWidget.h"

#include "MainWindow.h"
#include "ui_MainWindow.h"

#include <QDebug>
#include <QDockWidget>
#include <QFileDialog>
#include <QMessageBox>
#include <QStandardPaths>

using namespace Widgets;

namespace {
const QStringList savePictureFormats {
    "PNG-Image (*.png)"
};

const QStringList loadPictureFormats = QStringList()
    << savePictureFormats
    << "GIF-Image (*.gif)";
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->initializeToolWidget();
    this->initializePreviewWidget();

    this->connect(ui->actionNew, SIGNAL(triggered(bool)), SLOT(onNewImageAction()));

    this->connect(ui->actionLoad_Image, SIGNAL(triggered(bool)), SLOT(onLoadImageAction()));

    this->connect(ui->actionSave_Image, SIGNAL(triggered(bool)), SLOT(onSaveImageAction()));
    this->connect(ui->actionSave_Image_As, SIGNAL(triggered(bool)), SLOT(onSaveImageAsAction()));

    this->connect(ui->actionExit, SIGNAL(triggered(bool)), SLOT(close()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initializeToolWidget()
{
    auto toolsDock = new QDockWidget(tr("Tools"), this);
    toolsDock->setWidget(new ToolbarWidget(*ui->centralWidget, toolsDock));

    this->addDockWidget(Qt::LeftDockWidgetArea, toolsDock);

}

void MainWindow::initializePreviewWidget()
{
    auto previewDock = new QDockWidget(tr("Preview"), this);
    auto preview = new PreviewWidget(*ui->centralWidget, previewDock);
    previewDock->setWidget(preview);

    previewDock->setMinimumWidth(preview->minimumWidth());

    this->addDockWidget(Qt::RightDockWidgetArea, previewDock);

    this->connect(ui->centralWidget, SIGNAL(pixmapChanged(QPixmap)), preview, SLOT(updatePixmap(QPixmap)));
}

void MainWindow::onNewImageAction()
{
    ui->centralWidget->clear();
    mFilename.clear();
}

QString MainWindow::standardLocation() const
{
    const auto openDirList = QStringList()
            << QStandardPaths::standardLocations(QStandardPaths::PicturesLocation)
            << qApp->applicationDirPath();

    return openDirList.first();
}

void MainWindow::onLoadImageAction()
{
    const auto openFilename = QFileDialog::getOpenFileName(this,
                                                           tr("Load Image"),
                                                           this->standardLocation(),
                                                           ::loadPictureFormats.join(";;"));

    if(QFileInfo(openFilename).exists()) {
        const QImage image(openFilename);
        ui->centralWidget->initWithImage(image);
    }
}

void MainWindow::onSaveImageAction()
{
    if(mFilename.isEmpty()) {
        this->onSaveImageAsAction();
        return;
    }

    this->saveImage();
}

void MainWindow::saveImage()
{
    auto image = ui->centralWidget->grabImage();
    if(!image.save(mFilename)) {
        //TODO: show warning
    }
}

void MainWindow::onSaveImageAsAction()
{
    const auto saveFilename = QFileDialog::getSaveFileName(this,
                                                           tr("Save Image"),
                                                           this->standardLocation(),
                                                           ::savePictureFormats.join(";;"));

    mFilename = saveFilename;
    this->saveImage();
}
