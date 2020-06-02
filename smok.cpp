#include "smok.h"
#include"gracz.h"
Smok::Smok(QString path,Gra *gra, QGraphicsItem *parent) :Karta(path,gra,parent)
{
    moc=7;
}

bool Smok::dzialanie(Gracz *g)
{
return true;
}

void Smok::wybrano(QString)
{

}
