#include "MyTabBar.h"

MyTabBar::MyTabBar(QWidget *parent) : QWidget(parent)
{
    TabBar = new QTabBar;
    Stack = new QStackedWidget;

    QGridLayout *mainLay = new QGridLayout;

    addButton = new QPushButton("+");
    TabBar->setTabsClosable(true);

    connect(addButton,SIGNAL(clicked()),SIGNAL(_sendAddSig()));
    connect(TabBar,SIGNAL(currentChanged(int)),SLOT(_currentChanged(int)));

    connect(TabBar,SIGNAL(tabCloseRequested(int)),
            this,SLOT(_closeTab(int)));

    addButton->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);
    addButton->setFixedSize(24,24);
    TabBar->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Fixed);
    TabBar->setFixedHeight(24);

    mainLay->addWidget(addButton,0,0);
    mainLay->addWidget(TabBar,0,1);
    mainLay->addWidget(Stack,1,0,3,2);
    mainLay->setSpacing(0);
    mainLay->setMargin(0);
    setLayout(mainLay);
}

QSize MyTabBar::sizeHint() const
{
    return QSize(200,24);
}

void MyTabBar::_catchResultMatrix(Matrix newMatrix)
{
    for (int i = 0;i < tabPointers.size();i++) {
        if(Stack->currentWidget() == tabPointers[i])
        {
            tabPointers[i]->setNewMatrix(newMatrix);
        }
    }
}

void MyTabBar::_closeTab(int index)
{
    TabBar->removeTab(index);
    for (int i = 0; i < matrixNames.size(); i++)
    {
        if(matrixNames[i] == Stack->widget(index)->objectName())
            matrixNames.remove(i);
    }
    for (int i = 0; i < tabPointers.size(); i++)
    {
        if(tabPointers[i] == Stack->widget(index))
            tabPointers.remove(i);
    }
    Stack->removeWidget(Stack->widget(sender()->objectName().toInt()));
}

void MyTabBar::_addNewTab(QString name, int height, int width)
{
    TabBar->blockSignals(true);

    int tempIndex=TabBar->addTab(name);
    /*QPushButton *closeButton = new QPushButton("x");
    closeButton->setObjectName(QString::number(tempIndex));
    closeButton->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);
    closeButton->setFixedSize(15,15);
    TabBar->setTabButton(tempIndex,QTabBar::RightSide,closeButton);*/




    MyTab* tempTab = new MyTab(tempIndex,height,width,name,this);
    tempTab->setObjectName(name);
    Stack->addWidget(tempTab);
    matrixNames.push_back(name);
    tabPointers.push_back(tempTab);

    TabBar->blockSignals(false);
}

void MyTabBar::_currentChanged(int index)
{
    Stack->setCurrentIndex(index);
}

void MyTabBar::_queryFirstMatrix(QString name)
{
    for (int i = 0;i < tabPointers.size(); i++) {
        if(tabPointers[i]->objectName() == name)
        {
            emit _sendFirstMatrix(tabPointers[i]->getMatrix());
        }
    }
}

void MyTabBar::_querySecondMatrix(QString name)
{
    for (int i = 0;i < tabPointers.size(); i++) {
        if(tabPointers[i]->objectName() == name)
        {
            emit _sendSecondMatrix(tabPointers[i]->getMatrix());
        }
    }
}

void MyTabBar::_queryActiveMatrixName()
{
    emit _sendActiveMatrixName(Stack->currentWidget()->objectName());
}

void MyTabBar::_queryMatrixNames()
{
    emit _sendAllMatrixNames(matrixNames);
}
