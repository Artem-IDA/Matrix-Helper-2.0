#ifndef MATRIXINPUTWIDGET_H
#define MATRIXINPUTWIDGET_H

#include <QWidget>
#include <QtWidgets>
#include <Matrix.h>

class MatrixInWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MatrixInWidget(Matrix start_matrix, QWidget *parent = nullptr);
    void resizeWidget(Matrix new_Matrix);

    QSize sizeHint() const;
private:
    void updateState();

    QVector <QVector<QSpinBox*>> matrix_spBox;
    Matrix In_matrix;

    QGridLayout* mainLayout;
    int width_widget;
    int height_widget;
signals:
    void _sendMatrix(Matrix In_matrix);
public slots:
    void _updateMatrix(Matrix new_Matrix);
    void _valuesChanged(int value);
};

#endif // MATRIXINPUTWIDGET_H
