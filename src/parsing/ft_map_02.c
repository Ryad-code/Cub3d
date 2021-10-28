#include "../../cub3D.h"

int	ft_is_opt(char *opt, char *line)
{
	if (strstr(line, opt) != NULL)
		return (0);
	return (-1);
}

int	ft_get_text(t_mlx *mlx, char *file)
{
	int	i;
	int	res;
	int	fd;
	char	*line;

	i = 0;
	res = 0;
	fd = open(file, O_RDONLY);
	while (get_next_line(fd, &line))
	{
		if (ft_is_opt("NO", line) == 0)
		{
			mlx->arg.no = ft_strdup(line);
			res++;
		}
		else if (ft_is_opt("SO", line) == 0)
		{
			mlx->arg.so = ft_strdup(line);
			res++;
		}
		else if (ft_is_opt("WE", line) == 0)
		{
			mlx->arg.we = ft_strdup(line);
			res++;
		}
		else if (ft_is_opt("EA", line) == 0)
		{
			mlx->arg.ea = ft_strdup(line);
			res++;
		}
		else if (ft_is_opt("F ", line) == 0)
		{
			mlx->arg.f = ft_strdup(line);
			res++;
		}
		else if (ft_is_opt("C ", line) == 0)
		{
			mlx->arg.c = ft_strdup(line);
			res++;
		}
		if (res < 6)
			i++;
	}
	close(fd);
	if (res != 6)
		return (-1);
	return (i);
}

int	ft_empty_line(char *str)
{
	int i;

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
	int i;

	i = 0;
	if (str == NULL || ft_strlen(str) == 0 || ft_empty_line(str) == 0)
		return (-1);
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '0' && str[i] != '1' &&
			str[i] != 'N' && str[i] != 'S' && str[i] != 'W' && str[i] != 'E')
				return (-1);
		i++;
	}
	return (0);
}

void	ft_get_g_height(t_mlx *mlx, char *file)
{
	int	fd;
	int	height;
	int	width;
	char	*line;

	fd = open(file, O_RDONLY);
	height = 0;
	width = 0;
	while (get_next_line(fd, &line))
	{
		if (ft_is_line(line) == 0)
		{
			if (ft_strlen(line) > width)
				width = ft_strlen(line);
			height++;
		}
	}
	mlx->map.g_width = width;
	mlx->map.g_height = height;
	close(fd);
}

void	ft_get_g_width(t_mlx *mlx)
{
	int i;
	int width;

	i = 0;
	width = 0;
	while (i < mlx->map.g_height)
	{
		if (ft_strlen(mlx->map.grid[i]) > width)
			width = ft_strlen(mlx->map.grid[i]);
		i++;
	}
	mlx->map.g_width = width;
}

int	ft_get_map(t_mlx *mlx, char *file)
{
	int	i;
	int	res;
	int	fd;
	char *line;
	
	i = 0;
	res = 0;
	fd = open(file, O_RDONLY);
	ft_get_g_height(mlx, file);
	line = NULL;
	mlx->map.grid = malloc(sizeof(char *) * (mlx->map.g_height + 1));
	if (mlx->map.grid == NULL)
		return (-1);
	while (get_next_line(fd, &line) && i < mlx->map.g_height)
	{
		if (ft_is_line(line) == 0)
		{	mlx->map.grid[i] = ft_strdup(line);
			i++;
		}
		res++;
	}
	mlx->map.grid[i] = NULL;
	close(fd);
	ft_get_g_width(mlx);
	return (res);
}

int	ft_get_infos(t_mlx *mlx, char *file)
{
	int text;
	int map;
	int position;

	text = ft_get_text(mlx, file);
	map = ft_get_map(mlx, file);
	position = ft_get_position(mlx);
	if (text < 0 || map < 0 || position < 0 || text > map)
		return (-1);
	return (0);
}
