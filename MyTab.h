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
    void changeMatrix(Matrix changedMatrix);
    void swapM_Widgets();

    int getIndex();

    QSize sizeHint() const;
private:
    int swapCount;

    Matrix tab_Matrix;
    int index_Tab;
    MatrixInWidget *matInWidget;
    MatrixDisplayWidget *matDisWidget;
signals:
    void _sendMatrix(Matrix tab_matrix);
public slots:
    void _getMatrix(Matrix tab_matrix);
};

#endif // MYTAB_H
