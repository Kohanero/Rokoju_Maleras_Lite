#include "skarb.h"
#include"gracz.h"
Skarb::Skarb(QString path,Gra *gra, QGraphicsItem *parent) :Karta(path,gra,parent)
{
    moc=8;
}

bool Skarb::dzialanie(Gracz *g)
{
return true;
}

void Skarb::wybrano(QString)
{

}
