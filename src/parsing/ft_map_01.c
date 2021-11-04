#include "../../cub3D.h"

int	ft_get_direction(char direction)
{
	if (direction == 'N')
		return (270);
	else if (direction == 'E')
		return (0);
	else if (direction == 'S')
		return (90);
	else if (direction == 'W')
		return (180);
	else
		return (-1);
}

int	ft_get_position_1(t_mlx *mlx)
{
	int	i;
	int	j;
	int	res;

	i = 0;
	j = 0;
	res = 0;
	while (mlx->map.grid[i])
	{
		while (mlx->map.grid[i][j])
		{
			res = ft_get_position_2(mlx, i, j, &res);
			j++;
		}
		i++;
		j = 0;
	}
	if (res != 1 || mlx->player.angle < 0)
		return (-1);
	return (0);
}

int	ft_get_position_2(t_mlx *mlx, int i, int j, int *res)
{
	int	index;

	index = *res;
	if (mlx->map.grid[i][j] != '1' && mlx->map.grid[i][j]
			!= '0' && mlx->map.grid[i][j] != ' ')
	{
		mlx->player.x = j + 0.5;
		mlx->player.y = i + 0.5;
		mlx->player.angle = ft_get_direction(mlx->map.grid[i][j]);
		index++;
	}
	return (index);
}

void	ft_display_map(t_mlx *mlx)
{
	int	i;

	i = 0;
	while (i < mlx->map.g_height)
	{
		printf("%s\n", mlx->map.grid[i]);
		i++;
	}
}
