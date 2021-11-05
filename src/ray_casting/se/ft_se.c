/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_se.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaouedj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 13:26:32 by mlaouedj          #+#    #+#             */
/*   Updated: 2021/11/05 13:26:38 by mlaouedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../cub3D.h"

double	ft_se(t_mlx *mlx, double x, double y, double angle)
{
	if ((1 - x) / cos(angle) <= (1 - y) / cos(PI / 2 - angle))
	{
		mlx->ray.hypo = ft_se_x(mlx, x, y, angle);
		if (mlx->ray.hypo == NULL)
			return (-1);
	}
	else if ((1 - y) / cos(PI / 2 - angle) <= (1 - x) / cos(angle))
	{
		mlx->ray.hypo = ft_se_y(mlx, x, y, angle);
		if (mlx->ray.hypo == NULL)
			return (-1);
	}
	return (ft_se_1(mlx, x, y, angle));
}

double	ft_se_1(t_mlx *mlx, double x, double y, double angle)
{
	double	hypo;

	if (mlx->ray.hypo[0] <= mlx->ray.hypo[1])
	{
		mlx->player.f_hit_x = mlx->player.hit1_x;
		mlx->player.f_hit_y = mlx->player.hit1_y;
		if ((1 - x) / cos(angle) <= (1 - y) / cos(PI / 2 - angle))
			mlx->player.dir = 'e';
		else
			mlx->player.dir = 's';
		hypo = mlx->ray.hypo[0];
		free(mlx->ray.hypo);
		return (hypo);
	}
	else
		return (ft_se_2(mlx, x, y, angle));
}

double	ft_se_2(t_mlx *mlx, double x, double y, double angle)
{
	double	hypo;

	mlx->player.f_hit_x = mlx->player.hit2_x;
	mlx->player.f_hit_y = mlx->player.hit2_y;
	if ((1 - x) / cos(angle) <= (1 - y) / cos(PI / 2 - angle))
		mlx->player.dir = 's';
	else
		mlx->player.dir = 'e';
	hypo = mlx->ray.hypo[1];
	free(mlx->ray.hypo);
	return (hypo);
}
