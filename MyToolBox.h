#ifndef MYTOOLBOX_H
#define MYTOOLBOX_H

#include <QWidget>
#include <QtWidgets>

class MyToolBox : public QWidget
{
    Q_OBJECT
public:
    explicit MyToolBox(QWidget *parent = nullptr);
    QSize sizeHint() const;
private:
    QToolBox* ToolBox;
    QSpinBox* C_number;
    QPushButton* ok_unary;
    QComboBox* List_names;
    QPushButton* ok_binary;

    QString lastChangedOperation;
    int lastChangedValue;
    QString lastChangedSecondMatrix;
    QString lastActiveMatrix;

    QVector<QString> matrix_names;
signals:
    void _requestUnaryOperation(QString nameFirstMatrix, QString operation, int value);
    void _requestBinaryOperation(QString nameFirstMatrix, QString operation, QString nameSecondMatrix);
    void _requestMatrixNames();
    void _requestActiveMatrixName();
    void _cleanComboBox();
public slots:
    void _catchMatrixNames(QVector<QString> names);
    void _catchActiveMatrixName(QString name);
    void _catchCurrentOperation();
    void _catchCurrentValue(int value);
    void _catchCurrentMatrix(QString name);
    void _okClicked();
};

#endif // MYTOOLBOX_H
