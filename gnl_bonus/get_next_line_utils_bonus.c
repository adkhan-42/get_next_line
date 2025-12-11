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

void *gnl_memcpy(void *dest, const void *src,size_t n)
{
    size_t i;
    char *dest1;
    const char *src1;

    if (!dest || !src)
        return NULL;

    dest1 = (char *)dest;
    src1 = (const char *)src;
    i = 0;
    while (i < n)
    {
        dest1[i] = src1[i];
        i++;
    }
    return (dest);    
}


char *gnl_strjoin(const char *s1,const char *s2)
{
    size_t slen1;
    size_t slen2;
    size_t tot_len;
    char *res;

    slen1 = gnl_strlen(s1);
    slen2 = gnl_strlen(s2);
    tot_len = slen1 + slen2;
    res = malloc((tot_len + 1)*(sizeof(char)));
    if (!res)
        return NULL;
    gnl_memcpy(res,s1,slen1);
    gnl_memcpy((res + slen1),s2,slen2);
    res[slen1 + slen2] = '\0';
    return (res);
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
