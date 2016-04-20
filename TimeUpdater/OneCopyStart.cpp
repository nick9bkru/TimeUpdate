#include "OneCopyStart.h"


OneCopyStart::OneCopyStart( const QString name )
{
    sema = new QSystemSemaphore ( name + "_sem", 1);
    sema->acquire();

    {
        QSharedMemory shmem(name + "_mem");
        shmem.attach();
    }
    shmem = new QSharedMemory(name + "_mem");
    if (shmem->attach())
    {
        isRunning = true;
    }
    else
    {
        shmem->create(1);
        isRunning = false;
    }

    sema->release();
}

OneCopyStart::~OneCopyStart()
{
    delete shmem;
    delete sema;
}

bool OneCopyStart::isRun() const
{
  return isRunning;
};
