#include "path.h"

int	ft_map_height(char **str)
{
	int	i	= -1;
	int	c	= 0;

	while (str[++i])
		if (str[i][0] != '\n')
			c++;
	return (c);
}

int	ft_map_width(char **str)
{
	int	i	= 0;

	while (str[1][i])
		i++;
	return (i);
}

void ft_initialize_tab(t_tab *tab)
{
	int y	= -1;
	int x	= -1;

	tab->tab	= ft_map_in_tab("path.txt");
	tab->width	= ft_map_width(tab->tab);
	tab->height	= ft_map_height(tab->tab);
	
	while(tab->tab[++y])
	{
		x = -1;
		while(tab->tab[y][++x])
		{
			if(tab->tab[y][x] == 'x')
			{
				tab->start_point.x = x;
				tab->start_point.y = y;		
			}
			else if(tab->tab[y][x] == 'o')
			{
				tab->end_point.x = x;
				tab->end_point.y = y;		
			}
		}
	}
}