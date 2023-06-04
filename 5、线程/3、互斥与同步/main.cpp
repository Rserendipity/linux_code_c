#include <iostream>
#include <pthread.h>
#include <unistd.h>
#include <sys/socket.h>

using namespace std;

int g_val = 100000;
pthread_mutex_t mutex;

// /**
//  * 没有保护的访问并修改共享资源，会导致并发的数据更新不及时
//  * 即最终的结果不正确，加锁可以解决这个问题
//  */
// void *sub(void *args)
// {
//     for (int i = 0; i < 50000; i++)
//         g_val--;
//     return nullptr;
// }

void *sub(void *args)
{
    string name = static_cast<char *>(args);
    for (int i = 0; i < 50000; i++)
    {
        pthread_mutex_lock(&mutex);
        cout << name << "running...." << endl;
        g_val--;
        pthread_mutex_unlock(&mutex);
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