#include "mybutton.h"
#include <QDebug>

mybutton::mybutton(QWidget *parent) : QPushButton(parent)
{

}

mybutton::~mybutton()
{
    qDebug() << "按钮被析构";
}
