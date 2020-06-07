#include "tba.h"

TbA::TbA()
{    
    this->myTbA = new MyTbA(5);
    this->maingrid->addWidget(this->myTbA, 1, 0, 1, 2);

    this->sourceId = new QLineEdit(this);
    this->sourceId->setFixedSize(100, 25);
    QFont font = this->sourceId->font();
    font.setPointSize(14);
    this->sourceId->setFont(font);
    this->sourceId->setMaxLength(10);
    this->hbox->addWidget(this->sourceId);

    QPushButton *btn = new QPushButton("Взять исходные\nданные", this);
    this->hbox->addWidget(btn);
    connect(btn, &QPushButton::clicked, this, &TbA::fromMxA);

    this->cbCountNodes = new QComboBox(this);
    this->hbox->addWidget(this->cbCountNodes);
    for(int i = 1; i < 51; ++i)
    {
        this->cbCountNodes->addItem(QString::number(i));
    }
    connect(this->cbCountNodes, QOverload<int>::of(&QComboBox::currentIndexChanged),
        [=](int rowColumn){ this->changeRowColumn(rowColumn); });
    this->cbCountNodes->setCurrentIndex(4);

    QSpacerItem *spacerItem = new QSpacerItem(0, 5, QSizePolicy::Expanding, QSizePolicy::Expanding);
    this->hbox->addSpacerItem(spacerItem);
}

void TbA::getMxA(double **&mx, int &rowColumn)
{
    this->myTbA->toMxA(mx, rowColumn);
}

void TbA::fromMxA(bool checked)
{
    int id = -1;
    bool result = false;
    id = this->sourceId->text().toInt(&result);
    if(!result)
    {
        return;
    }
    BaseModule *sourceModule = BaseModule::getBaseModule(id);
    if(sourceModule == nullptr)
    {
        return;
    }
    double **mx = nullptr;
    int rowColumn = -1;
    sourceModule->getMxA(mx, rowColumn);
    if(mx == nullptr || rowColumn <= 0)
    {
        return;
    }
    this->changeRowColumn(rowColumn);
    this->cbCountNodes->setCurrentIndex(rowColumn-1);
    this->myTbA->fromMxA(mx, rowColumn);
    delete[] mx;
}

void TbA::changeRowColumn(int rowColumn)
{
    this->myTbA->setRowColumn(rowColumn+1);
}
