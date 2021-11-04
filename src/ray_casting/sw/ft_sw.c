#include "../../../cub3D.h"

double	ft_sw(t_mlx *mlx, double x, double y, double angle)
{
	double	*hypo;
	double	hypo_1;
	double	hypo_2;

	if (x / cos((PI / 2) - (angle - (PI / 2))) <= (1 - y) / cos(angle - (PI / 2)))
	{
		hypo = ft_sw_x(mlx, x, y, angle);
		if (hypo == NULL)
			return (-1);
		hypo_1 = hypo[0];
		hypo_2 = hypo[1];
		free(hypo);

	}
	else if ((1 - y) / cos(angle - (PI / 2)) <= x / cos((PI / 2) - (angle - (PI / 2))))
	{
		hypo = ft_sw_y(mlx, x, y, angle);
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
		if (x / cos((PI / 2) - (angle - (PI / 2))) <= (1 - y) / cos(angle - (PI / 2)))
			mlx->player.dir = 'w';
		else
			mlx->player.dir = 's';
		return (hypo_1);
	}
	else
	{
		mlx->player.f_hit_x = mlx->player.hit2_x;
		mlx->player.f_hit_y = mlx->player.hit2_y;
		if (x / cos((PI / 2) - (angle - (PI / 2))) <= (1 - y) / cos(angle - (PI / 2)))
			mlx->player.dir = 's';
		else
			mlx->player.dir = 'w';
		return (hypo_2);
	}
	return (0);
}

double	*ft_sw_x(t_mlx *mlx, double x, double y, double angle)
{
	int	i;
	double	*hypo;

	i = 1;
	hypo = malloc(sizeof(double) * 2);
	if (hypo == NULL)
		return (NULL);
	hypo[0] = x / cos((PI / 2) - (angle - (PI / 2)));
	mlx->player.hit1_x = (int)mlx->player.x;
	mlx->player.hit1_y = (int)mlx->player.y + y + sqrt((hypo[0] * hypo[0]) - (x * x));
	while (mlx->player.hit1_y <= mlx->map.g_height && mlx->player.hit1_x >= 0
		&& ft_check_hit(mlx, 'w' ,mlx->player.hit1_x, mlx->player.hit1_y) != '1')
	{
		hypo[0] = (x + i) / cos((PI / 2) - (angle - (PI / 2)));
		mlx->player.hit1_x = (int)mlx->player.x - i;
		mlx->player.hit1_y = (int)mlx->player.y + y + sqrt((hypo[0] * hypo[0]) - ((x + i) * (x + i)));
		i++;
	}
	i = 1;
	hypo[1] = (1 - y) / cos(angle - (PI / 2));
	mlx->player.hit2_x = (int)mlx->player.x + x - sqrt((hypo[1] * hypo[1]) - ((1 - y) * (1 - y)));
	mlx->player.hit2_y = (int)mlx->player.y + 1;
	while (mlx->player.hit2_y <= mlx->map.g_height && mlx->player.hit2_x >= 0
		&& ft_check_hit(mlx, 's' , mlx->player.hit2_x, mlx->player.hit2_y) != '1')
	{
		hypo[1] = ((1 - y) + i) / cos(angle - (PI / 2));
		mlx->player.hit2_x = (int)mlx->player.x + x - sqrt((hypo[1] * hypo[1]) - (((1 - y) + i) * ((1 - y) + i)));
		mlx->player.hit2_y = (int)mlx->player.y + 1 + i;
		i++;
	}
	return (hypo);
}

double  *ft_sw_y(t_mlx *mlx, double x, double y, double angle)
{
	int	i;
	double	*hypo;

	i = 1;
	hypo = malloc(sizeof(double) * 2);
	if (hypo == NULL)
		return (NULL);
	hypo[0] = (1 - y) / cos(angle - (PI / 2));
	mlx->player.hit1_x = (int)mlx->player.x + x - sqrt((hypo[0] * hypo[0]) - ((1 - y) * (1 - y)));
	mlx->player.hit1_y = (int)mlx->player.y + 1;
	while (mlx->player.hit1_y <= mlx->map.g_height && mlx->player.hit1_x >= 0
		&& ft_check_hit(mlx, 's' , mlx->player.hit1_x, mlx->player.hit1_y) != '1')
	{
		hypo[0] = ((1 - y) + i) / cos(angle - (PI / 2));
		mlx->player.hit1_x = (int)mlx->player.x + x - sqrt((hypo[0] * hypo[0]) - (((1 - y) + i) * ((1 - y) + i)));
		mlx->player.hit1_y = (int)mlx->player.y + 1 + i;
		i++;
	}
	i = 1;
	hypo[1] = x / cos((PI / 2) - (angle - (PI / 2)));
	mlx->player.hit2_x = (int)mlx->player.x;
	mlx->player.hit2_y = (int) mlx->player.y + y + sqrt((hypo[1] * hypo[1]) - (x * x));
	while (mlx->player.hit2_y <= mlx->map.g_height && mlx->player.hit2_x >= 0
		&& ft_check_hit(mlx, 'w' , mlx->player.hit2_x, mlx->player.hit2_y) != '1')
	{
		hypo[1] = (x + i) / cos((PI / 2) - (angle - (PI / 2)));
		mlx->player.hit2_x = (int)mlx->player.x - i;
		mlx->player.hit2_y = (int) mlx->player.y + y + sqrt((hypo[1] * hypo[1]) - ((x + i) * (x + i)));
		i++;
	}
	return (hypo);
}
