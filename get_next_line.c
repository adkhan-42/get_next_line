#include "get_next_line.h"

char * read_from_file(int fd, char *stash)
{
    char *buffer;
    char *temp;
    int bytes_read;

    buffer = malloc((BUFFER_SIZE + 1));
    if (!buffer)
    {
        free(stash);
        return (NULL);
    }
    bytes_read = 1;
    while (bytes_read > 0)
    {
        bytes_read = read(fd,buffer,BUFFER_SIZE);
        if(bytes_read == -1)
        {
            free(stash);
            free(buffer);
            return NULL;
        }
        buffer[bytes_read] = 0;
        temp = stash;
        stash = gnl_strjoin(temp,buffer);
        if(!stash)
        {
            free(stash);
            free(buffer);
            free(temp);
            return NULL;
        }
        free(temp);
        if (gnl_strchr(stash,'\n'))
            break;
    }
    free(buffer);
    return(stash);
}

char *extract_line(char *stash)
{
    char *line;
    int i;
    int size;

    i = 0;
    if(!stash || stash[0] == '\0')
        return NULL;
    while (stash[i] && stash[i] != '\n')
        i++;
    if (stash[i] == '\n')
        i++;
    size = i;
    line = malloc ((size + 1) *sizeof(char));
    if (!line)
        return NULL;
    i = 0;
    while(i < size)
    {
        line[i] = stash[i];
        i++;
    } 
    line[i] = '\0';
    return (line);
}

char *clean_stash(char *stash)
{
    int i;
    int j;
    char *new_stash;

    i = 0;
    while (stash[i] && stash[i] != '\n')
        i++;
    if (!stash[i])
    {
        free(stash);
        return NULL;
    }
    new_stash = malloc ((gnl_strlen(stash) - i + 1) * sizeof(char));
    if(!new_stash)
    {
        free(stash);
        return NULL;
    }
    i++;
    j = 0;
    while(stash[i])
        new_stash[j++] = stash[i++];
    new_stash[j] = '\0';
    free(stash);
    return (new_stash);
}

char *get_next_line(int fd)
{
    static char *stash;
    char *line;

    if(fd < 0 || BUFFER_SIZE <= 0)
        return NULL;
    stash = read_from_file(fd,stash);
    if (!stash)
        return NULL;
    line = extract_line(stash);
    stash = clean_stash(stash);
    return(line);
}
