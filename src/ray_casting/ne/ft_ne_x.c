#include "../../../cub3D.h"

double	*ft_ne_x(t_mlx *mlx, double x, double y, double angle)
{
	int		i;
	double	*hypo;

	i = 1;
	hypo = malloc(sizeof(double) * 2);
	if (hypo == NULL)
		return (NULL);
	hypo[0] = (1 - x) / cos((2 * PI) - angle);
	mlx->player.hit1_x = (int)mlx->player.x + 1;
	mlx->player.hit1_y = (int)mlx->player.y + y
		- sqrt((hypo[0] * hypo[0]) - ((1 - x) * (1 - x)));
	while (mlx->player.hit1_y >= 0 && mlx->player.hit1_x <= mlx->map.g_width
		&& ft_check_hit(mlx, 'e', mlx->player.hit1_x,
			mlx->player.hit1_y) != '1')
	{
		hypo[0] = ((1 - x) + i) / cos((2 * PI) - angle);
		mlx->player.hit1_x = (int)mlx->player.x + 1 + i;
		mlx->player.hit1_y = (int)mlx->player.y + y - sqrt((hypo[0]
					* hypo[0]) - (((1 - x) + i) * ((1 - x) + i)));
		i++;
	}
	hypo[1] = ft_ne_x_1(mlx, x, y, angle);
	return (hypo);
}

double	ft_ne_x_1(t_mlx *mlx, double x, double y, double angle)
{	
	int		i;
	double	hypo;

	i = 1;
	hypo = y / cos((PI / 2) - ((2 * PI) - angle));
	mlx->player.hit2_x = (int)mlx->player.x + x + sqrt((hypo * hypo) - (y * y));
	mlx->player.hit2_y = (int)mlx->player.y;
	while (mlx->player.hit2_y >= 0 && mlx->player.hit2_x <= mlx->map.g_width
		&& ft_check_hit(mlx, 'n', mlx->player.hit2_x,
			mlx->player.hit2_y) != '1')
	{
		hypo = (y + i) / cos((PI / 2) - ((2 * PI) - angle));
		mlx->player.hit2_x = (int)mlx->player.x + x + sqrt((hypo
					* hypo) - ((y + i) * (y + i)));
		mlx->player.hit2_y = (int)mlx->player.y - i;
		i++;
	}
	return (hypo);
}
