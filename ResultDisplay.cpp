#include "ResultDisplay.h"

ResultDisplay::ResultDisplay(QWidget *parent) : QWidget(parent)
{
    resultOutp = new QLabel("Other results",this);
    resultOutp->setWordWrap(true);
    resultOutp->setAlignment(Qt::AlignCenter|Qt::AlignHCenter);
    resultOutp->setStyleSheet("border: 2px ridge black;"
                              "background-color: white;");
    resultOutp->setFixedSize(200,50);
    resultOutp->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
}

void ResultDisplay::_displayText(QString text)
{
    resultOutp->setText(text);
    resultOutp->setStyleSheet("border: 2px ridge black;");
}
