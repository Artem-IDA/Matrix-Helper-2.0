#include "MyToolBox.h"

MyToolBox::MyToolBox(QWidget *parent) : QWidget(parent)
{
    QVBoxLayout *mainLay = new QVBoxLayout;
    QToolBox *ToolBox = new QToolBox(this);
    ToolBox->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);
    connect(ToolBox,SIGNAL(currentChanged(int)),this,SLOT(_catchCurrent(int)));

    QWidget *page1 = new QWidget;
    QWidget *page2 = new QWidget;
    QWidget *page3 = new QWidget;

    QVector<QString> textPage1 = {"+C","-C","*C","/C"};
    QVector<QString> textPage2 = {"+A{}","-A{}","*A{}","/A{}"};
    QVector<QString> textPage3 = {};

    QGridLayout *layPage1 = new QGridLayout;
    QGridLayout *layPage2 = new QGridLayout;
    QGridLayout *layPage3 = new QGridLayout;

    for (int i = 0;i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            QPushButton *temp = new QPushButton(textPage1[i]);
            temp->setFixedSize(40,40);
            temp->setObjectName(textPage1[i]+"_UNARY");
            connect(temp,SIGNAL(clicked()),this, SIGNAL(_sendRequestToLogic()));
            layPage1->setSpacing(0);
            layPage1->setMargin(0);
            layPage1->addWidget(temp,i,j);
        }
    }
    page1->setLayout(layPage1);

    for (int i = 0;i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            QPushButton *temp = new QPushButton(textPage2[i]);
            temp->setFixedSize(40,40);
            temp->setObjectName(textPage2[i]+"_BINARY");
            connect(temp,SIGNAL(clicked()),this, SIGNAL(_sendRequestToLogic()));
            layPage2->setSpacing(0);
            layPage2->setMargin(0);
            layPage2->addWidget(temp,i,j);
        }
    }
    page2->setLayout(layPage2);

    for (int i = 0;i < textPage3.size(); i++) {
        QPushButton *temp = new QPushButton;
        temp->setObjectName(textPage3[i]);
        connect(temp,SIGNAL(clicked()),this, SIGNAL(_sendRequestToLogic()));
        layPage3->addWidget(temp);
    }
    page3->setLayout(layPage3);

    ToolBox->addItem(page1,"Unary operations");
    ToolBox->addItem(page2,"Binary operations");
    ToolBox->addItem(page3,"Other operation");

    mainLay->addWidget(ToolBox);
    mainLay->setMargin(5);
    mainLay->setSpacing(0);
    setLayout(mainLay);
}

QSize MyToolBox::sizeHint() const
{
    return QSize(100,100);
}

void MyToolBox::_catchCurrent(int index)
{

}



