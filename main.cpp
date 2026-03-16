#include "MainWindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow hello;
    hello.resize(1200,600);
    hello.show();
    return a.exec();
}
