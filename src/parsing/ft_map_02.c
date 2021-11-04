#include "../../cub3D.h"

int	ft_strstr(char *str1, char *str2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str1[i])
	{
		if (str1[i] == str2[0])
		{
			while (str1[i + j] == str2[j])
				j++;
		}
		if (j >= ft_strlen(str2))
			return (0);
		i++;
	}
	return (-1);
}

int	ft_is_opt(char *opt, char *line)
{
	if (ft_strstr(line, opt) == 0)
		return (0);
	return (-1);
}

int	ft_count_lines(t_mlx *mlx, char *file)
{
	int		fd;
	int		nb_line;
	int		nb_empty;
	char	*line;

	fd = open(file, O_RDONLY);
	nb_line = 0;
	nb_empty = 0;
	while (get_next_line(fd, &line))
	{
		if (ft_empty_line(line) == 0)
			nb_empty++;
		nb_line++;
		free(line);
	}
	close(fd);
	free(line);
	mlx->arg.nb_line = nb_line;
	mlx->arg.nb_empty = nb_empty;
	return (0);
}

int	ft_empty_line(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != ' ')
			return (-1);
		i++;
	}
	return (0);
}

int	ft_is_line(char *str)
{
	int	i;

	i = 0;
	if (str == NULL || ft_strlen(str) == 0 || ft_empty_line(str) == 0)
		return (-1);
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '0' && str[i] != '1'
			&& str[i] != 'N' && str[i] != 'S' && str[i] != 'W' && str[i] != 'E')
			return (-1);
		i++;
	}
	return (0);
}
