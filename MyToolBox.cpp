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

    QVector<QString> textPage1 = {"ADDITION","SUBTRACTION", "MULTIPLICATION", "DIVISION"};
    QVector<QString> textPage2 = {};
    QVector<QString> textPage3 = {};

    QVBoxLayout *layPage1 = new QVBoxLayout;
    QVBoxLayout *layPage2 = new QVBoxLayout;
    QVBoxLayout *layPage3 = new QVBoxLayout;

    for (int i = 0;i < textPage1.size(); i++) {
        QPushButton *temp = new QPushButton(textPage1[i]);
        temp->setObjectName(textPage1[i]+"_UNARY");
        connect(temp,SIGNAL(clicked()),this, SIGNAL(_sendRequestToLogic()));
        layPage1->addWidget(temp);
    }
    page1->setLayout(layPage1);

    for (int i = 0;i < textPage2.size(); i++) {
        QPushButton *temp = new QPushButton;
        temp->setObjectName(textPage2[i]+"_BINARY");
        connect(temp,SIGNAL(clicked()),this, SIGNAL(_sendRequestToLogic()));
        layPage2->addWidget(temp);
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



