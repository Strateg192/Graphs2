#include "global.h"

GLOBAL::GLOBAL()
{
    std::async(GLOBAL::deleteClosedWidet);
}
QVector<QWidget *> GLOBAL::allOpenWidget(10);
void GLOBAL::addNewOpenWidget(QWidget *wd)
{
    GLOBAL::allOpenWidget.push_back(wd);
}

void GLOBAL::deleteClosedWidet()
{
    while(true)
    {
        int count = GLOBAL::allOpenWidget.count();
        for(int i = 0; i < count; ++i)
        {
            if(GLOBAL::allOpenWidget[i]->isVisible() == false)
            {
                delete GLOBAL::allOpenWidget[i];
                GLOBAL::allOpenWidget.removeAt(i);
                --i;
            }
        }
        qDebug() << "1";
    }
}
