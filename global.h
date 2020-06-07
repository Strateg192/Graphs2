#ifndef GLOBAL_H
#define GLOBAL_H

#include <QVector>
#include <QWidget>
#include <iostream>
#include <future>
#include <QThread>
#include <QDebug>

class GLOBAL
{
public:
    GLOBAL();
    static void addNewOpenWidget(QWidget *wd);
private:
    static void deleteClosedWidet();
    static QVector<QWidget *> allOpenWidget;
};

#endif // GLOBAL_H
