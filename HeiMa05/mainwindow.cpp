#include "mainwindow.h"
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QDebug>
#include <QToolBar>
#include <QPushButton>
#include <QStatusBar>
#include <QLabel>
#include <QTextEdit>
#include <QDockWidget>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    // 菜单栏
    QMenuBar *mbar = menuBar();

    // 添加菜单
    QMenu *pFile = mbar->addMenu("文件");

    // 添加菜单项,添加动作
    QAction *pNew = pFile->addAction("新建");

    connect(pNew, &QAction::triggered,
            [=]()
            {
                qDebug() << "新建被按下";
            }
            );

    pFile->addSeparator();

    // 添加菜单项,添加动作
    QAction *pOpen = pFile->addAction("打开");

    // 工具栏:菜单项的快捷方式
    QToolBar *toolBar=addToolBar("新建");

    // 工具栏添加快捷键
    toolBar->addAction(pNew);
    toolBar->addAction(pOpen);

    QPushButton *pButton1 = new QPushButton(this);
    pButton1->setText("^_^");

    toolBar->addWidget(pButton1);

    connect(pButton1,&QPushButton::pressed,
            [=]()
            {
                pButton1->setText("@_@");
            }
            );

    QLabel *pLable = new QLabel(this);
    pLable->setText("Nomal test file");

    // 状态栏
    QStatusBar *pStatus = statusBar();

    // addWidget 从左往右添加
    pStatus->addWidget(pLable);
    pStatus->addWidget(new QLabel("2",this));
    // addWidget 从右往左添
    pStatus->addPermanentWidget(new QLabel("end",this));

    // 核心控件
    QTextEdit *pTextEdit = new QTextEdit(this);
    setCentralWidget(pTextEdit);

    // 浮动窗口
    QDockWidget *pDockWidget = new QDockWidget(this);
    addDockWidget(Qt::RightDockWidgetArea,pDockWidget);

    // 给浮动窗口添加空间
    QTextEdit *pTextEdit2 = new QTextEdit(this);
    pDockWidget->setWidget(pTextEdit2);
}

MainWindow::~MainWindow()
{

}
