#include <iostream>
#include <pthread.h>
#include <unistd.h>
#include <sys/socket.h>
#include "lock.hpp"

using namespace std;

int g_val = 100000;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void *sub(void *args)
{
    string name = static_cast<char *>(args);
    for (int i = 0; i < 50000; i++)
    {
        {
            Lock lock(&mutex);

            std::cout << name << "running...." << std::endl;
            g_val--;
        }
    }
    return nullptr;
}

int main()
{
    pthread_t t1, t2;
    pthread_mutex_init(&mutex, nullptr);
    pthread_create(&t1, nullptr, sub, (void *)"thread1");
    pthread_create(&t2, nullptr, sub, (void *)"thread2");

    pthread_join(t1, nullptr);
    pthread_join(t2, nullptr);

    cout << g_val << endl;

    return 0;
}