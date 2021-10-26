#include "../../cub3D.h"

void	ft_init_ray(t_mlx *mlx)
{
	mlx->player.hit1_x = mlx->player.x;
	mlx->player.hit1_y = mlx->player.y;
	mlx->player.hit2_x = mlx->player.x;
	mlx->player.hit2_y = mlx->player.y;
	mlx->player.f_hit_x = mlx->player.x;
	mlx->player.f_hit_y = mlx->player.y;
}

int	ft_move_angle(int angle, int move)
{
	angle = angle + move;
	if (angle < 0)
		angle = 360 + angle;
	if (angle > 360)
		angle = 360 - angle;
	return (angle);
}

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
	int	i;
	int	angle;
	double	tmp;

	i = 0;
	angle = ft_move_angle(mlx->player.angle, -30);
	printf("a = %d |",  angle);
	printf("pos = [%f][%f]\n", mlx->player.x, mlx->player.y);
	my_pixel_put(buff, mlx->player.x * B_SIZE, mlx->player.y * B_SIZE, 0x0FF00FF);
	while (i < 60)
	{	
		tmp = (PI / 180) * angle;
		ft_raycast(mlx, buff, tmp);
		ft_ray_caster(mlx, mlx->player.x - (int)mlx->player.x, mlx->player.y - (int)mlx->player.y, tmp);
		my_pixel_put(buff, mlx->player.f_hit_x * B_SIZE, mlx->player.f_hit_y * B_SIZE, 0xFFFFFF);
		angle = ft_move_angle(angle, 1);
		//....................................
		printf("hit = [%f][ %f]\n", mlx->player.f_hit_x, mlx->player.f_hit_y);
		i++;
	}
	printf("\n");
}

double	ft_ray_caster(t_mlx *mlx, double x, double y, double angle)
{
	int	direction;
	double	hypo;

	direction = ft_angle(angle / (PI / 180));
	ft_init_ray(mlx);
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
//	printf("angle = %d\n", mlx->player.angle);
//	printf("hypo = %f\n", hypo);
//	printf("px = %f | py = %f\n", mlx->player.x, mlx->player.y);
//	printf("hit_x = %f | hit_y = %f\n\n", mlx->player.f_hit_x, mlx->player.f_hit_y);
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
