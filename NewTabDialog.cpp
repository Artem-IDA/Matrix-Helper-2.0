#include "NewTabDialog.h"

NewTabDialog::NewTabDialog(QWidget *parent) : QDialog(parent)
{
    lineEdit = new QLineEdit("Enter name of matrix");
    heightSB = new QSpinBox;
    widthSB = new QSpinBox;
    heightSB->setRange(2,9);
    widthSB->setRange(2,9);

    QLabel *heightLabel = new QLabel("Enter height:");
    QLabel *widthLabel = new QLabel("Enter width:");
    QPushButton *OKbutton = new QPushButton("OK");
    QPushButton *CANCELbutton = new QPushButton("Cancel");

    connect(OKbutton,SIGNAL(clicked()),SLOT(accept()));
    connect(CANCELbutton,SIGNAL(clicked()),SLOT(reject()));

    QGridLayout *mainLayout = new QGridLayout;
    mainLayout->addWidget(lineEdit,0,0,1,2);
    mainLayout->addWidget(heightLabel,1,0);
    mainLayout->addWidget(heightSB,1,1);
    mainLayout->addWidget(widthLabel,2,0);
    mainLayout->addWidget(widthSB,2,1);
    mainLayout->addWidget(OKbutton,3,0);
    mainLayout->addWidget(CANCELbutton,3,1);
    setLayout(mainLayout);
}

QString NewTabDialog::getText() const
{
    return lineEdit->text();
}
int NewTabDialog::getHeight() const
{
    return heightSB->value();
}
int NewTabDialog::getWidth() const
{
    return  widthSB->value();
}
