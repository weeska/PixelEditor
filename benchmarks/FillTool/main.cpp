#include <iostream>
#include <chrono>

#include <QElapsedTimer>
#include <QGuiApplication>

#include <Painting/FillTool.h>

int main(int argc, char *argv[])
{
    const int iterations = 10;

    QGuiApplication app(argc, argv);

    std::vector<int> sizes{50, 100, 200, 500, 1000};

    for(auto size : sizes) {

        double summedTimes = 0.0;

        for(int i=0; i < iterations; ++i) {
            Painting::FillTool tool;
            QPixmap pixmap(size, size);
            pixmap.fill(Qt::white);

            QPainter painter(&pixmap);
            painter.setPen(QColor(Qt::black));

            QElapsedTimer timer;
            timer.start();
            tool.begin(pixmap.rect().center(), painter, pixmap);
            summedTimes += timer.elapsed();
        }

        std::cout << size << "x" << size << "\t: "
                  << summedTimes / iterations
                  << "ms"
                  << std::endl;

    }

    return 0;
}
