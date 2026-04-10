#include "permutations.h"

void swap(char *s1, char *s2)
{
    char tmp;
    tmp = *s1;
    *s1 = *s2;
    *s2 = tmp;
}
void sort(char *str)
{
    int i =0;
    int j;

    while (str[i])
    {
        j = i + 1;
        while (str[j])
        {
            if(str[i] > str[j])
                swap(&str[i], &str[j]);
            j++;
        }
        i++;
    }
}
void perm(char *str, int start, int end)
{
    int i = 0;

    if (start == end)
    {
        puts(str);
        return ;
    }
    i = start;
    while (str[i])
    {
        sort(str + start);
        swap(&str[start], &str[i]);
        sort(str + start + 1);
        perm(str, start + 1, end);
        i++;
    }
}
int main(int ac, char **av)
{
    int len = 0;

    if (ac !=2)
        return (0);
    while (av[1][len])
        len++;
    sort(av[1]);
    perm(av[1], 0, len);
    return 0 ;
}