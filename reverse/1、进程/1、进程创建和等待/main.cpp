#include "sys/types.h"
#include "sys/wait.h"
#include "unistd.h"
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sys/wait.h>

using func_t = void (*)();

int main()
{
    // create a child process and print something.
    // the father process wait(nohang) him and excete father's code.

    pid_t id = fork();
    assert(id >= 0);

    if (id == 0)
    {
        // child
        for (int i = 0; i < 5; i++)
        {
            printf("child, pid:[%d], time:[%d]\n", getpid(), i + 1);
            sleep(1);
        }
        return 111;
    }
    else
    {
        // father
        int state = 0;
        // wait for child until it dead.
        // otherwide, make other thing.
        pid_t childid = 0;
        while ((childid = waitpid(id, &state, WNOHANG)) == 0)
        {
            // something to do.
            printf("parent is doing something, pid:[%d]\n", getpid());
            sleep(1);
        }

        printf("pid:[%d] waitpid:[%d]\n", getpid(), childid);
        if (WIFEXITED(state))
        {
            printf("child end. the exit code is [%d]\n", WEXITSTATUS(state));
        }
        else
        {
            printf("child send a sign:[%d]\n", state & 0x7f);
        }
    }

    return 0;
}