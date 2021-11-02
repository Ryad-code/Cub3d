#include "../cub3D.h"

void	ft_keycode(int keycode, t_mlx *mlx)
{
	(void)mlx;
	if (keycode == 65307)
	{
		ft_free_data(mlx);
		exit(0);
	}
	ft_turn(keycode, mlx);
	ft_move(keycode, mlx);
}

void	ft_turn(int keycode, t_mlx *mlx)
{
	if (keycode == 113)
		mlx->player.angle -= 2;
	else if (keycode == 119)
		mlx->player.angle += 2;
	if (mlx->player.angle < 0)
		mlx->player.angle = 360 + mlx->player.angle;
	else if (mlx->player.angle > 360)
		mlx->player.angle = mlx->player.angle - 360;
}

void	ft_move(int keycode, t_mlx *mlx)
{
	double tmp;
	
	if (keycode == 65361 || keycode == 65362 || keycode == 65363 || keycode == 65364)
	{
		if (keycode == 65362)
			tmp = (PI / 180) * mlx->player.angle;
		else if (keycode == 65361)
			tmp =  (PI / 180) * (mlx->player.angle + 270);
		else if (keycode == 65363)
			tmp =  (PI / 180) * (mlx->player.angle + 90);
		else if (keycode == 65364)
			tmp =  (PI / 180) * (mlx->player.angle + 180);
		if (mlx->map.grid[(int)(mlx->player.y + (sin(tmp) / 25))]
			[(int)(mlx->player.x + (cos(tmp) / 25))] != '1')
		{
			mlx->player.x = (mlx->player.x + (cos(tmp) / 25));
			mlx->player.y = (mlx->player.y + (sin(tmp) / 25));
		}
	}
}
