#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>

int ft_strlen(char *s)
{
    int i = -1;
    while (s[++i]);
    return i;
}

char *ft_strdup(char *s)
{
    char *n = malloc(ft_strlen(s) + 1);
    int i = -1;
    while (s[++i])
        n[i] = s[i];
    n[i] = '\0';
    return (n);
}

void swap(char *s1, char  *s2)
{
    char tmp = *s1;
    *s1 = *s2;
    *s2 = tmp;
}

void sort(char *str)
{
	for(int x = 0; str[x]; x++)
	{
		for(int y = x + 1; str[y]; y++)
		{
			if(str[x] > str[y])
				swap(&str[x], &str[y]);
		}
	}
}

void solve(char *s, int start, int len)
{
    if (start == len)
    {
        write(1, s, len);
		write(1, "\n", 1);
        return ;
    }
    for(int x = start; x < len; x++)
    {
        char temp = s[x];
		for(int i = x; i > start; i--)
			s[i] = s[i - 1];
		s[start] = temp;

		solve(s, start + 1, len);
		
		for(int i = start; i < x; i++)
			s[i] = s[i + 1];
		s[x] = temp;
    }
}

int main(int ac, char *av[])
{
    if (ac != 2)
        return 1;
    char *s = ft_strdup(av[1]);
    int len = ft_strlen(s);
    sort(s);
    solve(s, 0 ,len);
	free(s);
	return 0;
}