#ifndef MYBUTTON_H
#define MYBUTTON_H

#include <QPushButton>

class mybutton : public QPushButton
{
    Q_OBJECT
public:
    explicit mybutton(QWidget *parent = nullptr);
    ~mybutton();

signals:

public slots:
};

#endif // MYBUTTON_H
