#ifndef INSTRUKCJA_H
#define INSTRUKCJA_H
#include <QList>
#include "strona_ins.h"
#include<QGraphicsScene>
#include<QObject>
class Instrukcja:public QObject,public QList<Strona_ins*>
{
    Q_OBJECT
public:
    QGraphicsScene *sc;
    Instrukcja(QGraphicsScene *);
      QList<Strona_ins*>::iterator it;
    public slots:
    void ins(bool k);



};

#endif // INSTRUKCJA_H
