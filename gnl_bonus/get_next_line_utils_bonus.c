#include "get_next_line_bonus.h"

t_list *gnl_new_node(void *content, int fd)
{
    t_list *ptr;
    ptr = (t_list *)malloc(sizeof(t_list));
    if (!ptr)
        return NULL;
    
    ptr -> content = content;
    ptr -> fd = fd;
    ptr -> next = NULL;

    return ptr; 
}

t_list *get_node(t_list **head, int fd)
{
    t_list *current;
    t_list *new;
    
    if(!*head)
    {
        *head = gnl_new_node(NULL, fd);
        return (*head);
    }
    current  = *head;
    while(current)
    {
        if(current -> fd == fd)
            return current;
        if (current -> next == NULL)
            break;
        current = current -> next;
    }
    new = gnl_new_node(NULL, fd);
    current -> next = new;
    return(new);
}

char *gnl_strjoin(const char *s1,const char *s2)
{
    char *res;
    size_t i;
    size_t j;

    if (!s1)
        s1 = "";
    if (!s2)
        s2 = "";
    res = malloc(gnl_strlen(s1)+gnl_strlen(s2) + 1);
    if (!res)
        return(NULL);
    i = -1;
    while(s1[++i])
        res[i] = s1[i];
    j = -1;
    while(s2[++j])
        res[i+j] = s2[j];
    res[i+j] = '\0';
    return(res);
}
void remove_node(t_list **head,int fd)
{
    t_list *current;
    t_list *prev;

    current = *head;
    prev = NULL;
    while(current)
    {
        if (current -> fd == fd)
        {
            if (prev)
                prev -> next = current -> next;
            else 
                *head = current -> next;
            if (current -> content)
                return(free(current));
        }
        prev = current;
        current = current -> next;
    }
}

char *gnl_strchr(const char *s, int c)
{
    char *last_match;

    last_match = NULL;
    while(1)
    {
        if (*s == (char)c)
        {
            last_match = (char *)s;
            break;
        }
        if(*s == '\0')
            break;
        s++;
    }
    return last_match;
}
