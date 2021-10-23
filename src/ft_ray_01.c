#include "../cub3D.h"

int	ft_get_len(float cos, float sin)
{
	float	res;

	res = sqrt((cos * cos) + (sin * sin));

	res = 100000 / res;
	return (res);
}

void	ft_raycast(t_mlx *mlx, t_img *buff, float angle)
{
	int i;

	i = 1;
//	while (mlx->map.grid[(int)(mlx->player.y + (sin(angle) * i)) / 100]
//		[(int)(mlx->player.x + (cos(angle) * i)) / 100] != '1')
	while (i < 20)
	{
		my_pixel_put(buff, (int)nearbyint((mlx->player.x  * B_SIZE) + (cos(angle) * i)), (int)nearbyint((mlx->player.y * B_SIZE) + (sin(angle) * i)), 0x0FF00FF);
		i++;
	}
//	mlx->player.ray_x = mlx->player.x + (cos(angle) * i);
//	mlx->player.ray_y = mlx->player.y + (sin(angle) * i);
}

void	ft_vision(t_mlx *mlx, t_img *buff)
{
	int	i;
	float	angle;
	float	tmp;
	float	res;
//......................................................

	i = 0;
	angle = mlx->player.angle + 330;
	while (i < 1000)
	{
		tmp = (PI / 180) * (angle);
		ft_raycast(mlx, buff, tmp);
		res = ft_get_len(mlx->player.hit1_x - mlx->player.x, mlx->player.hit1_y - mlx->player.y);
		tmp = (PI / 180) * (mlx->player.angle - angle);
		res = res * (1 / cos(tmp));
		if ( res > 1000)
			res = 1000;
		ft_draw_col(buff, i, 0, (1000 - res) / 2, 0x0FFFFF);
//		ft_draw_col(buff, i, (1000 - res) / 2, res, 0x0000FF);
		ft_draw_text(mlx, buff, i, (1000 - res) / 2, res);//........TEXTURES
		i++;
		angle = angle + 0.06;
	}
}
