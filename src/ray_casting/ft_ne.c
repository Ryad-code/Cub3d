#include "../../cub3D.h"

double	ft_ne(t_mlx *mlx, double x, double y, double angle)
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
	seg_y = y;
	angle_a = (2 * PI) - angle;
	angle_b = (PI / 2) - angle_a;
	printf("NE | ");
	if (seg_x / cos(angle_a) <= seg_y / cos(angle_b))
	{
		hypo_1 = seg_x / cos(angle_a);
		mlx->player.hit1_x = (int)mlx->player.x + 1;
		mlx->player.hit1_y = (int)mlx->player.y + y - sqrt((hypo_1 * hypo_1) - (seg_x * seg_x));
		while (mlx->player.hit1_y >= 0 && mlx->player.hit1_x <= mlx->map.g_width
		&& ft_check_hit(mlx, 'e' , mlx->player.hit1_x, mlx->player.hit1_y) != '1')
		{
			hypo_1 = (seg_x + i) / cos(angle_a);
			mlx->player.hit1_x = (int)mlx->player.x + 1 + i;
			mlx->player.hit1_y = (int)mlx->player.y + y - sqrt((hypo_1 * hypo_1) - ((seg_x + i) * (seg_x + i)));
			i++;
		}
		i = 0;
		hypo_2 = seg_y / cos(angle_b);
		mlx->player.hit2_x = (int)mlx->player.x + x + sqrt((hypo_2 * hypo_2) - (seg_y * seg_y));
		mlx->player.hit2_y = (int)mlx->player.y;
		while (mlx->player.hit2_y >= 0 && mlx->player.hit2_x <= mlx->map.g_width
		&& ft_check_hit(mlx, 'n' , mlx->player.hit2_x, mlx->player.hit2_y) != '1')
		{
			hypo_2 = (seg_y + i) / cos(angle_b);
			mlx->player.hit2_x = (int)mlx->player.x + x + sqrt((hypo_2 * hypo_2) - ((seg_y + i) * (seg_y + i)));
			mlx->player.hit2_y = (int)mlx->player.y - i;
			i++;
		}
	}
	else if (seg_y / cos(angle_b) <= seg_x / cos(angle_a))
	{
		hypo_1 = seg_y / cos(angle_b);
		mlx->player.hit1_x = (int)mlx->player.x + x + sqrt((hypo_1 * hypo_1) - (seg_y * seg_y));
		mlx->player.hit1_y = (int)mlx->player.y;
		while (mlx->player.hit1_y >= 0 && mlx->player.hit1_x <= mlx->map.g_width
		&& ft_check_hit(mlx, 'n' , mlx->player.hit1_x, mlx->player.hit1_y) != '1')
		{
			hypo_1 = (seg_y + i) / cos(angle_b);
			mlx->player.hit1_x = (int)mlx->player.x + x + sqrt((hypo_1 * hypo_1) - ((seg_y + i) * (seg_y + i)));
			mlx->player.hit1_y = (int)mlx->player.y - i;
			i++;
		}
		i = 0;
		hypo_2 = seg_x / cos(angle_a);
		mlx->player.hit2_x = (int)mlx->player.x + 1;
		mlx->player.hit2_y = (int)mlx->player.y + y - sqrt((hypo_2 * hypo_2) - (seg_x * seg_x));
		while (mlx->player.hit2_y >= 0 && mlx->player.hit2_x <= mlx->map.g_width
		&& ft_check_hit(mlx, 'e' , mlx->player.hit2_x, mlx->player.hit2_y) != '1')
		{
			hypo_2 = (seg_x + i) / cos(angle_a);
			mlx->player.hit2_x = (int)mlx->player.x + 1 + i;
			mlx->player.hit2_y = (int)mlx->player.y + y - sqrt((hypo_2 * hypo_2) - ((seg_x + i) * (seg_x + i)));
			i++;
		}
	}
	if (hypo_1 <= hypo_2)
	{
		mlx->player.f_hit_x =  mlx->player.hit1_x;
		mlx->player.f_hit_y =  mlx->player.hit1_y;
		return (hypo_1);
	}
	else
	{
		mlx->player.f_hit_x =  mlx->player.hit2_x;
		mlx->player.f_hit_y =  mlx->player.hit2_y;
		return (hypo_2);
	}
	return (0);
}
