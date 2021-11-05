/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nw_y.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaouedj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 13:26:21 by mlaouedj          #+#    #+#             */
/*   Updated: 2021/11/05 13:26:22 by mlaouedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../cub3D.h"

double	*ft_nw_y(t_mlx *mlx, double x, double y, double angle)
{
	int		i;
	double	*hypo;

	i = 1;
	hypo = malloc(sizeof(double) * 2);
	if (hypo == NULL)
		return (NULL);
	hypo[0] = y / cos((PI / 2) - (angle - PI));
	mlx->player.hit1_x = mlx->player.x - sqrt(hypo[0] * hypo[0] - (y * y));
	mlx->player.hit1_y = (int)mlx->player.y;
	while (mlx->player.hit1_y >= 0 && mlx->player.hit1_x >= 0
		&& ft_check_hit(mlx, 'n', mlx->player.hit1_x,
			mlx->player.hit1_y) != '1')
	{
		hypo[0] = (y + i) / cos((PI / 2) - (angle - PI));
		mlx->player.hit1_x = mlx->player.x - sqrt(
				hypo[0] * hypo[0] - ((y + i) * (y + i)));
		mlx->player.hit1_y = (int)mlx->player.y - i;
		i++;
	}
	hypo[1] = ft_nw_y_1(mlx, x, y, angle);
	return (hypo);
}

double	ft_nw_y_1(t_mlx *mlx, double x, double y, double angle)
{
	int		i;
	double	hypo;

	(void)y;
	i = 1;
	hypo = x / cos(angle - PI);
	mlx->player.hit2_x = (int)mlx->player.x;
	mlx->player.hit2_y = mlx->player.y - sqrt(hypo * hypo - (x * x));
	while (mlx->player.hit2_y >= 0 && mlx->player.hit2_x >= 0
		&& ft_check_hit(mlx, 'w', mlx->player.hit2_x,
			mlx->player.hit2_y) != '1')
	{
		hypo = (x + i) / cos(angle - PI);
		mlx->player.hit2_x = (int)mlx->player.x - i;
		mlx->player.hit2_y = mlx->player.y - sqrt(
				hypo * hypo - ((x + i) * (x + i)));
		i++;
	}
	return (hypo);
}
