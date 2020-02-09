#ifndef RESULTDISPLAY_H
#define RESULTDISPLAY_H

#include <QWidget>
#include <QtWidgets>

class ResultDisplay : public QWidget
{
    Q_OBJECT
public:
    explicit ResultDisplay(QWidget *parent = nullptr);
private:
    QLabel *resultOutp;
    QPushButton *closeResOut;

signals:

public slots:
    void _displayText(QString text);
};

#endif // RESULTDISPLAY_H
