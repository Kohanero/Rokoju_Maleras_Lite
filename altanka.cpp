#include "altanka.h"
#include"gracz.h"
Altanka::Altanka(QString path,Gra *gra, QGraphicsItem *parent) :Karta(path,gra,parent)
{
    moc=6;
}

bool Altanka::dzialanie(Gracz *g)
{
return true;
}

void Altanka::wybrano(QString)
{

}
