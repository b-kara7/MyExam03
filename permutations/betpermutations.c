#include <unistd.h>
#include <stdio.h>

// 1. Fonksiyon: İki karakterin yerini değiştirir
void	swap(char *a, char *b)
{
	char temp = *a;
	*a = *b;
	*b = temp;
}

// 2. Fonksiyon: String'i alfabetik sıraya dizer
void	sort_str(char *s, int start)
{
	int i, j;

	i = start;
	while (s[i])
	{
		j = i + 1;
		while (s[j])
		{
			if (s[i] > s[j])
				swap(&s[i], &s[j]);
			j++;
		}
		i++;
	}
}

// 3. Fonksiyon: Permütasyonları üretir ve basar
void	generate(char *s, int start, int len)
{
	int i;

	if (start == len)
	{
		puts(s);
		return;
	}
	i = start;
	while (i < len)
	{
		sort_str(s, start); // Her adımda alfabetik sırayı koru
		swap(&s[start], &s[i]);
		generate(s, start + 1, len);
		swap(&s[start], &s[i]); // Backtrack
		i++;
	}
}

// 4. Fonksiyon: Ana giriş noktası
int	main(int ac, char **av)
{
	int len = 0;

	if (ac == 2)
	{
		while (av[1][len])
			len++;
		sort_str(av[1], 0);
		generate(av[1], 0, len);
	}
	return (0);
}