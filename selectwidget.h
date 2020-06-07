#ifndef SELECTWIDGET_H
#define SELECTWIDGET_H

#include <QWidget>
#include <QGridLayout>
#include <QPushButton>
#include "tba.h"

class SelectWidget : public QWidget
{
    Q_OBJECT
public:
    explicit SelectWidget(QWidget *parent = nullptr);
public slots:
    void openTbA(bool checked);
    void openTbB(bool checked);
    void openGP(bool checked);
    void openGM(bool checked);
signals:

};

#endif // SELECTWIDGET_H
