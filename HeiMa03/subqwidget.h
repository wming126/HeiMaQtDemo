#ifndef SUBQWIDGET_H
#define SUBQWIDGET_H

#include <QWidget>
#include <QPushButton>

class SubQWidget : public QWidget
{
    Q_OBJECT
public:
    explicit SubQWidget(QWidget *parent = nullptr);
    void sendSlot();

signals:
    void mySignal();
    void mySignal(int, QString);

public slots:

private:
    QPushButton button;
};

#endif // SUBQWIDGET_H
