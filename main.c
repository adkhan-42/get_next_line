#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int main(void)
{
    int fd;
    char *ret;
    fd =open("test.txt", O_RDONLY);
    if (fd<0)
    {
        printf("ERROR BITCH GIVE ME A FILE TO READ NOT THIS BS");
        return (0);
    }
    while ((ret = get_next_line(fd)) != NULL)
    {
        printf("The Line is [%s]",ret);
        free(ret);
    }
    close (fd);
    return (0);
}
