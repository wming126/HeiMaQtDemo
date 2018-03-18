#include "subqwidget.h"

SubQWidget::SubQWidget(QWidget *parent) : QWidget(parent)
{
    this->setWindowTitle("老二");
    this->resize(500,400);
    button.setParent(this);
    button.setText("切换到主窗体");

    connect(&button,&QPushButton::clicked,this,&SubQWidget::sendSlot);
}

void SubQWidget::sendSlot()
{
    emit mySignal();
    emit mySignal(250, "我是子窗口");
}
