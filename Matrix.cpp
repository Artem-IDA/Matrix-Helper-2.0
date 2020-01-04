#include "Matrix.h"

Matrix::Matrix()
{
    m_name = "default";
    m_height = m_width = 3;
    for(int i = 0; i < 3; i++)
    {
        QVector <int> temp;
        for(int j = 0; j < 3; j++)
        {
            temp.push_back(0);
        }
        m_Matrix.push_back(temp);
    }
}
Matrix::Matrix(int height, int width, QString name)
{
    m_name = name;
    m_height = height;
    m_width = width;
    for(int i = 0; i < height; i++)
    {
        QVector <int> temp;
        for(int j = 0; j < width; j++)
        {
            temp.push_back(0);
        }
        m_Matrix.push_back(temp);
    }
}
Matrix::Matrix(QVector<QVector<int>> QVec_matrix, QString name)
{
    m_name = name;
    m_height = QVec_matrix.size();
    m_width = QVec_matrix[0].size();
    m_Matrix = QVec_matrix;
}
Matrix::~Matrix()
{

}

QString Matrix::getName()
{
    return m_name;
}
void Matrix::setName(QString name)
{
    m_name = name;
}
QVector<QVector<int> > Matrix::getVecMatrix()
{
    return  m_Matrix;
}
void Matrix::setVecMatrix(QVector<QVector<int>> QVecMatr)
{
    m_Matrix = QVecMatr;
}
int Matrix::getHeight()
{
    return m_height;
}
int Matrix::getWidth()
{
    return m_width;
}

Matrix & Matrix::operator = (const Matrix second_Matrix)
{
    m_name = second_Matrix.m_name;
    m_height = second_Matrix.m_height;
    m_width = second_Matrix.m_width;
    m_Matrix = second_Matrix.m_Matrix;
    return *this;
}

Matrix &Matrix::operator +(int value)
{
    for(int i = 0; i < m_Matrix.size(); i++)
    {
        for(int j = 0; j < m_Matrix[i].size(); j++)
        {
            m_Matrix[i][j]+=value;
        }
    }
    return *this;
}
Matrix &Matrix::operator -(int value)
{
    for(int i = 0; i < m_Matrix.size(); i++)
    {
        for(int j = 0; j < m_Matrix[i].size(); j++)
        {
            m_Matrix[i][j]-=value;
        }
    }
    return *this;
}
Matrix &Matrix::operator *(int value)
{
    for(int i = 0; i < m_Matrix.size(); i++)
    {
        for(int j = 0; j < m_Matrix[i].size(); j++)
        {
            m_Matrix[i][j]*=value;
        }
    }
    return *this;
}

Matrix &Matrix::operator /(int value)
{
    if(value != 0)
    {
        for(int i = 0; i < m_Matrix.size(); i++)
        {
            for(int j = 0; j < m_Matrix[i].size(); j++)
            {
                m_Matrix[i][j]/=value;
            }
        }
    }
    return *this;
}

bool Matrix::operator ==(const Matrix second_Matrix)
{
     if(m_name == second_Matrix.m_name &&
        m_height == second_Matrix.m_height &&
        m_width == second_Matrix.m_width &&
        m_Matrix == second_Matrix.m_Matrix)
        return true;
     else
         return false;
}

bool Matrix::operator !=(const Matrix second_Matrix)
{
    if(m_name == second_Matrix.m_name &&
       m_height == second_Matrix.m_height &&
       m_width == second_Matrix.m_width &&
       m_Matrix == second_Matrix.m_Matrix)
       return false;
    else
        return true;
}

QVector<int> &Matrix::operator [](int index)
{
    return m_Matrix[index];
}



