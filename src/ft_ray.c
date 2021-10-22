#include "../cub3D.h"

int	ft_angle(int angle)
{
	if (angle > 0 && angle < 90)
		return (1);
	else if (angle > 90 && angle < 180)
		return (2);
	else if (angle > 180 && angle < 270)
		return (3);
	else if (angle > 270 && angle < 360)
		return (4);
	else if (angle == 0 || angle == 360)
		return (5);
	else if (angle == 90)
		return (6);
	else if (angle == 180)
		return (7);
	else if (angle == 270)
		return (8);
	return (-1);
}

void	ft_vector(t_mlx *mlx, t_img *buff)
{
	double tmp;

	tmp = (PI / 180) * mlx->player.angle;
//.................................................................
//	ft_draw_grid(mlx, buff);
	my_pixel_put(buff, mlx->player.x * B_SIZE, mlx->player.y * B_SIZE, 0x0FF00FF);
//.................................................................
	ft_find_hypo(mlx, mlx->player.x - (int)mlx->player.x, mlx->player.y - (int)mlx->player.y, tmp);
	ft_raycast(mlx, buff, tmp);
	my_pixel_put(buff, (floor(mlx->player.x) + mlx->player.ray_x) * B_SIZE,
		(floor(mlx->player.y) + mlx->player.ray_y) * B_SIZE, 0x0FF00FF);

//	ft_find_hypo(mlx, mlx->player.x - (int)mlx->player.x, mlx->player.y - (int)mlx->player.y, tmp);

	printf("angle = %d | rad = %f\n\n", mlx->player.angle, tmp);

}

double	ft_find_hypo(t_mlx *mlx, double x, double y, double angle)
{
	double	seg_x;
	double	seg_y;
	double	angle_a;
	double	angle_b;
	int	direction;
	double	hypo_x;
	double	hypo_y;
	double	hypo;

	direction = ft_angle(mlx->player.angle);
	if (direction == 1)
	{
		seg_x = 1 - x;
		seg_y = 1 - y;
		angle_a = angle;
		angle_b = (PI / 2) - angle_a;
		hypo_x = seg_x / cos(angle_a);
		hypo_y = seg_y / cos(angle_b);
		if (hypo_x <= hypo_y)
		{
			hypo = hypo_x;
			mlx->player.ray_x = 1;
			mlx->player.ray_y = y + sqrt((hypo * hypo) - (seg_x * seg_x));
		}
		else if (hypo_y <= hypo_x)
		{
			hypo = hypo_y;
			mlx->player.ray_x = x + sqrt((hypo * hypo) - (seg_y * seg_y));
			mlx->player.ray_y = 1;
		}
	}
	else if (direction == 2)
	{
		seg_x = x;
		seg_y = 1 - y;
		angle_a = angle - (PI / 2);
		angle_b = (PI / 2) - angle_a;
		hypo_y = seg_y / cos(angle_a);
		hypo_x = seg_x / cos(angle_b);
		if (hypo_x <= hypo_y)
		{
			hypo = hypo_x;
			mlx->player.ray_x = 0;
			mlx->player.ray_y = y + sqrt((hypo * hypo) - (seg_x * seg_x));
		}
		else if (hypo_y <= hypo_x)
		{
			hypo = hypo_y;
			mlx->player.ray_x = x - sqrt((hypo * hypo) - (seg_y * seg_y));
			mlx->player.ray_y = 1;
		}
	}
	else if (direction == 3)
	{
		seg_x = x;
		seg_y = y;
		angle_a = angle - PI;
		angle_b = (PI / 2) - angle_a;
		hypo_x = seg_x / cos(angle_a);
		hypo_y = seg_y / cos(angle_b);
		if (hypo_x <= hypo_y)
		{
			hypo = hypo_x;
			mlx->player.ray_x = 0;
			mlx->player.ray_y = y - sqrt((hypo * hypo) - (seg_x * seg_x));
		}
		else if (hypo_y <= hypo_x)
		{
			hypo = hypo_y;
			mlx->player.ray_x = x - sqrt((hypo * hypo) - (seg_y * seg_y));
			mlx->player.ray_y = 0;
		}
	}
	else if (direction == 4)
	{
		seg_x = 1 - x;
		seg_y = y;
		angle_a = (2 * PI) - angle;
		angle_b = (PI / 2) - angle_a;
		hypo_x = seg_x / cos(angle_a);
		hypo_y = seg_y / cos(angle_b);
		if (hypo_x <= hypo_y)
		{
			hypo = hypo_x;
			mlx->player.ray_x = 1;
			mlx->player.ray_y = y - sqrt((hypo * hypo) - (seg_x * seg_x));
		}
		else if (hypo_y <= hypo_x)
		{
			hypo = hypo_y;
			mlx->player.ray_x = x + sqrt((hypo * hypo) - (seg_y * seg_y));
			mlx->player.ray_y = 0;
		}
	}
	else if (direction == 5)
	{
		mlx->player.ray_x = 1;
		mlx->player.ray_y = y;
	}
	else if (direction == 6)
	{
		mlx->player.ray_x = x;
		mlx->player.ray_y = 1;
	}
	else if (direction == 7)
	{
		mlx->player.ray_x = 0;
		mlx->player.ray_y = y;
	}
	else if (direction == 8)
	{
		mlx->player.ray_x = x;
		mlx->player.ray_y = 0;
	}
	mlx->player.ray_x = mlx->player.ray_x;
	mlx->player.ray_x = mlx->player.ray_x;
	printf("rel_x = %f | rel_y = %f\n", x, y);
	printf("rx = %f | ry = %f\n", mlx->player.ray_x, mlx->player.ray_y);
	printf("direction = %d\n", direction);
	return (hypo);
}
