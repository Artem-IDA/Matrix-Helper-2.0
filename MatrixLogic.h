#ifndef MATRIXLOGIC_H
#define MATRIXLOGIC_H

#include <QObject>
#include <QWidget>
#include <Matrix.h>
#include <QDebug>

class MatrixLogic : public QObject
{
    Q_OBJECT
public:
    explicit MatrixLogic(QObject *parent = nullptr);
private:
    Matrix gettingMatrix_1;
    Matrix gettingMatrix_2;
    Matrix resultMatrix;
    double resultNum;
signals:
    void _requestFirstMatrix(QString name);
    void _requestSecondMatrix(QString name);
    void _sendResultMatrix(Matrix);
    void _sendResultNum(QString);
public slots:
    void _queryUnaryOperation(QString nameFirstMatrix, QString operation, int value);
    void _queryBinaryOperation(QString nameFirstMatrix, QString operation, QString nameSecondMatrix);
    void _queryOtherOperation(QString nameFirstMatrix, QString operation);
    void _catchFirstMatrix(Matrix matrix);
    void _catchSecondMatrix(Matrix matrix);
};


#endif // MATRIXLOGIC_H
