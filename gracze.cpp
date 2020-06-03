#include "gracze.h"

Gracze::Gracze(Gracz* g):QList<Gracz *>()
{
    push_front(g);
    it=begin();
}

QString Gracze::nastepnyGracz()
{
    if(it==end())  it=begin();
    Gracz *g=*it;
    it++;
    return g->getNazwa();
}
