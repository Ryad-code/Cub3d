#include "../../../cub3D.h"

double	ft_ne(t_mlx *mlx, double x, double y, double angle)
{
	double	*hypo;
	double	hypo_1;
	double	hypo_2;

	if ((1 - x) / cos((2 * PI) - angle) <= y / cos((PI / 2) - ((2 * PI) - angle)))
	{
		hypo = ft_ne_x(mlx, x, y, angle);
		if (hypo == NULL)
			return (-1);
		hypo_1 = hypo[0];
		hypo_2 = hypo[1];
		free(hypo);
	}
	else if (y / cos((PI / 2) - ((2 * PI) - angle)) <= (1 - x) / cos((2 * PI) - angle))
	{
		hypo = ft_ne_y(mlx, x, y, angle);
		if (hypo == NULL)
			return (-1);
		hypo_1 = hypo[0];
		hypo_2 = hypo[1];
		free(hypo);
	}
	if (hypo_1 <= hypo_2)
	{
		mlx->player.f_hit_x =  mlx->player.hit1_x;
		mlx->player.f_hit_y =  mlx->player.hit1_y;
		if ((1 - x) / cos((2 * PI) - angle) <= y / cos((PI / 2) - ((2 * PI) - angle)))
			mlx->player.dir = 'e';
		else
			mlx->player.dir = 'n';
		return (hypo_1);
	}
	else
	{
		mlx->player.f_hit_x =  mlx->player.hit2_x;
		mlx->player.f_hit_y =  mlx->player.hit2_y;
		if ((1 - x) / cos((2 * PI) - angle) <= y / cos((PI / 2) - ((2 * PI) - angle)))
			mlx->player.dir = 'n';
		else
			mlx->player.dir = 'e';
		return (hypo_2);
	}
	return (0);
}

double	*ft_ne_x(t_mlx *mlx, double x, double y, double angle)
{
	int	i;
	double	*hypo;

	i = 1;
	hypo = malloc(sizeof(double) * 2);
	if (hypo == NULL)
		return (NULL);
	hypo[0] = (1 - x) / cos((2 * PI) - angle);
	mlx->player.hit1_x = (int)mlx->player.x + 1;
	mlx->player.hit1_y = (int)mlx->player.y + y - sqrt((hypo[0] * hypo[0]) - ((1 - x) * (1 - x)));
	while (mlx->player.hit1_y >= 0 && mlx->player.hit1_x <= mlx->map.g_width
		&& ft_check_hit(mlx, 'e' , mlx->player.hit1_x, mlx->player.hit1_y) != '1')
	{
		hypo[0] = ((1 - x) + i) / cos((2 * PI) - angle);
		mlx->player.hit1_x = (int)mlx->player.x + 1 + i;
		mlx->player.hit1_y = (int)mlx->player.y + y - sqrt((hypo[0] * hypo[0]) - (((1 - x) + i) * ((1 - x) + i)));
		i++;
	}
	i = 1;
	hypo[1] = y / cos((PI / 2) - ((2 * PI) - angle));
	mlx->player.hit2_x = (int)mlx->player.x + x + sqrt((hypo[1] * hypo[1]) - (y * y));
	mlx->player.hit2_y = (int)mlx->player.y;
	while (mlx->player.hit2_y >= 0 && mlx->player.hit2_x <= mlx->map.g_width
		&& ft_check_hit(mlx, 'n' , mlx->player.hit2_x, mlx->player.hit2_y) != '1')
	{
		hypo[1] = (y + i) / cos((PI / 2) - ((2 * PI) - angle));
		mlx->player.hit2_x = (int)mlx->player.x + x + sqrt((hypo[1] * hypo[1]) - ((y + i) * (y + i)));
		mlx->player.hit2_y = (int)mlx->player.y - i;
		i++;
	}
	return (hypo);
}

double  *ft_ne_y(t_mlx *mlx, double x, double y, double angle)
{
	int	i;
	double	*hypo;

	i = 1;
	hypo = malloc(sizeof(double) * 2);
	if (hypo == NULL)
		return (NULL);
	hypo[0] = y / cos((PI / 2) - ((2 * PI) - angle));
	mlx->player.hit1_x = (int)mlx->player.x + x + sqrt((hypo[0] * hypo[0]) - (y * y));
	mlx->player.hit1_y = (int)mlx->player.y;
	while (mlx->player.hit1_y >= 0 && mlx->player.hit1_x <= mlx->map.g_width
		&& ft_check_hit(mlx, 'n' , mlx->player.hit1_x, mlx->player.hit1_y) != '1')
	{
		hypo[0] = (y + i) / cos((PI / 2) - ((2 * PI) - angle));
		mlx->player.hit1_x = (int)mlx->player.x + x + sqrt((hypo[0] * hypo[0]) - ((y + i) * (y + i)));
		mlx->player.hit1_y = (int)mlx->player.y - i;
		i++;
	}
	i = 1;
	hypo[1] = (1 - x) / cos((2 * PI) - angle);
	mlx->player.hit2_x = (int)mlx->player.x + 1;
	mlx->player.hit2_y = (int)mlx->player.y + y - sqrt((hypo[1] * hypo[1]) - ((1 - x) * (1 - x)));
	while (mlx->player.hit2_y >= 0 && mlx->player.hit2_x <= mlx->map.g_width
		&& ft_check_hit(mlx, 'e' , mlx->player.hit2_x, mlx->player.hit2_y) != '1')
	{
		hypo[1] = ((1 - x) + i) / cos((2 * PI) - angle);
		mlx->player.hit2_x = (int)mlx->player.x + 1 + i;
		mlx->player.hit2_y = (int)mlx->player.y + y - sqrt((hypo[1] * hypo[1]) - (((1 - x) + i) * ((1 - x) + i)));
		i++;
	}
	return (hypo);
}
