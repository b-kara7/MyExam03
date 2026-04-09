#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int check(char *s1, char *s2, int len)
{
    while (len--)
    {
         if (!*s1 || !*s2 || *s1++ !=*s2++)
            return(0);
    }
    return(1);
}

int main(int ac, char **av)
{
    if (ac !=2)
        return(1);
    char *buff = calloc(1024 *1024, sizeof(char));
    if (!buff)
    {
        perror("Error: ");
        return(1);
    }
    int i = 0;
    char c;
    int rd = read(0, &c, 1);
    while (rd > 0)
    {
        buff[i++] = c;
        rd = read(0, &c, 1);
    }
    i = 0;
    while (buff[i])
    {
        int len = strlen(av[1]);
        if (len && check(&buff[i], av[1], len))
        {
            while (len--)
                buff[i++] = '*';
        }
        else
            i++;
    }
    printf("%s", buff);
    free(buff);
    return(0);
}