/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keycode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaouedj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 13:23:28 by mlaouedj          #+#    #+#             */
/*   Updated: 2021/11/15 15:15:51 by mlaouedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	if (keycode == 65361)
		mlx->player.angle -= 2;
	else if (keycode == 65363)
		mlx->player.angle += 2;
	if (mlx->player.angle < 0)
		mlx->player.angle = 360 + mlx->player.angle;
	else if (mlx->player.angle > 360)
		mlx->player.angle = mlx->player.angle - 360;
}

void	ft_move(int keycode, t_mlx *mlx)
{
	double	tmp;

	if (keycode == 97 || keycode == 119
		|| keycode == 100 || keycode == 115)
	{
		if (keycode == 119)
			tmp = (PI / 180) * mlx->player.angle;
		else if (keycode == 97)
			tmp = (PI / 180) * (mlx->player.angle + 270);
		else if (keycode == 100)
			tmp = (PI / 180) * (mlx->player.angle + 90);
		else if (keycode == 115)
			tmp = (PI / 180) * (mlx->player.angle + 180);
		if (mlx->map.grid[(int)(mlx->player.y + (sin(tmp) / 25))]
			[(int)(mlx->player.x + (cos(tmp) / 25))] != '1')
		{
			mlx->player.x = (mlx->player.x + (cos(tmp) / 25));
			mlx->player.y = (mlx->player.y + (sin(tmp) / 25));
		}
	}
}
