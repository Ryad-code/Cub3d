/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sw.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaouedj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 13:26:55 by mlaouedj          #+#    #+#             */
/*   Updated: 2021/11/05 13:26:57 by mlaouedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../cub3D.h"

double	ft_sw(t_mlx *mlx, double x, double y, double angle)
{
	if (x / cos((PI / 2) - (angle - (PI / 2)))
		<= (1 - y) / cos(angle - (PI / 2)))
	{
		mlx->ray.hypo = ft_sw_x(mlx, x, y, angle);
		if (mlx->ray.hypo == NULL)
			return (-1);
	}
	else if ((1 - y) / cos(angle - (PI / 2))
		<= x / cos((PI / 2) - (angle - (PI / 2))))
	{
		mlx->ray.hypo = ft_sw_y(mlx, x, y, angle);
		if (mlx->ray.hypo == NULL)
			return (-1);
	}
	return (ft_sw_1(mlx, x, y, angle));
}

double	ft_sw_1(t_mlx *mlx, double x, double y, double angle)
{
	double	hypo;

	if (mlx->ray.hypo[0] <= mlx->ray.hypo[1])
	{
		 mlx->player.f_hit_x = mlx->player.hit1_x;
		 mlx->player.f_hit_y = mlx->player.hit1_y;
		 if (x / cos((PI / 2) - (angle - (PI / 2)))
			<= (1 - y) / cos(angle - (PI / 2)))
			 mlx->player.dir = 'w';
		 else
			 mlx->player.dir = 's';
		 hypo = mlx->ray.hypo[0];
		 free(mlx->ray.hypo);
		 return (hypo);
	}
	else
		return (ft_sw_2(mlx, x, y, angle));
	return (0);
}

double	ft_sw_2(t_mlx *mlx, double x, double y, double angle)
{
	double	hypo;

	mlx->player.f_hit_x = mlx->player.hit2_x;
	mlx->player.f_hit_y = mlx->player.hit2_y;
	if (x / cos((PI / 2) - (angle - (PI / 2)))
		<= (1 - y) / cos(angle - (PI / 2)))
		mlx->player.dir = 's';
	else
		 mlx->player.dir = 'w';
	hypo = mlx->ray.hypo[1];
	free(mlx->ray.hypo);
	return (hypo);
}
