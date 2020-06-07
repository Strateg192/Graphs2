#include "basemodule.h"

BaseModule::BaseModule()
{
    BaseModule::addNewBaseModule(this, this->id);
    this->setAttribute(Qt::WidgetAttribute::WA_DeleteOnClose);

    this->maingrid = new QGridLayout(this);
    this->setLayout(this->maingrid);

    QLabel *labelId = new QLabel(QString::number(this->id), this);
    QFont tmpFont(labelId->font().family(), 14, QFont::Bold);
    labelId->setFont(tmpFont);
    this->maingrid->addWidget(labelId, 0, 1, Qt::AlignRight);

    this->hbox = new QHBoxLayout();
    this->hbox->setSpacing(1);
    this->maingrid->addLayout(this->hbox, 0, 0, Qt::AlignmentFlag::AlignLeft);
}

int BaseModule::getId() const
{
    return this->id;
}

void BaseModule::getMxA(double **&mx, int &rowColumn)
{
    mx = nullptr;
    rowColumn = -1;
}

BaseModule* BaseModule::getBaseModule(qint32 id)
{
    int count = BaseModule::allIdBaseModules.count();
    for(int i = 0; i < count; ++i)
    {
        if(BaseModule::allIdBaseModules[i]->getId() == id)
        {
            return BaseModule::allIdBaseModules[i];
        }
    }
    return nullptr;
}

void BaseModule::closeEvent(QCloseEvent *event)
{
    BaseModule::deleteBaseModule(this, -1);
    event->accept();
}

void BaseModule::addNewBaseModule(BaseModule* baseModule, qint32 &id)
{
    BaseModule::allIdBaseModules.push_back(baseModule);
    id = BaseModule::idPointer;
    BaseModule::idPointer++;
}

void BaseModule::deleteBaseModule(BaseModule *baseModule, qint32 id)
{
    int count = BaseModule::allIdBaseModules.count();
    if(baseModule != nullptr)
    {
        for(int i = 0; i < count; ++i)
        {
            if(BaseModule::allIdBaseModules[i] == baseModule)
            {
                BaseModule::allIdBaseModules.removeAt(i);
                return;
            }
        }
    }
    else if (id > -1)
    {
        for(int i = 0; i < count; ++i)
        {
            if(BaseModule::allIdBaseModules[i]->getId() == id)
            {
                BaseModule::allIdBaseModules.removeAt(i);
                return;
            }
        }
    }
}

QVector<BaseModule*> BaseModule::allIdBaseModules(0);
qint32 BaseModule::idPointer = 0;
