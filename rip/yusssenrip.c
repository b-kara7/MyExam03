#include <stdio.h>

int	ft_valid(char *s)
{
	int	open = 0;
	int	close = 0;

	while (*s)
	{
		if (*s == '(')
			open++;
		else if (*s == ')')
		{
			if (open > 0)
				open--;
			else
				close++;
		}
		s++;
	}
	return (open + close);
}

void	rip(char *s, int must_fix, int fix, int i)
{
	char	c;

	if (fix == must_fix && !ft_valid(s))
	{
		puts(s);
		return ;
	}
	if (fix > must_fix)
		return ;
	while (s[i])
	{
		if (s[i] == '(' || s[i] == ')')
		{
			c = s[i];
			s[i] = ' ';
			rip(s, must_fix, fix + 1, i + 1);
			s[i] = c;
		}
		i++;
	}
}

int	main(int ac, char **av)
{
	if (ac != 2)
		return (1);
	rip(av[1], ft_valid(av[1]), 0, 0);
	return (0);
}