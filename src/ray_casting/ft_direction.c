#include "../../cub3D.h"

void	ft_east(t_mlx *mlx)
{
	int i;

	i = 0;
	while (mlx->map.grid[(int)mlx->player.f_hit_y][(int)mlx->player.f_hit_x] != '1')
	{
		mlx->player.f_hit_x = (int)mlx->player.x + i;
		mlx->player.f_hit_y = mlx->player.y;
		i++;
	}
}

void    ft_west(t_mlx *mlx)
{
	int i;

	i = 0;
	while (mlx->map.grid[(int)mlx->player.f_hit_y][(int)mlx->player.f_hit_x - 1] != '1')
	{
		mlx->player.f_hit_x = (int)mlx->player.x - i;
		mlx->player.f_hit_y = mlx->player.y;
		i++;
	}
}

void    ft_south(t_mlx *mlx)
{
	int i;

	i = 0;
	while (mlx->map.grid[(int)mlx->player.f_hit_y][(int)mlx->player.f_hit_x] != '1')
	{
		mlx->player.f_hit_x = mlx->player.x;
		mlx->player.f_hit_y = (int)mlx->player.y + i;
		i++;
	}
}

void    ft_north(t_mlx *mlx)
{
	int i;

	i = 0;
	while (mlx->map.grid[(int)mlx->player.f_hit_y - 1][(int)mlx->player.f_hit_x] != '1')
	{
		mlx->player.f_hit_x = mlx->player.x;
		mlx->player.f_hit_y = (int)mlx->player.y - i;
		i++;
	}

}
