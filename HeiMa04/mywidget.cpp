#include "mywidget.h"
#include <QPushButton>
#include "mybutton.h"

MyWidget::MyWidget(QWidget *parent)
    : QWidget(parent)
{
    /*
     * 对于父窗口(主窗口),坐标相对于屏幕左上角
     * 原点:相对于屏幕左上脚
     * x:往右递增
     * y:往左递增
     */
    move(200,200);

    /*
     * 对于子窗口(主窗口),坐标相对于主窗口左上角
     * 原点:相对于窗口空白区域左上脚(不包括边框)
     * x:往右递增
     * y:往左递增
     */
    QPushButton * b1 = new QPushButton(this);
    b1->setText("Button1");
    b1->move(100, 100);
    b1->resize(100,100);
    QPushButton * b2 = new QPushButton(b1);
    b2->setText("Button2");

    b2->move(10, 10);
    b2->resize(50,50);

    mybutton *b3 = new mybutton(this);

    b3->setText("mybutton");

    // 1)指定父对象后 2)直接后间接继承于QObject
    // 子对象是如果是动态分配空间的，不需要手动释放
    // 系统自动释放
}

MyWidget::~MyWidget()
{

}
