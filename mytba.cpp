#include "mytba.h"


MyTbA::MyTbA()
{
}
MyTbA::MyTbA(int rowColumn) :
    QTableWidget(rowColumn, rowColumn)
{
    for(int i = 0; i < rowColumn; ++i)
    {
        this->setColumnWidth(i, 10);
    }
    for(int i =0 ; i  < rowColumn; ++i)
    {
        for(int j = 0 ; j < rowColumn; ++j)
        {
            QVariant value(QString::number(0));
            QTableWidgetItem *tmpItem = new QTableWidgetItem();
            tmpItem->setData(Qt::DisplayRole, value);
            tmpItem->setTextAlignment(Qt::AlignCenter);
            this->setItem(i, j, tmpItem);
        }
    }
}

void MyTbA::setRowColumn(int rowColumn)
{
    this->baseSetRowAndColumn(rowColumn);
}

void MyTbA::toMxA(double **&matrix, int &rowColumn)
{
    int tmpRowsColumns = this->rowCount();
    rowColumn = tmpRowsColumns;
    matrix = new double*[tmpRowsColumns];
    for(int i = 0; i < tmpRowsColumns; ++i)
    {
        matrix[i] = new double[tmpRowsColumns];
        for(int j = 0; j < this->columnCount(); ++j)
        {
            matrix[i][j] = this->item(i, j)->text().toDouble();
        }
    }
}

void MyTbA::fromMxA(double **matrix, int rowColumn)
{
    this->baseSetRowAndColumn(rowColumn);
    for(int i = 0; i < rowColumn; ++i)
    {
        for(int j = 0; j < rowColumn; ++j)
        {
            this->item(i, j)->setText(QString::number(matrix[i][j]));
        }
    }
}

void MyTbA::baseSetRowAndColumn(int count)
{
    if(count < this->columnCount())
    {
        this->setColumnCount(count);
        this->setRowCount(count);
    }
    else if(count > this->columnCount())
    {
        int beforeRow = this->rowCount();
        this->setRowCount(count);
        for(int i = beforeRow; i < this->rowCount(); ++i)
        {
            for(int j = 0; j < this->columnCount(); ++j)
            {
                QVariant value(QString::number(0));
                QTableWidgetItem *tmpItem = new QTableWidgetItem();
                tmpItem->setData(Qt::DisplayRole, value);
                tmpItem->setTextAlignment(Qt::AlignCenter);
                this->setItem(i, j, tmpItem);
            }
        }
        int beforeColumn = this->columnCount();
        this->setColumnCount(count);
        for(int i = 0 ; i < this->rowCount(); ++i)
        {
            for(int j = beforeColumn; j < this->columnCount(); ++j)
            {
                QVariant value(QString::number(0));
                QTableWidgetItem *tmpItem = new QTableWidgetItem();
                tmpItem->setData(Qt::DisplayRole, value);
                tmpItem->setTextAlignment(Qt::AlignCenter);
                this->setItem(i, j, tmpItem);
            }
        }
        for(int j = beforeColumn-1; j < this->columnCount(); ++j)
        {
            this->setColumnWidth(j, 10);
        }
    }
}
