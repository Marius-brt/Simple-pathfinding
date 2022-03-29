#include "path.h"
#include <stdio.h>

int ft_is_safe(int x, int y, t_tab tab)
{
	return (x >= 0 && x < tab.width && y >= 0 && y < tab.height && tab.tab[y][x] == '.');
}

int ft_backtrack(int x, int y, int dir, t_tab tab, char **path)
{
	if(x == tab.end_point.x && y == tab.end_point.y)
		return (1);
	if(ft_is_safe(x, y, tab) || (x == tab.start_point.x && y == tab.start_point.y))
	{
		if(path[y][x] == '*')
			return (0);
		path[y][x] = '*';
		switch(dir)
		{
			case 1:
				if (ft_backtrack(x, y - 1, 1, tab, path))
					return (1);
				break;
			case 2:
				if (ft_backtrack(x - 1, y, 2, tab, path))
					return (1);
				break;
			case 3:
				if (ft_backtrack(x, y + 1, 3, tab, path))
					return (1);
				break;
			case 4:
				if (ft_backtrack(x + 1, y, 4, tab, path))
					return (1);
				break;
		}
		if (ft_backtrack(x, y - 1, 1, tab, path))
			return (1);
		if (ft_backtrack(x - 1, y, 2, tab, path))
			return (1);
		if (ft_backtrack(x, y + 1, 3, tab, path))
			return (1);
		if (ft_backtrack(x + 1, y, 4, tab, path))
			return (1);
		path[y][x] = '.';
		return (0);
	}
	return (0);
}

void ft_resolve(t_tab *tab)
{
	int y = -1;
	int x = -1;
	char **path = (char **)malloc(sizeof(char *) * tab->height * tab->width);
	while(++y < tab->height)
	{
		path[y] = (char *)malloc(sizeof(char) * tab->width);
		x = -1;
		while(++x < tab->width)
			path[y][x] = '.';
	}	
	if(!ft_backtrack(tab->start_point.x, tab->start_point.y, 1, *tab, path))
		printf("No solution\n");
	else
		ft_print(path, tab->tab);
	ft_free(path);
}