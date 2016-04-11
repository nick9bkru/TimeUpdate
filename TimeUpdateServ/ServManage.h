#ifndef SERVMANAGE_H
#define SERVMANAGE_H
#include "UdpServ.h"
#include <QObject>
/**
 * @brief The ServManage class
 * класс выполняет всю работу: рием команд и отсылку результата обратно
 */
class ServManage : public QObject
{
    Q_OBJECT
public:
    explicit ServManage(const QString ip, const int port);
    ~ServManage();

signals:

public slots:
    /**
     * @brief recievCom
     * слот который ринемает , выполнят и отсылает результат обратно
     */
    void recievCom ();
private :
    /**
     * @brief serv
     * указатель на класс работающий с UDP окетом
     */
    UdpServ * serv;
};

#endif // SERVMANAGE_H
