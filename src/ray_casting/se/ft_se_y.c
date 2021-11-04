#include "../../../cub3D.h"

double	*ft_se_y(t_mlx *mlx, double x, double y, double angle)
{
	int		i;
	double	*hypo;

	i = 0;
	hypo = malloc(sizeof(double) * 2);
	if (hypo == NULL)
		return (NULL);
	while (mlx->player.hit1_y <= mlx->map.g_height && mlx->player.hit1_x
		<= mlx->map.g_width && ft_check_hit(mlx, 's',
			mlx->player.hit1_x, mlx->player.hit1_y) != '1')
	{
		hypo[0] = ((1 - y) + i) / cos(PI / 2 - angle);
		mlx->player.hit1_x = (int)mlx->player.x + x + sqrt(
				hypo[0] * hypo[0] - (((1 - y) + i) * ((1 - y) + i)));
		mlx->player.hit1_y = (int)mlx->player.y + i + 1;
		i++;
	}
	hypo[1] = ft_se_y_1(mlx, x, y, angle);
	return (hypo);
}

double	ft_se_y_1(t_mlx *mlx, double x, double y, double angle)
{
	int		i;
	double	hypo;

	i = 0;
	while (mlx->player.hit2_y <= mlx->map.g_height && mlx->player.hit2_x
		<= mlx->map.g_width && ft_check_hit(mlx, 'e',
			mlx->player.hit2_x, mlx->player.hit2_y) != '1')
	{
		hypo = ((1 - x) + i) / cos(angle);
		mlx->player.hit2_x = (int)mlx->player.x + i + 1;
		mlx->player.hit2_y = (int)mlx->player.y + y + sqrt(
				hypo * hypo - (((1 - x) + i) * ((1 - x) + i)));
		i++;
	}
	return (hypo);
}
