#ifndef MATRIXLOGIC_H
#define MATRIXLOGIC_H

#include <QObject>
#include <QWidget>
#include <Matrix.h>

class MatrixLogic : public QObject
{
    Q_OBJECT
public:
    explicit MatrixLogic(QObject *parent = nullptr);
private:
    void calculateADDITION();
    void calculateSUBTRACTION();
    void calculateMULTIPLICATION();
    void calculateDIVISION();


    Matrix gettingMatrix_1;
    Matrix gettingMatrix_2;
signals:
    void _sendLMatrix(QVector <QVector<int>> Matrix, int height, int width);
public slots:
    void _selectMenu();
    void _gettingMatrix(Matrix matrix);
    void _getting2Matrix(Matrix first, Matrix second);
};


#endif // MATRIXLOGIC_H
