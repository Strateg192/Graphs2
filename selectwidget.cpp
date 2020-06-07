#include "selectwidget.h"

SelectWidget::SelectWidget(QWidget *parent) : QWidget(parent)
{
    QGridLayout *grid = new QGridLayout(this);
    this->setLayout(grid);
    this->setAttribute(Qt::WidgetAttribute::WA_DeleteOnClose);

    QPushButton *btA = new QPushButton("A", this);
    grid->addWidget(btA, 0, 0);
    connect(btA, &QPushButton::clicked, this, &SelectWidget::openTbA);

    QPushButton *btB = new QPushButton("B", this);
    grid->addWidget(btB, 0, 1);
    QPushButton *btGP = new QPushButton("G+", this);
    grid->addWidget(btGP, 1, 0);
    QPushButton *btGM = new QPushButton("G-", this);
    grid->addWidget(btGM, 1, 1);
    QPushButton *btH = new QPushButton("Иерархия", this);
    grid->addWidget(btH, 2, 0, 1, 2);
    QPushButton *btS = new QPushButton("Подсиситемы", this);
    grid->addWidget(btS, 3, 0, 1, 2);
    QPushButton *btShowGraph = new QPushButton("Отобразить граф", this);
    grid->addWidget(btShowGraph, 4, 0, 1, 2);
    QPushButton *btLines = new QPushButton("Матрица расстояний", this);
    grid->addWidget(btLines, 5, 0, 1, 2);
    QPushButton *btShortLine = new QPushButton("Матрица кратчайших\nрасстоний", this);
    grid->addWidget(btShortLine, 6, 0, 1, 2);
    QPushButton *btDegreeCentralization = new QPushButton("Степень централизации", this);
    grid->addWidget(btDegreeCentralization, 7, 0, 1, 2);

}

void SelectWidget::openTbA(bool checked)
{
    TbA *tbA = new TbA();
    tbA->show();
}
void SelectWidget::openTbB(bool checked)
{

}
void SelectWidget::openGP(bool checked)
{

}
void SelectWidget::openGM(bool checked)
{

}
