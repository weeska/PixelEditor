#include "Widgets/MainWindow.h"

#include <QApplication>
#include <QDebug>
#include <QFile>
#include <QTextStream>

void loadStylesheet(const QString &path, QApplication &a)
{
    QFile styleFile(path);
    styleFile.open(QFile::ReadOnly);

    QTextStream stream(&styleFile);
    a.setStyleSheet(stream.readAll());
}

int main(int argc, char *argv[])
{
    QApplication application(argc, argv);
    loadStylesheet("://Resources/Stylesheet.qss", application);

    Widgets::MainWindow window;
    window.showMaximized();

    return application.exec();
}
