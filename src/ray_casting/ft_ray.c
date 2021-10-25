#include "../../cub3D.h"

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
	my_pixel_put(buff, mlx->player.x * B_SIZE, mlx->player.y * B_SIZE, 0x0FF00FF);
//.................................................................
	ft_ray_caster(mlx, mlx->player.x - (int)mlx->player.x, mlx->player.y - (int)mlx->player.y, tmp);
	ft_raycast(mlx, buff, tmp);
	my_pixel_put(buff, mlx->player.f_hit_x * B_SIZE, mlx->player.f_hit_y * B_SIZE, 0xFFFFFF);
}

double	ft_ray_caster(t_mlx *mlx, double x, double y, double angle)
{
	int	direction;
	double	hypo;

	direction = ft_angle(mlx->player.angle);
	mlx->player.hit1_x = mlx->player.x;
	mlx->player.hit1_y = mlx->player.y;
	mlx->player.hit2_x = mlx->player.x;
	mlx->player.hit2_y = mlx->player.y;
	if (direction == 1)
		hypo = ft_se(mlx, x, y, angle);
	else if (direction == 2)
		hypo = ft_sw(mlx, x, y, angle);
	else if (direction == 3)
		hypo = ft_nw(mlx, x, y, angle);
	else if (direction == 4)
		hypo = ft_ne(mlx, x, y, angle);
	else if (direction == 5)
		ft_east(mlx);
	else if (direction == 6)
		ft_south(mlx);
	else if (direction == 7)
		ft_west(mlx);
	else if (direction == 8)
		ft_north(mlx);
	printf("hypo = %f\n", hypo);
	printf("hit_x = %f\n", mlx->player.f_hit_x);
	printf("hit_y = %f\n\n", mlx->player.f_hit_y);
	return (hypo);
}

char	ft_check_hit(t_mlx *mlx, char hit, double x, double y)
{
	if (hit == 'e')
		return (mlx->map.grid[(unsigned int)y][(unsigned int)x]);
	else if (hit == 's')
		return (mlx->map.grid[(unsigned int)y][(unsigned int)x]);
	else if (hit == 'w')
		return (mlx->map.grid[(unsigned int)y][(unsigned int)(x - 1)]);
	else if (hit == 'n')
		return (mlx->map.grid[(unsigned int)(y - 1)][(unsigned int)x]);
	return ('1');
}
