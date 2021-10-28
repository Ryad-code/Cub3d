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

double	ft_move_angle(double angle, double move)
{
	angle = angle + move;
	if (angle <= 0)
		angle = 360 + angle;
	if (angle >= 360)
		angle = angle - 360;
	return (angle);
}

int	ft_angle(double angle)
{
	if (angle == 0 || angle == 360)
		return (1);
	else if (angle == 90)
		return (2);
	else if (angle == 180)
		return (3);
	else if (angle == 270)
		return (4);
	else if (angle > 0 && angle < 90)
		return (5);
	else if (angle > 90 && angle < 180)
		return (6);
	else if (angle > 180 && angle < 270)
		return (7);
	else if (angle > 270 && angle < 360)
		return (8);
	return (-1);
}

void	ft_vector(t_mlx *mlx, t_img *buff)
{
	int	i;
	double	angle;
	double	tmp;
	double dist;
	int	res;
	double hit;

	i = 0;
	angle = ft_move_angle(mlx->player.angle, - 30);
	while (i < S_WIDTH)
	{
		tmp = (PI / 180) * angle;
		dist = ft_ray_caster(mlx, mlx->player.x - (int)mlx->player.x, mlx->player.y - (int)mlx->player.y, tmp);
		res = (int)nearbyint((1 / dist) * S_HEIGHT);
		res = (int)nearbyint(res * (1 / cos((PI / 180) * (mlx->player.angle - angle))));
		if (res > S_HEIGHT)
			res = S_HEIGHT;
		hit = ft_texture(mlx, mlx->player.dir);
		ft_draw_col(buff, i, 0, (S_HEIGHT - res) / 2, 0x0FFFFF);
		ft_draw_t_col(mlx, buff, i, (S_HEIGHT - res) / 2, res, hit, &mlx->text);
		angle = ft_move_angle(angle, 0.06);
		i++;
	}
}

double	ft_ray_caster(t_mlx *mlx, double x, double y, double angle)
{
	int	direction;
	double	hypo;

	direction = ft_angle(angle / (PI / 180));
	ft_init_ray(mlx);
	if (direction == 1)
		hypo = ft_east(mlx);
	else if (direction == 2)
		hypo = ft_south(mlx);
	else if (direction == 3)
		hypo = ft_west(mlx);
	else if (direction == 4)
		hypo = ft_north(mlx);
	else if (direction == 5)
		hypo = ft_se(mlx, x, y, angle);
	else if (direction == 6)
		hypo = ft_sw(mlx, x, y, angle);
	else if (direction == 7)
		hypo = ft_nw(mlx, x, y, angle);
	else if (direction == 8)
		hypo = ft_ne(mlx, x, y, angle);
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
