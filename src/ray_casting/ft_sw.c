#include "../../cub3D.h"

double	ft_sw(t_mlx *mlx, double x, double y, double angle)
{
	int	i;
	double	seg_x;
	double	seg_y;
	double	angle_a;
	double	angle_b;
	double	hypo_1;
	double	hypo_2;

	i = 1;
	seg_x = x;
	seg_y = 1 - y;
	angle_a = angle - (PI / 2);
	angle_b = (PI / 2) - angle_a;
	if (seg_x / cos(angle_b) <= seg_y / cos(angle_a))
	{
		hypo_1 = seg_x / cos(angle_b);
		mlx->player.hit1_x = (int)mlx->player.x;
		mlx->player.hit1_y = (int)mlx->player.y + y + sqrt((hypo_1 * hypo_1) - (seg_x * seg_x));
		while (mlx->player.hit1_y <= mlx->map.g_height && mlx->player.hit1_x >= 0
		&& ft_check_hit(mlx, 'w' ,mlx->player.hit1_x, mlx->player.hit1_y) != '1')
		{
			hypo_1 = (seg_x + i) / cos(angle_b);
			mlx->player.hit1_x = (int)mlx->player.x - i;
			mlx->player.hit1_y = (int)mlx->player.y + y + sqrt((hypo_1 * hypo_1) - ((seg_x + i) * (seg_x + i)));
			i++;
		}
		i = 0;
		hypo_2 = seg_y / cos(angle_a);
		mlx->player.hit2_x = (int)mlx->player.x + x - sqrt((hypo_2 * hypo_2) - (seg_y * seg_y));
		mlx->player.hit2_y = (int)mlx->player.y + 1;
		while (mlx->player.hit2_y <= mlx->map.g_height && mlx->player.hit2_x >= 0
		&& ft_check_hit(mlx, 's' , mlx->player.hit2_x, mlx->player.hit2_y) != '1')
		{
			hypo_2 = (seg_y + i) / cos(angle_a);
			mlx->player.hit2_x = (int)mlx->player.x + x - sqrt((hypo_2 * hypo_2) - ((seg_y + i) * (seg_y + i)));
			mlx->player.hit2_y = (int)mlx->player.y + 1 + i;
			i++;
		}
	}
	else if (seg_y / cos(angle_a) <= seg_x / cos(angle_b))
	{
		hypo_1 = seg_y / cos(angle_a);
		mlx->player.hit1_x = (int)mlx->player.x + x - sqrt((hypo_1 * hypo_1) - (seg_y * seg_y));
		mlx->player.hit1_y = (int)mlx->player.y + 1;
		while (mlx->player.hit1_y <= mlx->map.g_height && mlx->player.hit1_x >= 0
		&& ft_check_hit(mlx, 's' , mlx->player.hit1_x, mlx->player.hit1_y) != '1')
		{
			hypo_1 = (seg_y + i) / cos(angle_a);
			mlx->player.hit1_x = (int)mlx->player.x + x - sqrt((hypo_1 * hypo_1) - ((seg_y + i) * (seg_y + i)));
			mlx->player.hit1_y = (int)mlx->player.y + 1 + i;
			i++;
		}
		i = 0;
		hypo_2 = seg_x / cos(angle_b);
		mlx->player.hit2_x = (int)mlx->player.x;
		mlx->player.hit2_y = (int) mlx->player.y + y + sqrt((hypo_2 * hypo_2) - (seg_x * seg_x));
		while (mlx->player.hit2_y <= mlx->map.g_height && mlx->player.hit2_x >= 0
		&& ft_check_hit(mlx, 'w' , mlx->player.hit2_x, mlx->player.hit2_y) != '1')
		{
			hypo_2 = (seg_x + i) / cos(angle_b);
			mlx->player.hit2_x = (int)mlx->player.x - i;
			mlx->player.hit2_y = (int) mlx->player.y + y + sqrt((hypo_2 * hypo_2) - ((seg_x + i) * (seg_x + i)));
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
