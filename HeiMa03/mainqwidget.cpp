#include "mainqwidget.h"
#include <QPushButton>
#include <QDebug>

MainQWidget::MainQWidget(QWidget *parent)
    : QWidget(parent)
{
    button.setParent(this);
    button.setText("button1");

    pButton = new QPushButton(this);

    pButton->setText("Button2");
    pButton->move(100, 100);

    button2.setParent(this);
    button2.setText("切换到子窗口");
    button2.move(200, 200);

    // 标准信号
    connect(&button,&QPushButton::pressed,this,&MainQWidget::close);
    //connect(pButton,&QPushButton::released,this,&MainQWidget::MySlot);
    //connect(pButton,&QPushButton::pressed,&button,&QPushButton::hide);

    this->setWindowTitle("老大");

    this->resize(500,400);
    //setWindowTitle("老大");

    //w2.show();

    connect(&button2,&QPushButton::pressed,this,&MainQWidget::changeWin);


#if 0 // QT5
    //QT5 处理子窗口信号
    void (SubQWidget::*funcsignal)() = &SubQWidget::mySignal;
    connect(&w2,funcsignal,this,&MainQWidget::dealSub);

    void (SubQWidget::*funcsignal2)(int,QString) = &SubQWidget::mySignal;
    connect(&w2,funcsignal2,this,&MainQWidget::dealSignal);
#else // QT4
    // QT4  槽函数必须有slots关键字修饰
    // SLOT SIGNAL 将函数名字转成了字符串不进行错误检查
    connect(&w2, SIGNAL(mySignal ()), this, SLOT(dealSub()));
    connect(&w2, SIGNAL(mySignal(int,QString)), this, SLOT(dealSignal(int,QString)));
#endif

    // Lambda表达式,匿名函数对象
    // C++11增加的新特性,项目文件 CONFIG += C++11
    // Qt配合信号一起使用,非常方便

    QPushButton *b4 = new QPushButton(this);

    b4->setText("Lambda表达式");

    b4->move(300,300);

    int a = 10, b = 20;
    connect(b4, &QPushButton::clicked,
            //[b4,a,b]()
            // = :把外部所有局部变量,类中所有成员以值传递的方式传入 变量默认为只读 加mutable变为可写
            // this:类中所有成员以值传递方式
            // &:把外部所有局部变量,
            [=](bool clicked) mutable
            {
                b4->setText("Lambda");
                qDebug()<<"This is lambda!" << a << b;

                qDebug() << a << b;
                a = 0;
                b = 0;
                qDebug() << a << b;

                qDebug() << clicked;
            }
            );
}

void MainQWidget::MySlot()
{
    button2.setText("Button2");
}

void MainQWidget::changeWin()
{
    // 子窗口显示
    w2.show();
    // 主窗口隐藏
    this->hide();
}

void MainQWidget::dealSub()
{
    this->show();

    w2.hide();

}

void MainQWidget::dealSignal(int a, QString str)
{
    qDebug() << a << str;
}

MainQWidget::~MainQWidget()
{

}
