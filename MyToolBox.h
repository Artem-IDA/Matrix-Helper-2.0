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
    QToolBox *ToolBox;
signals:
    void _sendRequestToLogic();
public slots:
    void _catchCurrent(int index);
};

#endif // MYTOOLBOX_H
