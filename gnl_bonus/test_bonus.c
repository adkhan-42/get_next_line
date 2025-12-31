#include <fcntl.h>
#include <stdio.h>
#include "get_next_line_bonus.h"

int main(void)
{
    int fd1, fd2, fd3;
    char *line;

    // 1. Open all files simultaneously
    fd1 = open("file1.txt", O_RDONLY);
    fd2 = open("file2.txt", O_RDONLY);
    fd3 = open("file3.txt", O_RDONLY);

    if (fd1 == -1 || fd2 == -1 || fd3 == -1)
    {
        printf("Error opening files. Make sure file1.txt, file2.txt, file3.txt exist.\n");
        return (1);
    }

    printf("===================================================\n");
    printf("TESTING BONUS: Interleaved Reading (FD %d, %d, %d)\n", fd1, fd2, fd3);
    printf("===================================================\n\n");

    // Round 1: Read Line 1 from everyone
    line = get_next_line(fd1);
    printf("FD %d: [%s]", fd1, line); // Expected: File_1_Line_1
    free(line);

    line = get_next_line(fd2);
    printf("FD %d: [%s]", fd2, line); // Expected: File_2_Line_1
    free(line);

    line = get_next_line(fd3);
    printf("FD %d: [%s]", fd3, line); // Expected: File_3_Line_1
    free(line);
    
    printf("\n--- Context Switch ---\n\n");

    // Round 2: Read Line 2 from everyone
    // If your linked list is broken, these will be garbage or mixed up!
    line = get_next_line(fd1);
    printf("FD %d: [%s]", fd1, line); // Expected: File_1_Line_2
    free(line);

    line = get_next_line(fd2);
    printf("FD %d: [%s]", fd2, line); // Expected: File_2_Line_2
    free(line);

    line = get_next_line(fd3);
    printf("FD %d: [%s]", fd3, line); // Expected: File_3_Line_2
    free(line);

    printf("\n--- Context Switch ---\n\n");

    // Round 3: Read Line 3 from everyone
    line = get_next_line(fd1);
    printf("FD %d: [%s]", fd1, line);
    free(line);

    line = get_next_line(fd2);
    printf("FD %d: [%s]", fd2, line);
    free(line);

    line = get_next_line(fd3);
    printf("FD %d: [%s]", fd3, line);
    free(line);

    // Cleanup
    close(fd1);
    close(fd2);
    close(fd3);

    char *ret;
    int fd4 = open("file4.txt", O_RDONLY);
    if (fd4<0)
    {
        printf("ERROR BITCH GIVE ME A FILE TO READ NOT THIS BS");
        return (0);
    }
    int count = 0;
    while ((ret = get_next_line(fd4)) != NULL)
    {

        printf("%d, The Line is [%s]",count,ret);
        count++;
        free(ret);
    }
    printf("total lines read = %d\n",count);
    close (fd4);

    return (0);
}