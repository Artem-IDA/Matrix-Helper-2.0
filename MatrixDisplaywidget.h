#ifndef MATRIXDISPLAYWIDGET_H
#define MATRIXDISPLAYWIDGET_H

#include <QWidget>
#include <QtWidgets>
#include <Matrix.h>

class MatrixDisplayWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MatrixDisplayWidget(Matrix dis_Matrix, QWidget *parent = nullptr);
    void resizeWidget(Matrix new_Matrix);
    void display(Matrix dis_Matrix);

    QSize sizeHint() const;
private:
    void updateState();

    Matrix actualWidgetMatrix;
    QVector <QVector<QLCDNumber*>> matrix_LCDn;

    QGridLayout* mainLayout;
    int width_widget;
    int height_widget;
signals:
public slots:
    void _updateMatrix(Matrix new_Matrix);
};

#endif // MATRIXDISPLAYWIDGET_H
