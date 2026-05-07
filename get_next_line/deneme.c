#include "get_next_line.h"

char *ft_strchr(char *s, int c)
{
    while (s && *s)
    {
        if (*s == (char)c)
            return (s);
        s++;
    }
    if (s && *s == (char)c)
        return (s);
    return (NULL);
}

void *ft_memcpy(void *dest, const void *src, size_t n)
{
    size_t i = 0;
    if(!dest && !src)
        return (NULL);
    while (i < n)
    {
        ((char *)dest)[i] = ((char *)src)[i];
        i++;
    }  
    return (dest);
}

size_t ft_strlen(char *s)
{
    size_t ret = 0;
    while (s && s[ret])
        ret++;
    return (ret);
}

int str_append_mem(char **s1, char *s2, size_t size2)
{
    size_t size1 = ft_strlen(*s1);
    char *tmp = malloc(size2 + size1 + 1);
    if (!tmp)
    {
        free(*s1);
        *s1 = NULL;
        return (0);
    }
    ft_memcpy(tmp, *s1, size1);
    ft_memcpy(tmp + size1, s2, size2);
    tmp[size1 + size2] = '\0';
    free(*s1);
    *s1 = tmp;
    return (1);
}

int str_append_str(char **s1, char *s2)
{
    return (str_append_mem(s1, s2, ft_strlen(s2)));
}

void *ft_memmove(void *dest, const void *src, size_t n)
{
    if (dest < src)
        return (ft_memcpy(dest, src, n));
    if (dest == src)
        return (dest);
    while (n > 0)
    {
        ((char *)dest)[n - 1] = ((char *)src)[n - 1];
        n--;
    }
    return (dest);
}

char *get_next_line(int fd)
{
    static char b[BUFFER_SIZE + 1] = "";
    char *ret = malloc(1);
    char *tmp;
    int read_ret;

    if (fd < 0 || BUFFER_SIZE <= 0 || !ret)
        return (free(ret), NULL);
    ret[0] = 0;
    while (!(tmp = ft_strchr(b, '\n')))
    {
        if (!str_append_str(&ret, b))
            return (NULL);
        read_ret = read(fd, b, BUFFER_SIZE);
        if (read_ret <= 0)
        {
            if (read_ret == 0 && *ret)
                return (b[0] = 0, ret);
            return (free(ret), b[0] = 0, NULL);
        }
        b[read_ret] = 0;
    }
    if (!str_append_mem(&ret, b, (tmp - b) + 1))
        return (NULL);
    ft_memmove(b, tmp + 1, ft_strlen(tmp + 1) + 1);
    return (ret);
}