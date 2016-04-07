#ifndef SERVMANAGE_H
#define SERVMANAGE_H
#include "UdpServ.h"
#include <QObject>

class ServManage : public QObject
{
    Q_OBJECT
public:
    explicit ServManage(const QString ip, const int port);

signals:

public slots:
    void recievCom ();
private :
    UdpServ * serv;
};

#endif // SERVMANAGE_H
