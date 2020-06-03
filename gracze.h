#ifndef GRACZE_H
#define GRACZE_H
#include<QList>
#include"gracz.h"
class Gracze: public QList<Gracz*>
{
public:
    Gracze(Gracz*);
    QString nastepnyGracz();
private:
    QList<Gracz*>::iterator it=0;
};

#endif // GRACZE_H
