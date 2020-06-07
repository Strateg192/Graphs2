#ifndef TBA_H
#define TBA_H

#include "basemodule.h"
#include "mytba.h"
#include <QLineEdit>
#include <QPushButton>
#include <QComboBox>
#include <QSpacerItem>

class TbA : public BaseModule
{
    Q_OBJECT
public:
    TbA();
    void getMxA(double **&mx, int &rowColumn) override;
private slots:
    void fromMxA(bool checked);
    void changeRowColumn(int rowColumn);
private:
    MyTbA *myTbA;
    QLineEdit *sourceId = nullptr;
    QComboBox *cbCountNodes = nullptr;
};

#endif // TBA_H
