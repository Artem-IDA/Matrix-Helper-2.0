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

void MatrixLogic::_catchFirstMatrix(Matrix matrix)
{
    gettingMatrix_1 = matrix;
}

void MatrixLogic::_catchSecondMatrix(Matrix matrix)
{
    gettingMatrix_2 = matrix;
}



