#ifndef MYTAB_H
#define MYTAB_H

#include <QWidget>
#include <QtWidgets>
#include <Matrix.h>
#include <MatrixInwidget.h>
#include <MatrixDisplaywidget.h>

class MyTab : public QWidget
{
    Q_OBJECT
public:
    MyTab(int index, int height_matrix, int width_matrix, QString name_matrix, QWidget *parent = nullptr);

    void setNewMatrix(Matrix newMatrix);

    Matrix getMatrix();
    int getIndex();
    QString getName();

    QSize sizeHint() const;
private:
    Matrix tab_Matrix;
    int index_Tab;
    QPushButton *modeBut;
    QPushButton *okBut;
    MatrixInWidget *matInWidget;
    MatrixDisplayWidget *matDisWidget;
signals:
    void _sendMatrix(Matrix tab_matrix);
public slots:
    void _catchMatrix(Matrix tab_matrix);
    void _OKClicked();
    void _ModeClicked();
};

#endif // MYTAB_H
