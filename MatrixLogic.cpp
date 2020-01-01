#include "MatrixLogic.h"

MatrixLogic::MatrixLogic(QObject *parent) : QObject(parent)
{

}

void MatrixLogic::calculateADDITION()
{

}

void MatrixLogic::calculateSUBTRACTION()
{

}

void MatrixLogic::calculateMULTIPLICATION()
{

}

void MatrixLogic::calculateDIVISION()
{

}

void MatrixLogic::_selectMenu()
{
    QString action = sender()->objectName();
}

void MatrixLogic::_getting2Matrix(Matrix first, Matrix second)
{
    gettingMatrix_1 = first;
    gettingMatrix_1 = second;
}
void MatrixLogic::_gettingMatrix(Matrix matrix)
{
    gettingMatrix_1 = matrix;
}



