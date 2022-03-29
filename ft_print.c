#include "path.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void ft_print(char **path, char **tab)
{
	int y	= -1;
	int x	= -1;

	while(tab[++y])
	{
		x = -1;
		while(tab[y][++x])
		{
			if(tab[y][x] == '.' && path[y][x] == '*')
				ft_putchar('*');
			else
				ft_putchar(tab[y][x]);
		}
		ft_putchar('\n');
	}
}