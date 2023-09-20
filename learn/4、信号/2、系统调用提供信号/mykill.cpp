#include <iostream>
#include <signal.h>
#include <unistd.h>

void usage()
{
    std::cout << "mykill [signal] [pid]" << std::endl;
    exit(-1);
}

int main(int argc, char const *argv[])
{
    if (argc != 3)
    {
        usage();
    }

    int signal = atoi(argv[1]);
    int pid = atoi(argv[2]);
    kill(pid, signal);
    return 0;
}
