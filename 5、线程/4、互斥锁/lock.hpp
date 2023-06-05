#include <pthread.h>

class Lock
{
public:
    Lock(pthread_mutex_t *lock) : _lock(lock)
    {
        pthread_mutex_lock(_lock);
    }
    ~Lock()
    {
        pthread_mutex_unlock(_lock);
    }

private:
    pthread_mutex_t *_lock;
};