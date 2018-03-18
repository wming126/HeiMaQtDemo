#include "mainqwidget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainQWidget w;
    w.show();

    return a.exec();
}
