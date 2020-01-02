#include "MyTab.h"

MyTab::MyTab(int index, int height_matrix, int width_matrix, QString name_matrix, QWidget *parent) : QWidget(parent)
{
    swapCount = 1;
    index_Tab = index;
    tab_Matrix = Matrix(height_matrix,width_matrix,name_matrix);
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
            this,SLOT(_getMatrix(Matrix)));

    //                  this
    //                   |↑
    //                   ||  matrix
    //                   ↓|
    //                matInWgt --> matDisWgt

    QGridLayout *mainLay = new QGridLayout;
    mainLay->addWidget(matInWidget,0,0);
    mainLay->addWidget(matDisWidget,0,0);

    setLayout(mainLay);
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
}

void MyTab::changeMatrix(Matrix changedMatrix)
{
    tab_Matrix = changedMatrix;
}

void MyTab::swapM_Widgets()
{
    if(swapCount%2 == 0)
    {
        matDisWidget->show();
        matInWidget->hide();
    }
    else
    {
        matDisWidget->hide();
        matInWidget->show();
    }
    swapCount++;
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

void MyTab::_getMatrix(Matrix new_Matrix)
{
    if(new_Matrix != tab_Matrix)
    {
        tab_Matrix = new_Matrix;
        emit _sendMatrix(tab_Matrix);
    }
}
