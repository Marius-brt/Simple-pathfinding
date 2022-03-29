#include "path.h"

int	ft_dico_size(int fd)
{
	char	buf[1024];
	int		size;
	int		len;

	size = 0;
	while (1)
	{
		len = read(fd, buf, 1024);
		if (len == 0)
			break ;
		if (len < 0)
			return (0);
		size += len;
	}
	return (size);
}

char	*ft_dico_read(char *file)
{
	char	*content;
	int		len;
	int		size;
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (0);
	size = ft_dico_size(fd);
	content = malloc(sizeof(char) * size + 1);
	if (!content)
		return (0);
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (0);
	len = read(fd, content, size);
	if (len < 0)
		return (0);
	content[size] = 0;
	if (close(fd) < 0)
		return (0);
	return (content);
}

char	**ft_size_tab(char *content)
{
	unsigned int	i;
	unsigned int	size;
	char			**val;

	i = 0;
	size = 0;
	while (content[i] != '\0')
	{
		while (content[i] != '\n' && content[i] != '\0')
			i++;
		size++;
		i++;
	}
	val = malloc(sizeof(char *) * size + 1);
	val[size] = 0;
	return (val);
}

int	ft_put_dico_in_tab(char *content, char **val)
{
	int	size;
	int	k;

	while (*content != '\0')
	{
		size = 0;
		while (*content != '\n' && *content)
		{
			size++;
			content++;
		}
		content = content - size;
		*val = malloc(sizeof(char) * size + 1);
		if (!*val)
			return (0);
		k = 0;
		while (*content != '\n' && *content)
			(*val)[k++] = *(content++);
		content++;
		(*val)[k] = 0;
		val++;
	}
	return (1);
}

char	**ft_map_in_tab(char *file)
{
	char	*content;
	char	**val;

	content = ft_dico_read(file);
	if (content == 0)
		return (0);
	val = ft_size_tab(content);
	if (!val)
		return (0);
	if (!ft_put_dico_in_tab(content, val))
		return (0);
	free(content);
	return (val);
}