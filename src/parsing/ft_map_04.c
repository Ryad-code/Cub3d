#include "../../cub3D.h"

int	ft_get_map(t_mlx *mlx, char *file)
{
	int		i;
	int		fd;
	char	*line;

	i = 0;
	fd = open(file, O_RDONLY);
	line = NULL;
	mlx->map.grid = malloc(sizeof(char *) * (mlx->map.g_height + 1));
	if (mlx->map.grid == NULL)
		return (-1);
	while (get_next_line(fd, &line) && i < mlx->map.g_height)
	{
		if (ft_is_line(line) == 0)
		{
			mlx->map.grid[i] = ft_strdup(line);
			i++;
		}
		free(line);
	}
	mlx->map.grid[i] = NULL;
	free(line);
	close(fd);
	return (0);
}

int	ft_get_infos(t_mlx *mlx, char *file)
{
	int	text;
	int	map;
	int	position;

	ft_count_lines(mlx, file);
	ft_get_g_dim(mlx, file);
	if (mlx->arg.nb_line > (mlx->arg.nb_empty + mlx->map.g_height + 6))
		return (-1);
	if (mlx->map.g_height < 2 || mlx->map.g_width < 2)
		return (-1);
	text = ft_get_opt(mlx, file);
	map = ft_get_map(mlx, file);
	position = ft_get_position_1(mlx);
	if (text < 0 || map < 0 || position < 0)
		return (-1);
	return (0);
}
