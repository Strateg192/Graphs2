#ifndef MYTBA_H
#define MYTBA_H

#include <QTableWidget>

class MyTbA : public QTableWidget
{
    Q_OBJECT
public:
    explicit MyTbA();
    explicit MyTbA(int rowColumn);
    void setRowColumn(int rowColumn);
    void toMxA(double **&matrix, int &rowColumn);
    void fromMxA(double **matrix, int rowColumn);
    //~MyTableA();
private:
    void baseSetRowAndColumn(int count);
};

#endif // MYTBA_H
