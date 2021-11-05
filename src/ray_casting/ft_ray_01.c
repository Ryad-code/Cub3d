/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ray_01.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaouedj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 13:25:19 by mlaouedj          #+#    #+#             */
/*   Updated: 2021/11/05 13:25:20 by mlaouedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

double	ft_ray_caster(t_mlx *mlx, double x, double y, double angle)
{
	int		direction;
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
