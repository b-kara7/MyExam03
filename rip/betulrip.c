#include <stdio.h>

// Bu senin yazdığın fonksiyon, sadece "is_balanced" kontrolü için güncelledik.
int ft_valid(char *s)
{
    int open = 0;

    while (*s)
    {
        if (*s == '(')
            open++;
        else if (*s == ')')
            open--;
        if (open < 0) // Kapatan parantez açandan önce gelemez, anında hata!
            return (1);
        s++;
    }
    return (open); // 0 dönerse tam dengelidir.
}

// Bu senin hata miktarını bulmak için kullandığın mantık.
int ft_count_bad(char *s)
{
    int open = 0, close = 0;
    for (int i = 0; s[i]; i++)
    {
        if (s[i] == '(') open++;
        else if (s[i] == ')') (open > 0) ? open-- : close++;
    }
    return (open + close);
}

void rip(char *s, int must_fix, int fix, int i)
{
    char c;

    // fix miktarı hedefe ulaştıysa ve dizi dengeliyse yazdır.
    if (fix == must_fix)
    {
        if (ft_valid(s) == 0)
            puts(s);
        return ;
    }
    while (s[i])
    {
        // Önemli: Aynı karakter yan yanaysa sadece ilkini boşluk yap (Tekrarı önler)
        if (s[i] == '(' || s[i] == ')')
        {
            if (i > 0 && s[i] == s[i - 1] && s[i - 1] != ' ')
            {
                i++;
                continue;
            }
            c = s[i];
            s[i] = ' ';
            rip(s, must_fix, fix + 1, i + 1);
            s[i] = c;
        }
        i++;
    }
}

int main(int ac, char **av)
{
    if (ac != 2)
        return (1);
    // Önce kaç tane silmemiz gerektiğini hesaplıyoruz, sonra senin rip fonksiyonun başlıyor.
    rip(av[1], ft_count_bad(av[1]), 0, 0);
    return (0);
}