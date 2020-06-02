#include "kaczor.h"
#include"gracz.h"

Kaczor::Kaczor(QString path,Gra *gra, QGraphicsItem *parent) :Karta(path,gra,parent)
{
    moc=3;
}

bool Kaczor::dzialanie(Gracz *g)
{

return true;
}

void Kaczor::wybrano(QString)
{

}
