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
	ft_ray_caster(mlx, mlx->player.x - (int)mlx->player.x, mlx->player.y - (int)mlx->player.y, tmp);
	ft_raycast(mlx, buff, tmp);
	my_pixel_put(buff, ((int)mlx->player.x + mlx->player.hit1_x) * B_SIZE,
		((int)mlx->player.y + mlx->player.hit1_y) * B_SIZE, 0x0FF00FF);//collision point
	my_pixel_put(buff, ((int)mlx->player.x + mlx->player.hit2_x) * B_SIZE,
               ((int)mlx->player.y + mlx->player.hit2_y) * B_SIZE, 0x0FF00FF);
}

double	ft_ray_caster(t_mlx *mlx, double x, double y, double angle)
{
	int	direction;
	int	square[2];
	double	hypo;

	direction = ft_angle(mlx->player.angle);
	square[0] = (int)mlx->player.y;
	square[1] = (int)mlx->player.x;
	mlx->player.hit1_x = 0;
	mlx->player.hit1_y = 0;
	mlx->player.hit2_x = 0;
	mlx->player.hit2_y = 0;
	if (direction == 1)
		hypo = ft_se(mlx, x, y, angle, square);
	else if (direction == 2)
		hypo = ft_sw(mlx, x, y, angle, square);
	else if (direction == 3)
		hypo = ft_nw(mlx, x, y, angle, square);
	else if (direction == 4)
		hypo = ft_ne(mlx, x, y, angle, square);
	else if (direction == 5)
	{
		mlx->player.hit1_x = 1;
		mlx->player.hit1_y = y;
		mlx->player.hit2_x = 2;
		mlx->player.hit2_y = y;
	}
	else if (direction == 6)
	{
		mlx->player.hit1_x = x;
		mlx->player.hit1_y = 1;
		mlx->player.hit2_x = x;
		mlx->player.hit2_y = 2;
	}
	else if (direction == 7)
	{
		mlx->player.hit1_x = 0;
		mlx->player.hit1_y = y;
		mlx->player.hit2_x = -1;
		mlx->player.hit2_y = y;
	}
	else if (direction == 8)
	{
		mlx->player.hit1_x = x;
		mlx->player.hit1_y = 0;
		mlx->player.hit2_x = x;
		mlx->player.hit2_y = -1;
	}
//	printf("x = %f | y = %f\n", mlx->player.x, mlx->player.y);
//	printf("rel_x = %f | rel_y = %f\n", x, y);
//	printf("hit1_x = %f | hit1_y = %f\n", mlx->player.hit1_x, mlx->player.hit1_y);
//	printf("hit2_x = %f | hit2_y = %f\n", mlx->player.hit2_x, mlx->player.hit2_y);
	printf("angle = %d\n\n", mlx->player.angle);
//	printf("d = %d | %c\n", direction, mlx->player.dir);
	return (hypo);
}
