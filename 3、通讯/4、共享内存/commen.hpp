#include <string>
#include <iostream>
#include <cassert>
#include <cstring>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <fcntl.h>

// 定义路径+项目id  作为key的获取
std::string path = ".";
const int project_id = 8;

class shared_memory
{
public:
    // 定义端口id
    enum port_id
    {
        click = 0,
        server = 1
    };

public:
    shared_memory(port_id id, size_t size = 1024)
    {
        _key = ftok(path.data(), project_id);
        _id = id;
        _size = size;
        umask(0);
        if (_id == click) // 用户端，只需要拿到共享内存
        {
            create_memory(_key, size, IPC_CREAT | 0777);
        }
        else // 服务端，创建并拿到内存，创建失败会报错
        {
            create_memory(_key, size, IPC_CREAT | IPC_EXCL | 0777);
        }
    }

    ~shared_memory()
    {
        // 都要取消和共享内存的连接
        shmdt(_shmptr);

        // 如果是服务端，需要销毁共享内存
        if (_id == server)
        {
            int ret = shmctl(_shmid, IPC_RMID, 0);
            assert(ret != -1);
        }
    }

    void *getMemory() const noexcept
    {
        return _shmptr;
    }

private:
    void create_memory(key_t key, size_t size, int mode)
    {
        _shmid = shmget(key, size, mode);
        assert(_shmid != -1);
        _shmptr = shmat(_shmid, nullptr, 0);
    }

    void *_shmptr;
    port_id _id;
    key_t _key;
    size_t _size;
    int _shmid;
};
