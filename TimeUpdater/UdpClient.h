#ifndef UDPCLIENT_H
#define UDPCLIENT_H

#include <QObject>
#include <QUdpSocket>
#include <QString>
#include <QHostAddress>

class UdpClient : public QObject
{
    Q_OBJECT
public:
    struct dataRecieve
    {
        QByteArray data;
        QHostAddress addr;
        quint16 port;
    };
    typedef struct dataRecieve dataRecieve;

    explicit UdpClient( const QString ip, const int port );
    ~UdpClient();
    static QString getIp();
    dataRecieve &recieveMes();
    bool sendMes( const QString &ip, const int &port, const QByteArray  & mess );
signals:
    void RecvCommand () ;
    void RecvCommand ( const UdpClient::dataRecieve & ) ;
private slots:
    void recieveMesSlot();
private:
    QUdpSocket * sock;
    dataRecieve ret;
};

#endif // UDPCLIENT_H
