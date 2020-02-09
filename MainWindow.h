#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QtWidgets>
#include <Matrix.h>
#include "NewTabDialog.h"
#include "MatrixInwidget.h"
#include "MatrixDisplaywidget.h"
#include "MatrixLogic.h"
#include "MyTabBar.h"
#include "MyToolBox.h"
#include "ResultDisplay.h"

class MainWindow : public QWidget
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);
private:
    NewTabDialog *newTabDialog;
    ResultDisplay *resultDis;

    QLabel *emptyTab;

    QGridLayout *mainLay;
signals:
    void _tabCreated(QString name, int height, int width);
    void _displayText(QString text);
public slots:
    void _addingNewTab();
    void _displayOtherResult(QString text);
    void _closeOtherResult();
};

#endif // MAINWINDOW_H

