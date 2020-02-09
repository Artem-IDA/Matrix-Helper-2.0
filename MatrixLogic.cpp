#include "MatrixLogic.h"

MatrixLogic::MatrixLogic(QObject *parent) : QObject(parent)
{

}

void MatrixLogic::_queryUnaryOperation(QString nameFirstMatrix, QString operation, int value)
{
    emit _requestFirstMatrix(nameFirstMatrix);
    if(operation == "+C_UNARY")
    {
        resultMatrix = gettingMatrix_1 + value;
        emit _sendResultMatrix(resultMatrix);
    }
    else if(operation == "-C_UNARY")
    {
        resultMatrix = gettingMatrix_1 - value;
        emit _sendResultMatrix(resultMatrix);
    }
    else if(operation == "*C_UNARY")
    {
        resultMatrix = gettingMatrix_1 * value;
        emit _sendResultMatrix(resultMatrix);
    }
    else if (operation == "^C_UNARY") {
        resultMatrix = gettingMatrix_1 ^ value;
        emit _sendResultMatrix(resultMatrix);
    }
}

void MatrixLogic::_queryBinaryOperation(QString nameFirstMatrix, QString operation, QString nameSecondMatrix)
{
    emit _requestFirstMatrix(nameFirstMatrix);
    emit _requestSecondMatrix(nameSecondMatrix);
    if(operation == "+A{}_BINARY")
    {
        resultMatrix = gettingMatrix_1 + gettingMatrix_2;
        emit _sendResultMatrix(resultMatrix);
    }
    else if(operation == "-A{}_BINARY")
    {
        resultMatrix = gettingMatrix_1 - gettingMatrix_2;
        emit _sendResultMatrix(resultMatrix);
    }
    else if(operation == "*A{}_BINARY")
    {
        resultMatrix = gettingMatrix_1 * gettingMatrix_2;
        emit _sendResultMatrix(resultMatrix);
    }
}

void MatrixLogic::_queryOtherOperation(QString nameFirstMatrix, QString operation)
{
    emit _requestFirstMatrix(nameFirstMatrix);
    if(operation == "D{}_OTHER"){
        resultNum = gettingMatrix_1.determinant();
        QString result = "Детерминант матрицы равен " + QString::number(resultNum);
        emit _sendResultNum(result);
    }
    else if(operation == "T{}_OTHER"){
        gettingMatrix_1.transpose();
        emit _sendResultMatrix(gettingMatrix_1);
    }
}

void MatrixLogic::_catchFirstMatrix(Matrix matrix)
{
    gettingMatrix_1 = matrix;
}

void MatrixLogic::_catchSecondMatrix(Matrix matrix)
{
    gettingMatrix_2 = matrix;
}



