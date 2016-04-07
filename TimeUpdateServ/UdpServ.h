#ifndef UDPSERV_H
#define UDPSERV_H

#include <QObject>
#include <QUdpSocket>
#include <QString>
#include <QHostAddress>

class UdpServ : public QObject
{
    Q_OBJECT
public:
    explicit UdpServ(const QString ip, const int port );
    ~UdpServ();
    static QString getIp();
    QByteArray recieveMes();
    bool sendMes( const QByteArray  & mess );
signals:

public slots:
signals:
    void RecvCommand () ;
private:
    QUdpSocket * sock;
    QHostAddress lastAddr;
    quint16 lastPort;
};

#endif // UDPSERV_H
