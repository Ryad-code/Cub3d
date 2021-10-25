#include "../../cub3D.h"

void	ft_raycast(t_mlx *mlx, t_img *buff, float angle)
{
	int i;

	i = 1;
	while (i < 60)
	{
		my_pixel_put(buff, (int)nearbyint((mlx->player.x  * B_SIZE) + (cos(angle) * i)), (int)nearbyint((mlx->player.y * B_SIZE) + (sin(angle) * i)), 0x0FF00FF);
		i++;
	}
}

void	ft_vision(t_mlx *mlx, t_img *buff)
{
	int	i;
	float	angle;
	float	tmp;
//	float	res;
//......................................................

	i = 0;
	angle = mlx->player.angle + 330;
	while (i < 1000)
	{
		tmp = (PI / 180) * (angle);
		ft_raycast(mlx, buff, tmp);
/*		res = ft_get_len(mlx->player.hit1_x - mlx->player.x, mlx->player.hit1_y - mlx->player.y);
		tmp = (PI / 180) * (mlx->player.angle - angle);
		res = res * (1 / cos(tmp));
		if ( res > 1000)
			res = 1000;
		ft_draw_col(buff, i, 0, (1000 - res) / 2, 0x0FFFFF);
//		ft_draw_col(buff, i, (1000 - res) / 2, res, 0x0000FF);
		ft_draw_text(mlx, buff, i, (1000 - res) / 2, res);//........TEXTURES*/
		i++;
		angle = angle + 0.06;
	}
}
