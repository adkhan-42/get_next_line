#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H


# include <stdlib.h> 
# include <unistd.h> 
# include <string.h>
# include <stdio.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

typedef struct s_list
{
    char *content;
    int fd;
    struct s_list *next;
}t_list;

char *get_next_line(int fd);

t_list *gnl_new_node(void *content, int fd);
t_list *get_node(t_list **stash, int fd);
size_t gnl_strlen(const char *s);
void *gnl_memcpy(void *dest, const void *src,size_t n);
char *gnl_strjoin(const char *s1,const char *s2);
char *gnl_strchr(const char *s, int c);
void remove_node(t_list **head,int fd);

#endif
