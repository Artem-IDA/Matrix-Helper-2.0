#include "MyToolBox.h"

MyToolBox::MyToolBox(QWidget *parent) : QWidget(parent)
{
    QVBoxLayout *mainLay = new QVBoxLayout;
    QToolBox *ToolBox = new QToolBox(this);
    ToolBox->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);
    //connect(ToolBox,SIGNAL(currentChanged(int)),this,SLOT(_catchCurrent(int)));

    QWidget *page1 = new QWidget;
    QWidget *page2 = new QWidget;
    QWidget *page3 = new QWidget;

    QVector<QString> textPage1 = {"+C","-C","*C","/C"};
    QVector<QString> textPage2 = {"+A{}","-A{}","*A{}","/A{}"};
    QVector<QString> textPage3 = {};
    int counter = 0;

    QGridLayout *layPage1 = new QGridLayout;
    QGridLayout *layPage2 = new QGridLayout;
    QGridLayout *layPage3 = new QGridLayout;

    ok_unary = new QPushButton("OK");
    ok_unary->setObjectName("ok_UNARY");
    ok_unary->setDisabled(true);

    C_number = new QSpinBox;
    C_number->setObjectName("C_number");
    C_number->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    C_number->setAlignment(Qt::AlignCenter);
    C_number->setRange(-99,99);
    C_number->setWrapping(true);
    C_number->setDisabled(true);

    connect(C_number,SIGNAL(valueChanged(int)),
            this,SLOT(_catchCurrentValue(int)));
    connect(ok_unary,SIGNAL(clicked()),
            this,SLOT(_okClicked()));

    layPage1->addWidget(C_number,2,0,1,0);
    layPage1->addWidget(ok_unary,3,0,1,0);

    for (int i = 0;i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            QPushButton *temp = new QPushButton(textPage1[counter]);
            temp->setFixedSize(40,40);
            temp->setObjectName(textPage1[counter]+"_UNARY");
            connect(temp,SIGNAL(clicked()),this, SLOT(_catchCurrentOperation()));
            layPage1->setSpacing(0);
            layPage1->setMargin(0);
            layPage1->addWidget(temp,i,j);
            counter++;
        }
    }
    page1->setLayout(layPage1);

    ok_binary = new QPushButton("OK");
    ok_binary->setObjectName("ok_BINARY");
    ok_binary->setDisabled(true);

    List_names = new QComboBox;
    List_names->setFixedSize(85,20);
    List_names->addItem("Change matrix");
    List_names->setDisabled(true);

    connect(this,SIGNAL(_cleanComboBox()),
            List_names,SLOT(clear()));
    connect(List_names,SIGNAL(currentTextChanged(const QString &)),
            this,SLOT(_catchCurrentMatrix(QString)));
    connect(ok_binary,SIGNAL(clicked()),
            this,SLOT(_okClicked()));

    layPage2->addWidget(List_names,2,0,1,0);
    layPage2->addWidget(ok_binary,3,0,1,0);

    counter = 0;
    for (int i = 0;i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            QPushButton *temp = new QPushButton(textPage2[counter]);
            temp->setFixedSize(40,40);
            temp->setObjectName(textPage2[counter]+"_BINARY");
            connect(temp,SIGNAL(clicked()),this, SLOT(_catchCurrentOperation()));
            layPage2->setSpacing(0);
            layPage2->setMargin(0);
            layPage2->addWidget(temp,i,j);
            counter++;
        }
    }
    page2->setLayout(layPage2);

    counter = 0;
    for (int i = 0;i < textPage3.size(); i++) {
        QPushButton *temp = new QPushButton;
        temp->setObjectName(textPage3[counter]);
        connect(temp,SIGNAL(clicked()),this, SLOT(_catchCurrentOperation()));
        layPage3->addWidget(temp);
        counter++;
    }
    page3->setLayout(layPage3);

    ToolBox->addItem(page1,"Unary operations");
    ToolBox->addItem(page2,"Binary operations");
    ToolBox->addItem(page3,"Other operation");

    mainLay->addWidget(ToolBox);
    mainLay->setMargin(1);
    mainLay->setSpacing(0);
    setLayout(mainLay);
}

QSize MyToolBox::sizeHint() const
{
    return QSize(100,100);
}

void MyToolBox::_catchMatrixNames(QVector<QString> names)
{
    emit _cleanComboBox();
    List_names->addItem("Change matrix");
    List_names->addItems(names.toList());
}

void MyToolBox::_catchActiveMatrixName(QString name)
{
    lastActiveMatrix = name;
}

void MyToolBox::_catchCurrentOperation()
{
    if(sender()->objectName().split("_")[1] == "UNARY")
    {
        C_number->setEnabled(true);
        ok_unary->setEnabled(true);
        lastChangedOperation = sender()->objectName();
    }
    else if(sender()->objectName().split("_")[1] == "BINARY")
    {
        emit _requestMatrixNames();
        List_names->setEnabled(true);
        ok_binary->setEnabled(true);
        lastChangedOperation = sender()->objectName();
    }
}

void MyToolBox::_catchCurrentValue(int value)
{
    lastChangedValue = value;
}

void MyToolBox::_catchCurrentMatrix(QString name)
{
    lastChangedSecondMatrix = name;
}

void MyToolBox::_okClicked()
{
    if(sender()->objectName().split("_")[1] == "UNARY")
    {
        emit _requestActiveMatrixName();
        emit _requestUnaryOperation(lastActiveMatrix,lastChangedOperation,lastChangedValue);
        C_number->setDisabled(true);
        C_number->setValue(0);
        ok_unary->setDisabled(true);
    }
    else if(sender()->objectName().split("_")[1] == "BINARY")
    {
        emit _requestActiveMatrixName();
        emit _requestBinaryOperation(lastActiveMatrix,lastChangedOperation,lastChangedSecondMatrix);
        List_names->setDisabled(true);
        emit _cleanComboBox();
        List_names->addItem("Change matrix");
        ok_binary->setDisabled(true);
    }
}



