#include "../../cub3D.h"

double	ft_se(t_mlx *mlx, double x, double y, double angle)
{
	double	*hypo;
	double	hypo_1;
	double	hypo_2;

	if ((1 - x) / cos(angle) <= (1 - y) / cos(PI / 2 - angle))
	{
		hypo = ft_se_x(mlx, x, y, angle);
		if (hypo == NULL)
			return (-1);
		hypo_1 = hypo[0];
		hypo_2 = hypo[1];
		free(hypo);
	}
	else if ((1 - y) / cos(PI / 2 - angle) <= (1 - x) / cos(angle))
	{
		hypo = ft_se_y(mlx, x, y, angle);
		if (hypo == NULL)
			return (-1);
		hypo_1 = hypo[0];
		hypo_2 = hypo[1];
		free(hypo);
	}
	if (hypo_1 <= hypo_2)
	{
		mlx->player.f_hit_x = mlx->player.hit1_x;
		mlx->player.f_hit_y = mlx->player.hit1_y;
		if ((1 - x) / cos(angle) <= (1 - y) / cos(PI / 2 - angle))
			mlx->player.dir = 'e';
		else
			mlx->player.dir = 's';
		return (hypo_1);
	}
	else
	{
		mlx->player.f_hit_x = mlx->player.hit2_x;
		mlx->player.f_hit_y = mlx->player.hit2_y;
		if ((1 - x) / cos(angle) <= (1 - y) / cos(PI / 2 - angle))
			mlx->player.dir = 's';
		else
			mlx->player.dir = 'e';
		return (hypo_2);
	}
	return (0);
}

double	*ft_se_x(t_mlx *mlx, double x, double y, double angle)
{
	int		i;
	double	*hypo;

	i = 0;
	hypo = malloc(sizeof(double) * 2);
	if (hypo == NULL)
		return (NULL);
	while (mlx->player.hit1_y <= mlx->map.g_height && mlx->player.hit1_x <= mlx->map.g_width
		&& ft_check_hit(mlx, 'e' ,mlx->player.hit1_x, mlx->player.hit1_y) != '1')
	{
		hypo[0] = ((1 - x) + i) / cos(angle);
		mlx->player.hit1_x = (int)mlx->player.x + i + 1;
		mlx->player.hit1_y = (int)mlx->player. y + y + sqrt((hypo[0] * hypo[0]) - (((1 - x) + i) * ((1 - x) + i)));
		i++;
	}
	i = 0;
	while (mlx->player.hit2_y <= mlx->map.g_height && mlx->player.hit2_x <= mlx->map.g_width
		&& ft_check_hit(mlx, 's' ,mlx->player.hit2_x, mlx->player.hit2_y) != '1')
	{
		hypo[1] = ((1 - y) + i) / cos(PI / 2 - angle);
		mlx->player.hit2_x = (int)mlx->player.x + x + sqrt((hypo[1] * hypo[1]) - (((1 - y) + i) * ((1 - y) + i)));
		mlx->player.hit2_y = (int)mlx->player.y + i + 1;
		i++;
	}
	return (hypo);
}

double	*ft_se_y(t_mlx *mlx, double x, double y, double angle)
{
	int	i;
	double	*hypo;

	i = 0;
	hypo = malloc(sizeof(double) * 2);
	if (hypo == NULL)
		return (NULL);
	while (mlx->player.hit1_y <= mlx->map.g_height && mlx->player.hit1_x <= mlx->map.g_width
		&& ft_check_hit(mlx, 's' ,mlx->player.hit1_x, mlx->player.hit1_y) != '1')
	{
		hypo[0] = ((1 - y) + i) / cos(PI / 2 - angle);
		mlx->player.hit1_x = (int)mlx->player.x + x + sqrt((hypo[0] * hypo[0]) - (((1 - y) + i) * ((1 - y) + i)));
		mlx->player.hit1_y = (int)mlx->player.y + i + 1;
		i++;
	}
	i = 0;
	while (mlx->player.hit2_y <= mlx->map.g_height && mlx->player.hit2_x <= mlx->map.g_width
		&& ft_check_hit(mlx, 'e' ,mlx->player.hit2_x, mlx->player.hit2_y) != '1')
	{
		hypo[1] = ((1 - x) + i) / cos(angle);
		mlx->player.hit2_x = (int)mlx->player.x + i + 1;
		mlx->player.hit2_y = (int)mlx->player.y + y + sqrt((hypo[1] * hypo[1]) - (((1 - x) + i) * ((1 - x) + i)));
		i++;
	}
	return (hypo);
}
