#include "../../cub3D.h"

double	ft_se(t_mlx *mlx, double x, double y, double angle)
{
	int	i;
	double	seg_x;
	double	seg_y;
	double	angle_a;
	double	angle_b;
	double	hypo_1;
	double	hypo_2;

	i = 0;
	seg_x = 1 - x;
	seg_y = 1 - y;
	angle_a = angle;
	angle_b = (PI / 2) - angle_a;
	printf("SE | ");
	if (seg_x / cos(angle_a) <= seg_y / cos(angle_b))
	{
		while (mlx->player.hit1_y <= mlx->map.g_height && mlx->player.hit1_x <= mlx->map.g_width
		&& ft_check_hit(mlx, 'e' ,mlx->player.hit1_x, mlx->player.hit1_y) != '1')
		{
			hypo_1 = (seg_x + i) / cos(angle_a);
			mlx->player.hit1_x = (int)mlx->player.x + i + 1;
			mlx->player.hit1_y = (int)mlx->player. y + y + sqrt((hypo_1 * hypo_1) - ((seg_x + i) * (seg_x + i)));
			i++;
		}
		i = 0;
		while (mlx->player.hit2_y <= mlx->map.g_height && mlx->player.hit2_x <= mlx->map.g_width
		&& ft_check_hit(mlx, 's' ,mlx->player.hit2_x, mlx->player.hit2_y) != '1')
		{
			hypo_2 = (seg_y + i) / cos(angle_b);
			mlx->player.hit2_x = (int)mlx->player.x + x + sqrt((hypo_2 * hypo_2) - ((seg_y + i) * (seg_y + i)));
			mlx->player.hit2_y = (int)mlx->player.y + i + 1;
			i++;
		}

	}
	else if (seg_y / cos(angle_b) <= seg_x / cos(angle_a))
	{
		while (mlx->player.hit1_y <= mlx->map.g_height && mlx->player.hit1_x <= mlx->map.g_width
		&& ft_check_hit(mlx, 's' ,mlx->player.hit1_x, mlx->player.hit1_y) != '1')
		{
			hypo_1 = (seg_y + i) / cos(angle_b);
			mlx->player.hit1_x = (int)mlx->player.x + x + sqrt((hypo_1 * hypo_1) - ((seg_y + i) * (seg_y + i)));
			mlx->player.hit1_y = (int)mlx->player.y + i + 1;
			i++;
		}
		i = 0;
		while (mlx->player.hit2_y <= mlx->map.g_height && mlx->player.hit2_x <= mlx->map.g_width
		&& ft_check_hit(mlx, 'e' ,mlx->player.hit2_x, mlx->player.hit2_y) != '1')
		{
			hypo_2 = (seg_x + i) / cos(angle_a);
			mlx->player.hit2_x = (int)mlx->player.x + i + 1;
			mlx->player.hit2_y = (int)mlx->player.y + y + sqrt((hypo_2 * hypo_2) - ((seg_x + i) * (seg_x + i)));
			i++;
		}
	}
	if (hypo_1 <= hypo_2)
	{
		mlx->player.f_hit_x = mlx->player.hit1_x;
		mlx->player.f_hit_y = mlx->player.hit1_y;
		return (hypo_1);
	}
	else
	{
		mlx->player.f_hit_x = mlx->player.hit2_x;
		mlx->player.f_hit_y = mlx->player.hit2_y;
		return (hypo_2);
	}
	return (0);

}
