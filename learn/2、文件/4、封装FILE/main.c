#include "myFile.h"
#include <string.h>

int main()
{
    myFILE *fp = myfopen("./text.txt", "a");

    char *p = "this is a test\n";
    myfwrite(p, 1, strlen(p), fp);

    myfclose(fp);

    return 0;
}