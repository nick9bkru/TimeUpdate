#include "UdpServ.h"

#include <QHostInfo>
#include <QDebug>
#include <QByteArray>
#include <QNetworkInterface>

UdpServ::UdpServ(const QString ip, const int port ) :lastPort(0)
{
    qDebug() << "UdpServ::UdpServ ip  ==" << ip << " port == " << port ;
    sock = new QUdpSocket ( );
    sock->bind( QHostAddress ( ip ) , port );
    connect( sock, SIGNAL( readyRead() ) , this, SIGNAL( RecvCommand () ) );
}


UdpServ::~UdpServ()
{
 sock->close();
 delete sock;
};

bool UdpServ::sendMes(const QByteArray  & mess )
{
    qDebug() << "UdpServ::sendMes = " << mess ;
    if ( lastPort )
            return sock->writeDatagram( mess, mess.size() , lastAddr , lastPort );
     else return 0;
};


QByteArray UdpServ::recieveMes()
{
    QByteArray data;
    data.resize( sock->pendingDatagramSize() );
    sock->readDatagram( data.data(), data.size(),&lastAddr, &lastPort  );
    qDebug() << "UdpServ::recieveMes() command =" << data << " addr = " << lastAddr.toString() << " port == " << lastPort;
    return data ;
};

QString UdpServ::getIp()
{
  QHostInfo info = QHostInfo::fromName( QHostInfo::localHostName() );
   QList<QHostAddress> listAddr= QNetworkInterface::allAddresses();
  for ( QList<QHostAddress>::iterator it = listAddr.begin() ; it != listAddr.end(); it++ )
  {
     if ( (*it).toString().contains("192.168.1.") && ((*it).toString() != "192.168.1.1") )
     {
          qDebug()<<" CommandSender::getIp() my ip == " << (*it).toString();
        return (*it).toString();
     }
  };
  return "";
};
