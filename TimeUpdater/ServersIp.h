#ifndef SERVERSIP_H
#define SERVERSIP_H

#include <QMap>
#include <QString>

/**
 * @brief The ServersIp class
 * класс со всеми рабочими местами и их названими
 */
class ServersIp
{
public:
    ServersIp();
    /**
     * @brief insert
     * добавить место
     * @param ip адрес
     * @param name название
     */
    void insert( QString ip, QString name );
    /**
     * @brief getName
     * получить имя
     * @param ip адрес
     * @return
     */
    QString getName ( const QString & ip) const;
    /**
     * @brief getMap получить указатель на QMAP
     * @return
     */
    QMap<QString, QString> *getMap();
private:
    QMap <QString , QString> serv;
};

#endif // SERVERSIP_H
