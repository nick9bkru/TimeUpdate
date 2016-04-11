#ifndef UDPCLIENT_H
#define UDPCLIENT_H

#include <QObject>
#include <QUdpSocket>
#include <QString>
#include <QHostAddress>

/**
 * @brief The UdpClient class
 * обертка для работы с UDP сокетом
 */
class UdpClient : public QObject
{
    Q_OBJECT
public:
    /**
     * @brief The dataRecieve struct
     * структура с приемной инф
     */
    struct dataRecieve
    {
        QByteArray data;
        QHostAddress addr;
        quint16 port;
    };
    typedef struct dataRecieve dataRecieve;

    /**
     * @brief UdpClient
     * @param ip мой IP
     * @param port приемный порт
     */
    explicit UdpClient( const QString ip, const int port );
    ~UdpClient();
    /**
     * @brief getIp
     * получаем мой IP
     * @return
     */
    static QString getIp();
    /**
     * @brief recieveMes
     *
     * @return
     */
    dataRecieve &recieveMes();
    /**
     * @brief sendMes посылаем строку
     * @param ip куда посылаем
     * @param port на порт
     * @param mess  сообщение
     * @return
     */
    bool sendMes( const QString &ip, const int &port, const QByteArray  & mess );
signals:
    /**
     * @brief RecvCommand
     * игнал о приеме сообщения
     */
    void RecvCommand () ;
    /**
     * @brief RecvCommand
     * игнал о приеме сообщения
     */
    void RecvCommand ( const UdpClient::dataRecieve & ) ;
private slots:
    /**
     * @brief recieveMesSlot
     * слот о длот для приема сообщения и вырабатывает сигнал RecvCommand ( const UdpClient::dataRecieve & ) ;
     */
    void recieveMesSlot();
private:
    /**
     * @brief sock
     * указатель на класс управления сокетом
     */
    QUdpSocket * sock;
    /**
     * @brief ret
     * принятая инф-я
     */
    dataRecieve ret;
};

#endif // UDPCLIENT_H
