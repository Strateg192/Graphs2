#ifndef BASEMODULE_H
#define BASEMODULE_H

#include <QWidget>
#include <QGridLayout>
#include <QLabel>
#include <QCloseEvent>
#include <QHBoxLayout>
#include <QDebug>

class BaseModule : public QWidget
{
    Q_OBJECT
public:
    explicit BaseModule();
    int getId() const;
    virtual void getMxA(double **&mx, int &rowColumn);
    //virtual void fromMxA(const double const **mx, int rowColumn);
    static BaseModule* getBaseModule(qint32 id); //возвращает указатель на класс по его id
protected:
    QGridLayout *maingrid = nullptr;
    QHBoxLayout *hbox = nullptr;
    void closeEvent(QCloseEvent *event) override;
private:
    int id;
    static void addNewBaseModule(BaseModule* baseModule, qint32 &id); //добавляет новый экземпляр класса BaseModule в глобальный вектор
    static void deleteBaseModule(BaseModule* baseModule, qint32 id); /*
                                                                      * удаляет из списка указанный BaseModule,
                                                                      * используя либо указатель, если он не равен nullptr,
                                                                      * либо id
                                                                      */
    static QVector<BaseModule*> allIdBaseModules; //содержит все id экземпляров классов основанных на BaseModule
    static qint32 idPointer; //автоинкрементирующий id
};

#endif // BASEMODULE_H
