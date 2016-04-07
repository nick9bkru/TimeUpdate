#include "UdpClient.h"
#include <QDebug>
#include <QHostInfo>
#include <QByteArray>
#include <QNetworkInterface>

UdpClient::UdpClient( const QString ip, const int port )
{
    qDebug() << "UdpClient::UdpClient ip  ==" << ip << " port == " << port ;
    sock = new QUdpSocket ( );
    sock->bind( QHostAddress ( ip ) , port );
    connect( sock, SIGNAL( readyRead() ) , this, SIGNAL( RecvCommand () ) );
    connect( sock, SIGNAL( readyRead() ) , this, SLOT ( recieveMesSlot () ) );
}

UdpClient::~UdpClient()
{
    sock->close();
    delete sock;
};


QString UdpClient::getIp()
{
  QHostInfo info = QHostInfo::fromName( QHostInfo::localHostName() );
   QList<QHostAddress> listAddr= QNetworkInterface::allAddresses();
  for ( QList<QHostAddress>::iterator it = listAddr.begin() ; it != listAddr.end(); it++ )
  {
     if ( (*it).toString().contains("192.168.1."))
     {
          qDebug()<<" CommandSender::getIp() my ip == " << (*it).toString();
        return (*it).toString();
     }
  };
  return "";
};

bool UdpClient::sendMes( const QString &ip, const int &port, const QByteArray  & mess )
{
    qDebug() << "UdpServ::sendMes = " << mess ;
    return sock->writeDatagram( mess, mess.size() , QHostAddress ( ip ) , port );

};


UdpClient::dataRecieve &UdpClient::recieveMes()
{
    ret.data.resize( sock->pendingDatagramSize() );
    sock->readDatagram( ret.data.data(), ret.data.size(), &(ret.addr), &(ret.port) );
    qDebug() << "UdpServ::recieveMes() command =" << ret.data << " addr = " << ret.addr.toString() << " port == " << ret.port;
    return ret ;
};

void UdpClient::recieveMesSlot()
{
    recieveMes();
    emit RecvCommand ( ret );
};
