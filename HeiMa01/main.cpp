#include "mywidget.h"
#include <QApplication>
#include <ql

int main(int argc, char *argv[])
{
    // 有且只有一个应用对象
    QApplication a(argc, argv);

    MyWidget w;
    w.show();

    return a.exec();
}
