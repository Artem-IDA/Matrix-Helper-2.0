#include "MyTabBar.h"

MyTabBar::MyTabBar(QWidget *parent) : QWidget(parent)
{
    TabBar = new QTabBar;
    Stack = new QStackedWidget;

    QGridLayout *mainLay = new QGridLayout;

    addButton = new QPushButton("+");

    connect(addButton,SIGNAL(clicked()),SIGNAL(_sendAddSig()));
    connect(TabBar,SIGNAL(currentChanged(int)),SLOT(_currentChanged(int)));

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

void MyTabBar::_closeTab()
{
    TabBar->removeTab(sender()->objectName().toInt());
    for (int i = 0; i < matrixNames.size(); i ++)
    {
        if(matrixNames[i] == Stack->widget(sender()->objectName().toInt())->objectName())
            matrixNames.remove(i);
    }
    for (int i = 0; i < tabPointers.size(); i ++)
    {
        if(tabPointers[i] == Stack->widget(sender()->objectName().toInt()))
            tabPointers.remove(i);
    }
    Stack->removeWidget(Stack->widget(sender()->objectName().toInt()));
}

void MyTabBar::_addNewTab(QString name, int height, int width)
{
    TabBar->blockSignals(true);

    int tempIndex=TabBar->addTab(name);
    QPushButton *closeButton = new QPushButton("x");
    closeButton->setObjectName(QString::number(tempIndex));
    closeButton->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);
    closeButton->setFixedSize(15,15);
    TabBar->setTabButton(tempIndex,QTabBar::RightSide,closeButton);

    connect(closeButton,SIGNAL(clicked()),this,SLOT(_closeTab()));

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

void MyTabBar::_queryMatrix(QString name)
{
    for (int i = 0;i < tabPointers.size(); i++) {
        if(tabPointers[i]->getName() == name)
        {
            emit _sendMatrix(tabPointers[i]->getMatrix());
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
