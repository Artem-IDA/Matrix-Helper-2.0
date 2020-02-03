#ifndef MYTABBAR_H
#define MYTABBAR_H

#include <QWidget>
#include <QtWidgets>
#include <MyTab.h>

class MyTabBar : public QWidget
{
    Q_OBJECT
public:
    explicit MyTabBar(QWidget *parent = nullptr);
    QSize sizeHint() const;
private:
    QPushButton *addButton;
    QTabBar *TabBar;
    QStackedWidget *Stack;
    QVector<MyTab*> tabPointers;
    QVector<QString> matrixNames;
signals:
    void _sendSelectTab(QString name);
    void _sendAddSig();

    void _sendFirstMatrix(Matrix matrix);
    void _sendSecondMatrix(Matrix matrix);
    void _sendActiveMatrixName(QString);
    void _sendAllMatrixNames(QVector<QString>);
public slots:
    void _catchResultMatrix(Matrix newMatrix);

    void _closeTab(int index);
    void _addNewTab(QString name, int height, int width);
    void _currentChanged(int index);

    void _queryFirstMatrix(QString name);
    void _querySecondMatrix(QString name);
    void _queryActiveMatrixName();
    void _queryMatrixNames();
};

#endif // MYTABBAR_H
