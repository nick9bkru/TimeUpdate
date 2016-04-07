#include "ServersIp.h"

ServersIp::ServersIp()
{
}

void ServersIp::insert( QString ip, QString name )
{
    serv.insert( ip, name  );
};

QString ServersIp::getName ( const QString & ip) const
{
    return serv[ ip ];
};

QMap<QString , QString> *ServersIp::getMap()
{
  return &serv;
};
