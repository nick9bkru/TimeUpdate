#include "MainWidjet.h"
#include <QDebug>
#include "Singleton.h"
#include "ServersIp.h"
#include <QMessageBox>

MainWidjet::MainWidjet(QWidget *parent) :
    QFrame(parent), Ui::MainWidjet()
{
    qDebug ()<< "MainWidjet::MainWidjet";
    setupUi( this );
    move ( 1600 , 0);
    TimeEdit = new TimeDateEdit (TimeEditWidget );
    connect( SetTimeButton, SIGNAL ( clicked() ), this, SLOT( setTimeSlot() ) );
    udpSender = new UdpClient ( UdpClient::getIp(), PORT );
    Result = new ResFrame ( this->ResWidget );
    connect( udpSender, SIGNAL( RecvCommand ( const UdpClient::dataRecieve & ) ), Result , SLOT ( SetRes( const UdpClient::dataRecieve & ) ) );
    connect( QuitButton, SIGNAL ( clicked() ), this, SLOT(close() )) ;
}

MainWidjet::~MainWidjet()
{
}

void MainWidjet::setTimeSlot()
{
    qDebug ()<< "MainWidjet::setTimeSlot()";
    QByteArray buf;
    try
    {
     buf= TimeEdit->getTimeStr().toUtf8();
     Result->resetColor();
     QMap <QString , QString> *serv = Util::Singleton<ServersIp>::getInstance().getMap();
     for ( QMap <QString , QString> ::iterator it = serv->begin(); it != serv->end(); it++ )
     {
         udpSender->sendMes( it.key(), PORT+1, buf);
     }
    }
    catch( const QString & str )
    {
        QMessageBox::warning( this, QString::fromUtf8("Ошибка") , QString::fromUtf8("Введена не корректная дата !!"),QMessageBox::Ok );
        qDebug() << " ERROR !!!! === " << str;
    };

}
