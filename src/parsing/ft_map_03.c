#include "../../cub3D.h"

int	ft_get_opt(t_mlx *mlx, char *file)
{
	int		i;
	int		res;
	int		fd;
	char	*line;

	i = 0;
	res = 0;
	fd = open(file, O_RDONLY);
	while (get_next_line(fd, &line))
	{
		res = ft_get_text(mlx, line, &res);
		res = ft_get_color(mlx, line, &res);
		if (res < 6)
			i++;
		free(line);
	}
	close(fd);
	free(line);
	if (res != 6)
		return (-1);
	return (i);
}

int	ft_get_text(t_mlx *mlx, char *line, int	*res)
{
	int	i;

	i = *res;
	if (ft_is_opt("NO", line) == 0)
	{
		mlx->arg.no = ft_strdup(line);
		i++;
	}
	else if (ft_is_opt("SO", line) == 0)
	{
		mlx->arg.so = ft_strdup(line);
		i++;
	}
	else if (ft_is_opt("WE", line) == 0)
	{
		mlx->arg.we = ft_strdup(line);
		i++;
	}
	else if (ft_is_opt("EA", line) == 0)
	{
		mlx->arg.ea = ft_strdup(line);
		i++;
	}
	return (i);
}

int	ft_get_color(t_mlx *mlx, char *line, int *res)
{
	int	i;

	i = *res;
	if (ft_is_opt("F ", line) == 0)
	{
		mlx->arg.f.str = ft_strdup(line);
		i++;
	}
	if (ft_is_opt("C ", line) == 0)
	{
		mlx->arg.c.str = ft_strdup(line);
		i++;
	}
	return (i);
}

void	ft_get_g_dim(t_mlx *mlx, char *file)
{
	int		vide;
	int		fd;
	int		height;
	int		width;
	char	*line;

	vide = 0;
	fd = open(file, O_RDONLY);
	height = 0;
	width = 0;
	while (get_next_line(fd, &line))
	{
		if (ft_is_line(line) == 0 && vide == 0)
		{
			if (ft_strlen(line) > width)
				width = ft_strlen(line);
			height++;
		}
		if (ft_is_line(line) != 0 && height > 0)
			vide = 1;
		free(line);
	}
	free(line);
	mlx->map.g_width = width;
	mlx->map.g_height = height;
	close(fd);
}
