#include "MatrixInwidget.h"
#include <string>

MatrixInWidget::MatrixInWidget(Matrix start_matrix, QWidget *parent) : QWidget(parent)
{
    width_widget = start_matrix.getWidth();
    height_widget = start_matrix.getHeight();

    mainLayout = new QGridLayout();
    setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    setMaximumHeight(100);

    for(int i = 0; i < start_matrix.getHeight(); i++){
        QVector <QSpinBox*> temp_vec_spBox;
        for (int j = 0; j < start_matrix.getWidth(); j++) {
            QString name = QString::number(i) + '.' + QString::number(j);
            QSpinBox* temp_sp = new QSpinBox;
            temp_sp->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
            temp_sp->setAlignment(Qt::AlignCenter);
            /*QFont font = temp_sp->font();
            font.setPixelSize(40);
            temp_sp->setFont(font);*/
            temp_sp->setObjectName(name);
            temp_sp->setRange(0,99);
            temp_sp->setWrapping(true);
            temp_sp->setMaximumHeight(100);
            //temp_sp->resize(50,50);
            temp_sp->setWindowFlag(Qt::ToolTip);
            temp_vec_spBox.push_back(temp_sp);
            connect(temp_sp,SIGNAL(valueChanged(int)),this,SLOT(_valuesChanged(int)));

            mainLayout->addWidget(temp_sp,i,j);
        }
        matrix_spBox.push_back(temp_vec_spBox);
    }
    In_matrix = start_matrix;

    mainLayout->setSpacing(0);
    mainLayout->setMargin(0);
    setLayout(mainLayout);

}

void MatrixInWidget::resizeWidget(Matrix new_Matrix)
{
    for (int i = 0;i < height_widget;i++) {
        for (int j = 0;j < width_widget;j++) {
            delete matrix_spBox[i][j];
        }
    }

    matrix_spBox.clear();

    height_widget = new_Matrix.getHeight();
    width_widget = new_Matrix.getWidth();

    delete mainLayout;
    mainLayout = new QGridLayout();
    setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    setMaximumHeight(100);
    for(int i = 0; i < new_Matrix.getHeight(); i++){
        QVector <QSpinBox*> temp_vec_spBox;
        for (int j = 0; j < new_Matrix.getWidth(); j++) {
            QString name = QString::number(i) + '.' + QString::number(j);
            QSpinBox* temp_sp = new QSpinBox;
            temp_sp->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
            temp_sp->setAlignment(Qt::AlignCenter);
            /*QFont font = temp_sp->font();
            font.setPixelSize(10);
            temp_sp->setFont(font);*/
            temp_sp->setObjectName(name);
            temp_sp->setRange(0,99);
            temp_sp->setWrapping(true);
            temp_sp->setMaximumHeight(100);
            //temp_sp->resize(50,50);
            temp_sp->setWindowFlag(Qt::ToolTip);
            temp_vec_spBox.push_back(temp_sp);
            connect(temp_sp,SIGNAL(valueChanged(int)),this,SLOT(_valuesChanged(int)));

            mainLayout->addWidget(temp_sp,i,j);
        }
        matrix_spBox.push_back(temp_vec_spBox);
    }

    mainLayout->setSpacing(0);
    mainLayout->setMargin(0);
    setLayout(mainLayout);

}

QSize MatrixInWidget::sizeHint() const
{
    return QSize(170,100);
}

void MatrixInWidget::updateState()
{
    for (int i = 0; i < height_widget; i++) {
        for (int j = 0; j < width_widget; j++) {
            matrix_spBox[i][j]->setValue(In_matrix[i][j]);
        }
    }
}

void MatrixInWidget::_updateMatrix(Matrix new_Matrix)
{
    if(new_Matrix != In_matrix)
    {
        if(new_Matrix.getHeight() != height_widget || new_Matrix.getWidth() != width_widget)
        {
            resizeWidget(new_Matrix);
            In_matrix = new_Matrix;
            updateState();
        }
        else
        {
            In_matrix = new_Matrix;
            updateState();
        }
        if(new_Matrix != In_matrix)
        emit _sendMatrix(new_Matrix);
    }
}

void MatrixInWidget::_valuesChanged(int value)
{
    QString nameSend = sender()->objectName();
    int height_element = nameSend.split(".")[0].toInt();
    int width_element = nameSend.split(".")[1].toInt();

    In_matrix[height_element][width_element] = value;
    emit _sendMatrix(In_matrix);
}

