#include "pierscien.h"
#include"gracz.h"
Pierscien::Pierscien(QString path,Gra *gra, QGraphicsItem *parent) :Karta(path,gra,parent)
{
    moc=4;
}

bool Pierscien::dzialanie(Gracz *g)
{
    g->ochrona=true;
    return true;
}

void Pierscien::wybrano(QString)
{

}
