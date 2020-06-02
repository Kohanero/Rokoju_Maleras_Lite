#ifndef GRACZ_H
#define GRACZ_H

#include"karta.h"

class Gra;

class Gracz :public QObject
{
    Q_OBJECT
public:
    Gracz(Gra *gra,QString nazwa);
    Karta* dobierz();
    bool tura=false;
    Karta *k1=nullptr;
    Karta *k2=nullptr;
    bool ochrona=false;
    bool poloczony;
    QString getNazwa();
public slots:
    void zagraj(Karta *k);
private:
    Gra *gra;
    short punkty;
    QString nazwa;

};

#endif // GRACZ_H
