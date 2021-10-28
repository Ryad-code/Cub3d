#include "../../cub3D.h"

char	*ft_fill_line(t_mlx *mlx, char *str)
{
	int	i;
	char	*res;

	i = 0;
	res = malloc(sizeof(char) * (mlx->map.g_width + 1));
	if (res == NULL)
		return (NULL);
	while (str[i])
	{
		res[i] = str[i];
		i++;
	}
	while (mlx->map.g_width - i > 0)
	{
		res[i] = '1';
		i++;
	}
	free(str);
	res[i] = '\0';
	return (res);
}

void    ft_replace_spaces(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == ' ')
			str[i] = '1';
		i++;
	}

}

void	ft_fill_grid(t_mlx *mlx)
{
	int	i;

	i = 0;
	while (i < mlx->map.g_height)
	{
		mlx->map.grid[i] = ft_fill_line(mlx, mlx->map.grid[i]);
		ft_replace_spaces(mlx->map.grid[i]);
		i++;
	}
}

int	ft_check_map_sides(t_mlx *mlx)
{
	int	i;

	i = 0;
	while (i < mlx->map.g_height)
	{
		if (mlx->map.grid[i][0] == '0' || mlx->map.grid[i][mlx->map.g_width - 1] == '0')
			return (-1);
		i++;
	}
	i = 0;
	while (i < mlx->map.g_width)
	{
		if (mlx->map.grid[0][i] == '0' || mlx->map.grid[mlx->map.g_height - 1][i] == '0')
			return (-1);
		i++;
	}
	return (0);
}
