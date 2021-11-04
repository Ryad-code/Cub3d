#include "../../cub3D.h"

void	ft_vector_1(t_mlx *mlx, t_img *buff)
{
	int		i;
	double	angle;
	double	tmp;

	i = 0;
	angle = ft_move_angle(mlx->player.angle, -30);
	while (i < S_WIDTH)
	{
		tmp = (PI / 180) * angle;
		ft_vector_2(mlx, angle, tmp);
		if (mlx->ray.wall_height > S_HEIGHT)
			mlx->ray.f_wall_height = S_HEIGHT;
		ft_draw_col_c(buff, i, (S_HEIGHT - mlx->ray.wall_height) / 2,
			mlx->arg.f.color);
		ft_draw_col_f(buff, i, S_HEIGHT / 2, mlx->arg.c.color);
		ft_draw_t_col(mlx, buff, i, (S_HEIGHT - mlx->ray.f_wall_height) / 2);
		angle = ft_move_angle(angle, 0.06);
		i++;
	}
}

void	ft_vector_2(t_mlx *mlx, double angle, double tmp)
{
	mlx->ray.dist = ft_ray_caster(mlx, mlx->player.x - (int)mlx->player.x,
			mlx->player.y - (int)mlx->player.y, tmp);
	mlx->ray.wall_height = (int)nearbyint((1 / mlx->ray.dist) * S_HEIGHT);
	mlx->ray.wall_height = (int)nearbyint(mlx->ray.wall_height
			* (1 / cos((PI / 180) * (mlx->player.angle - angle))));
	mlx->ray.f_wall_height = mlx->ray.wall_height;
}
