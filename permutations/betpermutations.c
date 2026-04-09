#include "permutations.h"

void	ft_swap(char *s1, char *s2)
{
	char	tmp = *s1;
	*s1 = *s2;
	*s2 = tmp;
}

void	sort_str(char *str)
{
	int i = 0;
	int j;

	while (str[i])
	{
		j = i + 1;
		while (str[j])
		{
			if (str[i] > str[j])
				ft_swap(&str[i], &str[j]);
			j++;
		}
		i++;
	}
}

void	perm(char *str, int start, int end)
{
	int i;

	if (start == end)
	{
		puts(str);
		return ;
	}
	i = start;
	while (i < end)
	{
		sort_str(str + start); // dizinin sonuna ulaştıysak tam dizine geldik
		ft_swap(&str[start], &str[i]); // başlangıç poz getir
		sort_str(str + start + 1); // sıradaki karakteri başlangııç poz getir
		perm(str, start + 1, end); // karakteri başa sabitledikten sonra sonrakine geç
		i++;
	}
}

int	main(int ac, char **av)
{
	int len = 0;

	if (ac != 2)
		return (0);
	while (av[1][len]) // kullanıcının girdiği kelimenin uzunluğu
		len++;
	sort_str(av[1]); // ilk iş kelimeyi alfabetik olarak dizer
	perm(av[1], 0, len);
	return (0);
}