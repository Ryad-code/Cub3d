#include "../../../cub3D.h"

double	ft_ne(t_mlx *mlx, double x, double y, double angle)
{
	if ((1 - x) / cos((2 * PI) - angle) <= y
		/ cos((PI / 2) - ((2 * PI) - angle)))
	{
		mlx->ray.hypo = ft_ne_x(mlx, x, y, angle);
		if (mlx->ray.hypo == NULL)
			return (-1);
	}
	else if (y / cos((PI / 2) - ((2 * PI) - angle))
		<= (1 - x) / cos((2 * PI) - angle))
	{
		mlx->ray.hypo = ft_ne_y(mlx, x, y, angle);
		if (mlx->ray.hypo == NULL)
			return (-1);
	}
	return (ft_ne_1(mlx, x, y, angle));
}

double	ft_ne_1(t_mlx *mlx, double x, double y, double angle)
{
	double	hypo;

	if (mlx->ray.hypo[0] <= mlx->ray.hypo[1])
	{
		mlx->player.f_hit_x = mlx->player.hit1_x;
		mlx->player.f_hit_y = mlx->player.hit1_y;
		if ((1 - x) / cos((2 * PI) - angle) <= y
			/ cos((PI / 2) - ((2 * PI) - angle)))
			mlx->player.dir = 'e';
		else
			mlx->player.dir = 'n';
		hypo = mlx->ray.hypo[0];
		free(mlx->ray.hypo);
		return (hypo);
	}
	else
		return (ft_ne_2(mlx, x, y, angle));
	return (0);
}

double	ft_ne_2(t_mlx *mlx, double x, double y, double angle)
{
	double	hypo;

	mlx->player.f_hit_x = mlx->player.hit2_x;
	mlx->player.f_hit_y = mlx->player.hit2_y;
	if ((1 - x) / cos((2 * PI) - angle)
		<= y / cos((PI / 2) - ((2 * PI) - angle)))
		mlx->player.dir = 'n';
	else
		mlx->player.dir = 'e';
	hypo = mlx->ray.hypo[1];
	free(mlx->ray.hypo);
	return (hypo);
}
