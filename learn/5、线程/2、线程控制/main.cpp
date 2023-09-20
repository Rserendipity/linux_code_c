#include <iostream>
#include <string>
#include <pthread.h>
#include <unistd.h>

using namespace std;

class ThreadData
{
public:
    ThreadData(int id, int from, int to) : _id(id), _from(from), _to(to) {}
    void caculate()
    {
        for (int i = _from; i <= _to; i++)
        {
            _result += i;
        }
    }

public:
    // 输入型
    int _id;
    int _from;
    int _to;

    // 输出型
    int _result = 0;
    int _state = 0;
};

const int NUM = 3;

void *thread_run(void *args)
{
    auto td = static_cast<ThreadData *>(args);
    cout << "thread running..."
         << "id:" << td->_id << endl;
    td->caculate();

    return td;
}

int main()
{
    pthread_t ths[NUM];
    for (int i = 0; i < NUM; i++)
    {
        auto td = new ThreadData(i + 1, 0, 10 * i + 10);
        pthread_create(&ths[i], nullptr, thread_run, td);
    }

    for (int i = 0; i < NUM; i++)
    {
        ThreadData *ret = 0;
        pthread_join(ths[i], reinterpret_cast<void **>(&ret));
        cout << ret->_result << endl;
        delete ret;
    }

    return 0;
}