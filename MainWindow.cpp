#include "MainWindow.h"
MainWindow::MainWindow(QWidget *parent) : QWidget(parent)
{
    newTabDialog = new NewTabDialog(this);

    MatrixLogic *Logic = new MatrixLogic(this);
    MyTabBar *TabBar = new MyTabBar(this);
    MyToolBox *ToolBox = new MyToolBox(this);
    emptyTab = new QLabel(this);

    QMenuBar *MenuBar = new QMenuBar(this);
    QMenu *file = new QMenu("File",MenuBar);
    file->addAction("Test");
    MenuBar->addMenu(file);
    MenuBar->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

    //resize(1920,1080);
    //setMinimumSize(600,600);
    mainLay = new QGridLayout;

    mainLay->addWidget(MenuBar);
    mainLay->addWidget(TabBar,1,1,1,6);
    mainLay->addWidget(ToolBox,2,0);
    mainLay->addWidget(emptyTab,2,1,6,6);
    mainLay->setSpacing(0);
    mainLay->setMargin(0);
    setLayout(mainLay);

    connect(TabBar,SIGNAL(_sendAddSig()),
            SLOT(_addingNewTab()));

    connect(this,SIGNAL(_tabCreated(QString,int,int)),
            TabBar,SLOT(_addNewTab(QString,int,int)));

    connect(ToolBox,SIGNAL(_requestMatrixNames()),
            TabBar,SLOT(_queryMatrixNames()));

    connect(TabBar,SIGNAL(_sendAllMatrixNames(QVector<QString>)),
            ToolBox,SLOT(_catchMatrixNames(QVector<QString>)));
}

void MainWindow::_addingNewTab()
{
    Matrix temp;
    newTabDialog->exec();

    emptyTab->hide();
    emit _tabCreated(newTabDialog->getText(),newTabDialog->getHeight(),newTabDialog->getWidth());
}

