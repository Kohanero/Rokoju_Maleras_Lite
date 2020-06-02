#ifndef UDPSOCKET_H
#define UDPSOCKET_H
#include<QUdpSocket>
#include<QObject>
#include<QGraphicsView>
class UdpSocket:public QObject
{
    Q_OBJECT
public:
    UdpSocket(QGraphicsView*,QObject *parent=0);

public slots:
    void readyRead();
    void send(QString,QHostAddress address=QHostAddress::Null);
    void addConnection(QString);
signals:
    void karta(int);
    void connected();
private:
    QUdpSocket *myudpsocket;
    QList<QHostAddress> allConnections;
    bool czekajNaAdresy=false;
};

#endif // UDPSOCKET_H
