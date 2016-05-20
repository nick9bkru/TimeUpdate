#ifndef ONECOPYSTART_H
#define ONECOPYSTART_H
#include <QSystemSemaphore>
#include <QSharedMemory>
#include <QString>
/**
 * @brief The OneCopyStart class
 * класс применяется для проверки запущенно ли уже приложение
 * ( необходимо сохранять экземпляр класса до конца работы программы )
 */
class OneCopyStart
{
public:
    /**
     * @brief OneCopyStart
     * @param name название приложение
     */
    OneCopyStart( const QString name );
    ~OneCopyStart();
    /**
     * @brief isRun запущен ли уже один экземпляр
     * @return
     */
    bool isRun() const;
private:
    bool isRunning;
    QSharedMemory * shmem;
    QSystemSemaphore *sema;
};

#endif // ONECOPYSTART_H
