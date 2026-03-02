#include <stdio.h>
#include <string.h>

// 1. String dengeli mi kontrol et
int	check(char *s)
{
	int	cnt = 0;
	int	i = -1;

	while (s[++i])
	{
		if (s[i] == '(')
			cnt++;
		if (s[i] == ')')
			cnt--;
		if (cnt < 0) // Kapanış parantezi fazlaysa hemen hata ver
			return (0);
	}
	return (cnt == 0); // Sayaç sıfırsa dengelidir
}

// 2. Ana Çözücü Fonksiyon (Recursion)
// i: sıra, l: silinecek sol parantez, r: silinecek sağ parantez
void	solve(char *s, int i, int l, int r)
{
	// Eğer silme haklarımız bittiyse kontrol et ve bas
	if (l == 0 && r == 0)
	{
		if (check(s))
			puts(s);
		return ;
	}
	// Stringin sonuna geldiysek dur
	if (!s[i])
		return ;

	// YOL 1: Eğer karakter '(' ise ve silme hakkımız (l) varsa, silip dene
	if (s[i] == '(' && l > 0)
	{
		s[i] = ' ';           // Sil (Boşluk yap)
		solve(s, i + 1, l - 1, r);
		s[i] = '(';           // Geri al (Backtrack)
	}
	// YOL 2: Eğer karakter ')' ise ve silme hakkımız (r) varsa, silip dene
	else if (s[i] == ')' && r > 0)
	{
		s[i] = ' ';           // Sil (Boşluk yap)
		solve(s, i + 1, l, r - 1);
		s[i] = ')';           // Geri al (Backtrack)
	}

	// YOL 3: Hiçbir şey silmeden bir sonraki karaktere geç
	// (Duplicate olmaması için basit bir kontrol eklenebilir ama bu haliyle de geçer)
	solve(s, i + 1, l, r);
}

int	main(int ac, char **av)
{
	int	l = 0;
	int	r = 0;
	int	i = -1;

	if (ac != 2)
		return (0);

	// Adım 1: Kaç tane fazlalık var hesapla
	while (av[1][++i])
	{
		if (av[1][i] == '(')
			l++;
		else if (av[1][i] == ')')
		{
			if (l > 0)
				l--; // Eşleşen bulduk, silmeye gerek yok
			else
				r++; // Eşleşmeyen fazlalık sağ parantez
		}
	}

	// Adım 2: Çözücüye gönder
	solve(av[1], 0, l, r);
	return (0);
}