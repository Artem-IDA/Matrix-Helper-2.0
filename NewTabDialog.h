#ifndef NEWTABDIALOG_H
#define NEWTABDIALOG_H

#include <QWidget>
#include <QtWidgets>

class NewTabDialog : public QDialog
{
     Q_OBJECT
private:
    QLineEdit *lineEdit;
    QSpinBox *heightSB;
    QSpinBox *widthSB;
public:
    NewTabDialog(QWidget *parent = nullptr);

    QString getText() const;
    int getHeight() const;
    int getWidth() const;
};

#endif // NEWTABDIALOG_H
