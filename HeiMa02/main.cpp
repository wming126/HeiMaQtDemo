#include <QApplication>
#include <QWidget>
#include <QPushButton>

int main(int argc, char *argv[])
{
    QApplication a(argc,argv);

    QWidget w;

    w.setWindowTitle("主要看气质");

    QPushButton button;

    button.setText("☺");

    //button.show();
    button.setParent(&w);

    button.move(100,100);

    QPushButton button2(&w);
    button2.setText("我去做头发了");

    w.show();

    return a.exec();
}

