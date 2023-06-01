#include <iostream>
#include <pthread.h>
#include <unistd.h>

using std::cout;
using std::endl;

/**
 * 线程的本质就是 内核在进程中创建的新的 task_struct
 * 在Linux中没有真正的线程结构，是复用的进程的代码
 * 复用以后，同一个进程，具有多个task_struct，被称为轻量级进程（Low Weith Process）
 * 因为同属一个进程，有一个线程引发了软/硬异常，其余线程都会崩溃
 */

void *func1(void *agrs)
{
    while (true)
    {
        cout << "this is thread1" << endl;
        sleep(1);
    }
}
void *func2(void *agrs)
{
    while (true)
    {
        cout << "this is thread2" << endl;
        sleep(1);
    }
}

int main()
{
    pthread_t t1, t2;

    pthread_create(&t1, nullptr, func1, nullptr);
    pthread_create(&t2, nullptr, func2, nullptr);

    while (true)
    {
        std::cout << "this is main thread" << endl;
        sleep(1);
    }

    return 0;
}