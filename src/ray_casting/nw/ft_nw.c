#include "../../../cub3D.h"

double	ft_nw(t_mlx *mlx, double x, double y, double angle)
{
	if (x / cos(angle - PI) <= y / cos((PI / 2) - (angle - PI)))
	{
		mlx->ray.hypo = ft_nw_x(mlx, x, y, angle);
		if (mlx->ray.hypo == NULL)
			return (-1);
	}
	else if (y / cos((PI / 2) - (angle - PI)) <= x / cos(angle - PI))
	{
		mlx->ray.hypo = ft_nw_y(mlx, x, y, angle);
		if (mlx->ray.hypo == NULL)
			return (-1);
	}
	return (ft_nw_1(mlx, x, y, angle));
}

double	ft_nw_1(t_mlx *mlx, double x, double y, double angle)
{
	double	hypo;

	if (mlx->ray.hypo[0] <= mlx->ray.hypo[1])
	{
		mlx->player.f_hit_x = mlx->player.hit1_x;
		mlx->player.f_hit_y = mlx->player.hit1_y;
		if (x / cos(angle - PI) <= y / cos((PI / 2) - (angle - PI)))
			mlx->player.dir = 'w';
		else
			mlx->player.dir = 'n';
		hypo = mlx->ray.hypo[0];
		free(mlx->ray.hypo);
		return (hypo);
	}
	else
		return (ft_nw_2(mlx, x, y, angle));
	return (0);
}

double	ft_nw_2(t_mlx *mlx, double x, double y, double angle)
{
	double	hypo;

	mlx->player.f_hit_x = mlx->player.hit2_x;
	mlx->player.f_hit_y = mlx->player.hit2_y;
	if (x / cos(angle - PI) <= y / cos((PI / 2) - (angle - PI)))
		mlx->player.dir = 'n';
	else
		mlx->player.dir = 'w';
	hypo = mlx->ray.hypo[1];
	free(mlx->ray.hypo);
	return (hypo);
}
