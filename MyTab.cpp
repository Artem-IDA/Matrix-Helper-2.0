#include "MyTab.h"

MyTab::MyTab(int index, int height_matrix, int width_matrix, QString name_matrix, QWidget *parent) : QWidget(parent)
{
    index_Tab = index;
    tab_Matrix = Matrix(height_matrix,width_matrix,name_matrix);
    modeBut = new QPushButton("Editing");
    modeBut->hide();
    modeBut->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    okBut = new QPushButton("OK");
    okBut->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    matInWidget = new MatrixInWidget(tab_Matrix);
    matInWidget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    matDisWidget = new MatrixDisplayWidget(tab_Matrix);
    matDisWidget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    matDisWidget->hide();

    connect(this,SIGNAL(_sendMatrix(Matrix)),
            matInWidget,SLOT(_updateMatrix(Matrix)));
    connect(matInWidget,SIGNAL(_sendMatrix(Matrix)),
            matDisWidget,SLOT(_updateMatrix(Matrix)));
    connect(matInWidget,SIGNAL(_sendMatrix(Matrix)),
            this,SLOT(_catchMatrix(Matrix)));

    connect(okBut,SIGNAL(clicked()),
            this,SLOT(_OKClicked()));
    connect(modeBut,SIGNAL(clicked()),
            this,SLOT(_ModeClicked()));

    //                  this
    //                   |↑
    //                   ||  matrix
    //                   ↓|
    //                matInWgt --> matDisWgt

    QGridLayout *mainLay = new QGridLayout;
    mainLay->addWidget(modeBut,1,0);
    mainLay->addWidget(okBut,1,0);
    mainLay->addWidget(matInWidget,0,0);
    mainLay->addWidget(matDisWidget,0,0);
    mainLay->setAlignment(modeBut,Qt::AlignCenter);
    mainLay->setAlignment(okBut,Qt::AlignCenter);
    mainLay->setMargin(1);
    mainLay->setSpacing(1);

    setLayout(mainLay);
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
}

void MyTab::setNewMatrix(Matrix newMatrix)
{
    tab_Matrix = newMatrix;
    emit _sendMatrix(tab_Matrix);
}

Matrix MyTab::getMatrix()
{
    return tab_Matrix;
}

int MyTab::getIndex()
{
    return index_Tab;
}

QString MyTab::getName()
{
    return tab_Matrix.getName();
}

QSize MyTab::sizeHint() const
{
    return QSize(300,300);
}

void MyTab::_catchMatrix(Matrix new_Matrix)
{
    if(new_Matrix != tab_Matrix)
    {
        tab_Matrix = new_Matrix;
        emit _sendMatrix(tab_Matrix);
    }
}

void MyTab::_OKClicked()
{
    matDisWidget->show();
    okBut->hide();
    matInWidget->hide();
    modeBut->show();
}

void MyTab::_ModeClicked()
{
    matDisWidget->hide();
    okBut->show();
    matInWidget->show();
    modeBut->hide();
}
