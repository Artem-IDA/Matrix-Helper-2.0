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
    QVector<int> indexVector;
    QVector<QString> matrixNames;
signals:
    void _sendSelectTab(QString name);
    void _sendAddSig();

    void _sendAllMatrixNames(QVector<QString>);
public slots:
    void _closeTab();
    void _addNewTab(QString name, int height, int width);
    void _currentChanged(int index);

    void _queryMatrixNames();
};

#endif // MYTABBAR_H
