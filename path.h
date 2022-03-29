#ifndef PATH_H
# define PATH_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_point {
	int	x;
	int	y;
}	t_point;

typedef struct s_tab {
	char	**tab;
	t_point	start_point;
	t_point	end_point;
	int		height;
	int		width;
}	t_tab;

char	**ft_map_in_tab(char *file);
int		ft_map_width(char **str);
int		ft_map_height(char **str);
void	ft_print(char **path, char **tab);
void	ft_free(char **data);
void	ft_initialize_tab(t_tab *tab);
void	ft_resolve(t_tab *tab);

#endif