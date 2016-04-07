#ifndef SERVERSIP_H
#define SERVERSIP_H

#include <QMap>
#include <QString>

class ServersIp
{
public:
    ServersIp();
    void insert( QString ip, QString name );
    QString getName ( const QString & ip) const;
    QMap<QString, QString> *getMap();
private:
    QMap <QString , QString> serv;
};

#endif // SERVERSIP_H
