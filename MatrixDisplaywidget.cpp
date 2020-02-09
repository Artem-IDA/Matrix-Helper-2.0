#include "MatrixDisplaywidget.h"

MatrixDisplayWidget::MatrixDisplayWidget(Matrix dis_Matrix ,QWidget *parent) : QWidget(parent)
{
    actualWidgetMatrix = dis_Matrix;
    width_widget = dis_Matrix.getWidth();
    height_widget = dis_Matrix.getHeight();

    mainLayout = new QGridLayout();
    setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    setMaximumHeight(100);

    for(int i = 0; i < height_widget; i++){
        QVector <QLCDNumber*> temp_vec_QLCD;
        for (int j = 0; j < width_widget; j++) {
            QString name = QString::number(i) + '.' + QString::number(j);
            QLCDNumber* temp_lcd = new QLCDNumber;
            temp_lcd->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Fixed);
            temp_lcd->setDigitCount(3);
            temp_lcd->setObjectName(name);
            //temp_lcd->resize(30,30);
            temp_lcd->setMaximumHeight(60);
            temp_lcd->setWindowFlag(Qt::ToolTip);
            temp_lcd->setSegmentStyle(QLCDNumber::Flat);
            temp_vec_QLCD.push_back(temp_lcd);

            mainLayout->addWidget(temp_lcd,i,j);
        }
        matrix_LCDn.push_back(temp_vec_QLCD);
    }
    mainLayout->setMargin(0);
    mainLayout->setSpacing(0);
    setLayout(mainLayout);

}

void MatrixDisplayWidget::resizeWidget(Matrix new_Matrix)
{
    actualWidgetMatrix = new_Matrix;
    for (int i = 0;i < height_widget;i++) {
        for (int j = 0;j < width_widget;j++) {
            delete matrix_LCDn[i][j];
        }
    }

    matrix_LCDn.clear();

    height_widget = new_Matrix.getHeight();
    width_widget = new_Matrix.getWidth();

    delete mainLayout;
    mainLayout = new QGridLayout();
    setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    setMaximumHeight(100);
    for(int i = 0; i < new_Matrix.getHeight(); i++){
        QVector <QLCDNumber*> temp_vec_QLCD;
        for (int j = 0; j < new_Matrix.getWidth(); j++) {
            QString name = QString::number(i) + '.' + QString::number(j);
            QLCDNumber* temp_lcd = new QLCDNumber;
            temp_lcd->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Fixed);
            temp_lcd->setDigitCount(3);
            temp_lcd->setObjectName(name);
            //temp_lcd->resize(30,30);
            temp_lcd->setMaximumHeight(60);
            temp_lcd->setWindowFlag(Qt::ToolTip);
            temp_lcd->setSegmentStyle(QLCDNumber::Flat);
            temp_vec_QLCD.push_back(temp_lcd);

            mainLayout->addWidget(temp_lcd,i,j);
        }
        matrix_LCDn.push_back(temp_vec_QLCD);
    }

    mainLayout->setMargin(0);
    mainLayout->setSpacing(0);
    setLayout(mainLayout);

}

void MatrixDisplayWidget::updateState()
{
    for (int i = 0; i < height_widget; i++) {
        for (int j = 0; j < width_widget; j++) {
            matrix_LCDn[i][j]->display(actualWidgetMatrix[i][j]);
        }
    }
}

void MatrixDisplayWidget::display(Matrix dis_Matrix)
{
    if(dis_Matrix.getHeight() == actualWidgetMatrix.getHeight() ||
       dis_Matrix.getWidth() == actualWidgetMatrix.getHeight())
    {
        actualWidgetMatrix = dis_Matrix;
        updateState();
    }
    else
    {
        resizeWidget(dis_Matrix);
        actualWidgetMatrix = dis_Matrix;
        updateState();
    }
}

QSize MatrixDisplayWidget::sizeHint() const
{
    return QSize(170,100);
}

void MatrixDisplayWidget::_updateMatrix(Matrix new_Matrix)
{
    if(new_Matrix != actualWidgetMatrix)
    {
        if(new_Matrix.getHeight() != height_widget || new_Matrix.getWidth() != width_widget)
        {
            resizeWidget(new_Matrix);
            actualWidgetMatrix = new_Matrix;
            updateState();
        }
        else
        {
            actualWidgetMatrix = new_Matrix;
            updateState();
        }
    }
}
