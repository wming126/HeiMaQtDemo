#ifndef MAINQWIDGET_H
#define MAINQWIDGET_H

#include <QWidget>
#include <QPushButton>
#include "subqwidget.h"

class MainQWidget : public QWidget
{
    Q_OBJECT

public:
    MainQWidget(QWidget *parent = 0);
    ~MainQWidget();

public slots:
    void MySlot();
    void changeWin();
    void dealSub();
    void dealSignal(int, QString);

private:
    QPushButton button;
    QPushButton * pButton;
    QPushButton button2;

    SubQWidget  w2;
};

#endif // MAINQWIDGET_H
