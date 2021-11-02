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

void	ft_replace_dir(t_mlx *mlx)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (mlx->map.grid[j])
	{
		while (i < ft_strlen(mlx->map.grid[j]))
		{
			if (mlx->map.grid[j][i] == 'N'|| mlx->map.grid[j][i] == 'E'||
				mlx->map.grid[j][i] == 'S'|| mlx->map.grid[j][i] == 'W')
				mlx->map.grid[j][i] = '0';
			i++;
		}
		i = 0;
		j++;
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
	while (i < ft_strlen(mlx->map.grid[0]))
	{
		if (mlx->map.grid[0][i] != '1' && mlx->map.grid[0][i] != ' ')
		{
			printf("i = %d\n", i);
			return (-1);
		}
		i++;
	}
	i = 0;
	while (i < ft_strlen(mlx->map.grid[mlx->map.g_height - 1]))
	{
		if (mlx->map.grid[mlx->map.g_height - 1][i] != '1' && mlx->map.grid[mlx->map.g_height - 1][i] != ' ')
			return (-2);
		i++;
	}
	i = 0;
	while (i < mlx->map.g_height)
	{
		if (mlx->map.grid[i][0] != '1' && mlx->map.grid[i][0] != ' ')
				return (-3);
		if (mlx->map.grid[i][ft_strlen(mlx->map.grid[i]) - 1] != '1' &&
			mlx->map.grid[i][ft_strlen(mlx->map.grid[i]) - 1] != ' ')
			return (-4);
		i++;
	}
	return (0);
}

int	ft_check_inside_grid(t_mlx *mlx)
{
	int	i;
	int	j;

	i = 1;
	j = 1;
	while (j < mlx->map.g_height - 1)
	{
		while (i < ft_strlen(mlx->map.grid[j]))
		{
			if (mlx->map.grid[j][i] == '0')
			{
				if (mlx->map.grid[j - 1][i] != '1' && mlx->map.grid[j - 1][i] != '0')
					return (-1);
				if (mlx->map.grid[j + 1][i] != '1' && mlx->map.grid[j + 1][i] != '0')
					return (-2);
				if (mlx->map.grid[j][i - 1] != '1' && mlx->map.grid[j][i - 1] != '0')
					return (-3);
				if (mlx->map.grid[j][i + 1] != '1' && mlx->map.grid[j][i + 1] != '0')
					return (-4);
			}
			i++;
		}
		i = 0;
		j++;
	}
	return (0);
}

int	ft_parse_map(t_mlx *mlx)
{
	int	out;
	int	in;

	ft_replace_dir(mlx);
	out = ft_check_map_sides(mlx);
	in = ft_check_inside_grid(mlx);
//	printf("out = %d | in = %d\n", out, in);
	if (in < 0 || out < 0)
		return (-1);
	ft_fill_grid(mlx);
	return (0);
}
