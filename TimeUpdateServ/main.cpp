#include <QCoreApplication>
#include <QDebug>

#include <unistd.h>
#include "ServManage.h"

int main(int argc, char *argv[])
{
    if ( argc == 1)
        daemon(0,0);


    QCoreApplication a( argc, argv);
    qDebug() << "Start";
    ServManage serv ( /*UdpServ::getIp()*/ "192.168.1.199", 30000 );
    return a.exec();
}
