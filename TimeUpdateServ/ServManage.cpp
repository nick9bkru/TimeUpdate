#include "ServManage.h"
#include <QProcess>
#include <QDebug>

ServManage::ServManage(const QString ip, const int port )
{
    qDebug() << "ServManage::ServManage";
    serv = new UdpServ ( ip, port );
    connect( serv, SIGNAL ( RecvCommand() ), this,  SLOT( recievCom () ));
}

ServManage::~ServManage()
{
     delete serv;
};

void ServManage::recievCom ()
{
    qDebug() << "ServManage::recievCom ()";
    QByteArray com = serv->recieveMes();
  //  qDebug() << "Command == " << com;
    if ( !QProcess::execute ( com ) )
    {
        com += " --OK";
    }   else
    {
        com += " --ERROR";
    }
    serv->sendMes ( com );
};
