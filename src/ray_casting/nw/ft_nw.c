#include "../../../cub3D.h"

double	ft_nw(t_mlx *mlx, double x, double y, double angle)
{
	double	*hypo;
	double	hypo_1;
	double	hypo_2;

	if (x / cos(angle - PI) <= y / cos((PI / 2) - (angle - PI)))
	{
		hypo = ft_nw_x(mlx, x, y, angle);
		if (hypo == NULL)
			return (-1);
		hypo_1 = hypo[0];
		hypo_2 = hypo[1];
		free(hypo);
	}
	else if (y / cos((PI / 2) - (angle - PI)) <= x / cos(angle - PI))
	{
		hypo = ft_nw_y(mlx, x, y, angle);
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
		if (x / cos(angle - PI) <= y / cos((PI / 2) - (angle - PI)))
			mlx->player.dir = 'w';
		else
			mlx->player.dir = 'n';
		return (hypo_1);
	}
	else
	{
		mlx->player.f_hit_x = mlx->player.hit2_x;
		mlx->player.f_hit_y = mlx->player.hit2_y;
		if (x / cos(angle - PI) <= y / cos((PI / 2) - (angle - PI)))
			mlx->player.dir = 'n';
		else
			mlx->player.dir = 'w';
		return (hypo_2);
	}
	return (0);
}

double	*ft_nw_x(t_mlx *mlx, double x, double y, double angle)
{
	int	i;
	double	*hypo;

	i = 1;
	hypo = malloc(sizeof(double) * 2);
	if (hypo == NULL)
		return (NULL);
	hypo[0] = x / cos(angle - PI);
	mlx->player.hit1_x = (int)mlx->player.x;
	mlx->player.hit1_y = (int)mlx->player.y + y - sqrt((hypo[0] * hypo[0]) - x * (x));
	while (mlx->player.hit1_y >= 0 && mlx->player.hit1_x >= 0
		&& ft_check_hit(mlx, 'w' , mlx->player.hit1_x, mlx->player.hit1_y) != '1')
	{
		hypo[0] = (x + i) / cos(angle - PI);
		mlx->player.hit1_x = (int)mlx->player.x - i;
		mlx->player.hit1_y = (int)mlx->player.y + y - sqrt((hypo[0] * hypo[0]) - ((x + i) * (x + i)));
		i++;
	}
	i = 1;
	hypo[1] = y / cos((PI / 2) - (angle - PI));
	mlx->player.hit2_x = (int)mlx->player.x + x - sqrt((hypo[1] * hypo[1]) - (y * y));
	mlx->player.hit2_y = (int)mlx->player.y;
	while (mlx->player.hit2_y >= 0 && mlx->player.hit2_x >= 0
		&& ft_check_hit(mlx, 'n' , mlx->player.hit2_x, mlx->player.hit2_y) != '1')
	{
		hypo[1] = (y + i) / cos((PI / 2) - (angle - PI));
		mlx->player.hit2_x = (int)mlx->player.x + x - sqrt((hypo[1] * hypo[1]) - ((y + i) * (y + i)));
		mlx->player.hit2_y = (int)mlx->player.y - i;
		i++;
	}
	return (hypo);
}

double  *ft_nw_y(t_mlx *mlx, double x, double y, double angle)
{
	int	i;
	double	*hypo;

	i = 1;
	hypo = malloc(sizeof(double) * 2);
	if (hypo == NULL)
		return (NULL);
	hypo[0] = y / cos((PI / 2) - (angle - PI));
	mlx->player.hit1_x = (int)mlx->player.x + x - sqrt((hypo[0] * hypo[0]) - (y * y));
	mlx->player.hit1_y = (int)mlx->player.y;
	while (mlx->player.hit1_y >= 0 && mlx->player.hit1_x >= 0
		&& ft_check_hit(mlx, 'n' , mlx->player.hit1_x, mlx->player.hit1_y) != '1')
	{
		hypo[0] = (y + i) / cos((PI / 2) - (angle - PI));
		mlx->player.hit1_x = (int)mlx->player.x + x - sqrt((hypo[0] * hypo[0]) - ((y + i) * (y + i)));
		mlx->player.hit1_y = (int)mlx->player.y - i;
		i++;
	}
	i = 1;
	hypo[1] = x / cos(angle - PI);
	mlx->player.hit2_x = (int)mlx->player.x;
	mlx->player.hit2_y = (int) mlx->player.y + y - sqrt((hypo[1] * hypo[1]) - (x * x));
	while (mlx->player.hit2_y >= 0 && mlx->player.hit2_x >= 0
		&& ft_check_hit(mlx, 'w' , mlx->player.hit2_x, mlx->player.hit2_y) != '1')
	{
		hypo[1] = (x + i) / cos(angle - PI);
		mlx->player.hit2_x = (int)mlx->player.x - i;
		mlx->player.hit2_y = (int) mlx->player.y + y - sqrt((hypo[1] * hypo[1]) - ((x + i) * (x + i)));
		i++;
	}
	return (hypo);
}
