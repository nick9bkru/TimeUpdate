#ifndef UDPSERV_H
#define UDPSERV_H

#include <QObject>
#include <QUdpSocket>
#include <QString>
#include <QHostAddress>

/**
 * @brief The UdpServ class
 * обертка класса для работы с UDP сокетов
 */
class UdpServ : public QObject
{
    Q_OBJECT
public:
    /**
     * @brief UdpServ
     * @param ip мой Ip адрес
     * @param port порт для принятия и отправки сообщений
     */
    explicit UdpServ(const QString ip, const int port );
    ~UdpServ();
    /**
     * @brief getIp
     * @return  получаем свой IP
     */
    static QString getIp();
    /**
     * @brief recieveMes
     * получаем принятое сообщения
     * @return
     */
    QByteArray recieveMes();
    /**
     * @brief sendMes
     * @param mess отсылаем сообщение
     * @return
     */
    bool sendMes( const QByteArray  & mess );
signals:

public slots:
signals:
    /**
     * @brief RecvCommand
     * сигнал о приеме сообщения
     */
    void RecvCommand () ;
private:
    /**
     * @brief sock
     * сокет
     */
    QUdpSocket * sock;
    /**
     * @brief lastAddr
     * адрес от которого получили сообщение
     */
    QHostAddress lastAddr;
    /**
     * @brief lastPort
     * порт с которого получили сообщение
     */
    quint16 lastPort;
};

#endif // UDPSERV_H
