#define QT42

#include "MainWidjet.h"
#include <QApplication>
#include "Singleton.h"
#include "ServersIp.h"
#ifndef QT42
#include "include/OneCopyStart.h"
#else
#include "include/qtsingleapplication.h"
#endif
/**
 * @brief insIp
 * устанавливаем все пары рабочих мест и IP дресов
 */
void insIp()
{
    Util::Singleton<ServersIp>::getInstance().insert("192.168.1.101", "ЦУУ1");
    Util::Singleton<ServersIp>::getInstance().insert("192.168.1.102", "ЦУУ2");
    Util::Singleton<ServersIp>::getInstance().insert("192.168.1.2", "РМО1");
    Util::Singleton<ServersIp>::getInstance().insert("192.168.1.3", "РМО2");
    Util::Singleton<ServersIp>::getInstance().insert("192.168.1.4", "РМО3");
    Util::Singleton<ServersIp>::getInstance().insert("192.168.1.6", "РМО4");
    Util::Singleton<ServersIp>::getInstance().insert("192.168.1.7", "РМДИ1");
    Util::Singleton<ServersIp>::getInstance().insert("192.168.1.8", "РМДИ2");
    Util::Singleton<ServersIp>::getInstance().insert("192.168.1.9", "РМИШ");
   // Util::Singleton<ServersIp>::getInstance().insert("192.168.1.199", "TEST");
}

int main(int argc, char *argv[])
{
#ifndef QT42
    OneCopyStart onecopy("Time Updater");
    if ( onecopy.isRun() )
    {
        qDebug() << "One copy already start !!!!!!!!!!";
        return -1;
    };
    QApplication a(argc, argv);
#else
    QtSingleApplication a(argc, argv);
    if ( a.sendMessage("Wake up!") )
    {
        qDebug() << "One copy already start !!!!!!!!!!";
        return -1;
    };
#endif
    insIp();

    MainWidjet w;
    w.show();

    return a.exec();
}
