#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Widgets {

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void initializeToolWidget();

private:
    QString standardLocation() const;

private slots:
    void onNewImageAction();
    void onLoadImageAction();
    void onSaveImageAction();
    void onSaveImageAsAction();

private:
    Ui::MainWindow *ui;
    QString mFilename;
    void saveImage();
};

}

#endif // MAINWINDOW_H
