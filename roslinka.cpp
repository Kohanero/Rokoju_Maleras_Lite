#include "roslinka.h"
#include"gracz.h"

Roslinka::Roslinka(QString path, Gra *gra,QGraphicsItem *parent) :Karta(path,gra,parent)
{
    moc=1;
}

bool Roslinka::dzialanie(Gracz *g)
{
return true;
}

void Roslinka::wybrano(QString)
{

}
