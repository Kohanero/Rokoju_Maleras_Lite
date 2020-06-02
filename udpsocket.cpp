#include "udpsocket.h"
#include<QNetworkInterface>
#include<QHostAddress>
#include<QDebug>
UdpSocket::UdpSocket(QGraphicsView *viev,QObject *parent):QObject(parent)
{
    myudpsocket=new QUdpSocket(this);
    //myudpsocket->bind(QHostAddress("25.150.240.229"),1234);
    myudpsocket->bind(QHostAddress::Any,1234);
    connect(myudpsocket,SIGNAL(readyRead()),this,SLOT(readyRead()));



}

void UdpSocket::addConnection(QString address)
{
    QByteArray data;
    data.append("connect");
    myudpsocket->writeDatagram(data,QHostAddress(address),1234);
}

void UdpSocket::readyRead()
{
    QByteArray buffer;
    QHostAddress sender;
    buffer.resize(myudpsocket->pendingDatagramSize());
    unsigned short int port;
    myudpsocket->readDatagram(buffer.data(),buffer.size(),&sender,&port);
    if(czekajNaAdresy)
    {
        if(buffer=="koniec")
        {
            czekajNaAdresy=false;
            qDebug()<<allConnections.size();
            emit connected();
            return;
        }
        QHostAddress newAddress(buffer.data());
        bool t = true;
        for(QHostAddress address:allConnections)
            if(address==newAddress)
            {
                t=false;
                break;
            }
        if(t) allConnections.push_front(newAddress);

    }
    bool t=false;
    if(buffer=="connect")
    {
        t=true;
        send("connected");
        for(QHostAddress address:allConnections)
            if(sender!=address) send(address.toString(),sender);
        send("koniec");
    }
    if(buffer=="connected")
    {
        t=true;
        czekajNaAdresy=true;
    }
    if(t) for(QHostAddress address:allConnections)
            if(address==sender)
            {
                t=false;
                break;
            }
    if(t) allConnections.push_front(sender);
    if(buffer=="disconnect") allConnections.removeOne(sender);
    int a=buffer.toInt();
    if(a!=0)
        emit karta(a);
}

void UdpSocket::send(QString messege, QHostAddress address)
{
    QByteArray data;
    data.append(messege);
    if(address!=QHostAddress::Null) qDebug()<<myudpsocket->writeDatagram(data,address,1234);
    for(QHostAddress address:allConnections) qDebug()<<myudpsocket->writeDatagram(data,address,1234);

}

