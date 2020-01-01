#ifndef MATRIX_H
#define MATRIX_H

#include <QVector>

class Matrix
{
public:
    Matrix();
    Matrix(int height, int width, QString name);
    Matrix(QVector<QVector<int>> QVec_matrix, QString name);
    ~Matrix();

    QString getName();
    void setName(QString name);
    QVector<QVector<int>> getVecMatrix();
    void setVecMatrix(QVector<QVector<int>> QVecMatr);
    int getHeight();
    int getWidth();

    Matrix & operator = (const Matrix second_Matrix);
    bool operator == (const Matrix second_Matrix);
    bool operator != (const Matrix second_Matrix);
    QVector<int>& operator [] (int index);
private:
    QString m_name;
    int m_height, m_width;
    QVector <QVector<int>> m_Matrix;
};



#endif // MATRIX_H
