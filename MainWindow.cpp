#include "MainWindow.h"
MainWindow::MainWindow(QWidget *parent) : QWidget(parent)
{
    setWindowFlags(Qt::Window|Qt::WindowMinimizeButtonHint|Qt::WindowCloseButtonHint);
    setWindowTitle("MatrixHelper 2.0");
    newTabDialog = new NewTabDialog(this);

    MatrixLogic *Logic = new MatrixLogic(this);
    MyTabBar *TabBar = new MyTabBar(this);
    MyToolBox *ToolBox = new MyToolBox(this);
    emptyTab = new QLabel("Add new tab",this);
    emptyTab->setAlignment(Qt::AlignCenter);

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

    connect(ToolBox,SIGNAL(_requestActiveMatrixName()),
            TabBar,SLOT(_queryActiveMatrixName()));
    connect(TabBar,SIGNAL(_sendActiveMatrixName(QString)),
            ToolBox,SLOT(_catchActiveMatrixName(QString)));

    connect(ToolBox,SIGNAL(_requestUnaryOperation(QString, QString, int)),
            Logic,SLOT(_queryUnaryOperation(QString, QString, int)));

    connect(ToolBox,SIGNAL(_requestBinaryOperation(QString, QString, QString)),
            Logic,SLOT(_queryBinaryOperation(QString, QString, QString)));

    connect(Logic,SIGNAL(_requestFirstMatrix(QString)),
            TabBar,SLOT(_queryFirstMatrix(QString)));
    connect(TabBar,SIGNAL(_sendFirstMatrix(Matrix)),
            Logic,SLOT(_catchFirstMatrix(Matrix)));

    connect(Logic,SIGNAL(_requestSecondMatrix(QString)),
            TabBar,SLOT(_querySecondMatrix(QString)));
    connect(TabBar,SIGNAL(_sendSecondMatrix(Matrix)),
            Logic,SLOT(_catchSecondMatrix(Matrix)));

    connect(Logic,SIGNAL(_sendResultMatrix(Matrix)),
            TabBar,SLOT(_catchResultMatrix(Matrix)));
}

void MainWindow::_addingNewTab()
{
    Matrix temp;
    emptyTab->hide();

    newTabDialog->exec();
    if(newTabDialog->result() != 0)
    emit _tabCreated(newTabDialog->getText(),newTabDialog->getHeight(),newTabDialog->getWidth());
}

