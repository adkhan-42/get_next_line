#include "get_next_line_bonus.h"

size_t gnl_strlen(const char *s)
{
    size_t i;
    if (!s)
        return(i = 0);

    i = 0;
    while (s[i])
    {
        i++;
    }
    return (i);
}

static char *read_from_file(int fd, char *stash)
{
    char *buffer;
    int bytes_read;
    char *temp;

    buffer = malloc((BUFFER_SIZE + 1));
    if (!buffer)
    {
        free(stash);
        return NULL;
    }
    while((bytes_read = read(fd,buffer,BUFFER_SIZE)) > 0)
    {
        buffer[bytes_read] = 0;
        temp = stash;
        stash = gnl_strjoin(temp,buffer);
        free(temp);
        if (gnl_strchr(stash,'\n'))
                    break;
    }
    free(buffer);
    if(bytes_read == -1) 
            return (free(stash),NULL);
    return (stash);
}

static char *extract_line(char *stash)
{
    char *line; 
    int i;
    int size;

    i = 0;
    if (!stash || stash[0]== '\0')
        return NULL;
    while(stash[i] && stash[i] != '\n')
        i++;
    if (stash[i]=='\n')
        i++;
    size = i;
    line = malloc((size + 1)* sizeof(char));
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

static char *clean_stash(char *stash)
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
    new_stash = malloc((gnl_strlen(stash) - i + 1) * sizeof(char));
    if (!new_stash)
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
    return(new_stash);
}

char *get_next_line_bonus(int fd)
{
    static t_list *head;
    char *line;
    t_list *node;

    if(fd < 0 || BUFFER_SIZE <= 0)
        return NULL;
    node = get_node(&head,fd);
    if(!node)
        return NULL;
    printf("DEBUG: Reading...\n");
    node->content = read_from_file(fd, node->content);
    if(!node -> content)
        return NULL;
    printf("DEBUG: Extracting...\n");
    line = extract_line(node -> content);
    printf("DEBUG: Cleaning...\n");
    node->content = clean_stash(node->content);
    return (line);
}
