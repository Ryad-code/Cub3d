/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sw_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaouedj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 13:27:01 by mlaouedj          #+#    #+#             */
/*   Updated: 2021/11/05 13:27:02 by mlaouedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../cub3D.h"

double	*ft_sw_x(t_mlx *mlx, double x, double y, double angle)
{
	int		i;
	double	*hypo;

	i = 1;
	hypo = malloc(sizeof(double) * 2);
	if (hypo == NULL)
		return (NULL);
	hypo[0] = x / cos((PI / 2) - (angle - (PI / 2)));
	mlx->player.hit1_x = (int)mlx->player.x;
	mlx->player.hit1_y = mlx->player.y + sqrt(hypo[0] * hypo[0] - (x * x));
	while (mlx->player.hit1_y <= mlx->map.g_height && mlx->player.hit1_x >= 0
		&& ft_check_hit(mlx, 'w', mlx->player.hit1_x,
			mlx->player.hit1_y) != '1')
	{
		hypo[0] = (x + i) / cos((PI / 2) - (angle - (PI / 2)));
		mlx->player.hit1_x = (int)mlx->player.x - i;
		mlx->player.hit1_y = mlx->player.y + sqrt(
				hypo[0] * hypo[0] - ((x + i) * (x + i)));
		i++;
	}
	hypo[1] = ft_sw_x_1(mlx, x, y, angle);
	return (hypo);
}

double	ft_sw_x_1(t_mlx *mlx, double x, double y, double angle)
{
	int		i;
	double	hypo;

	i = 1;
	hypo = (1 - y) / cos(angle - (PI / 2));
	mlx->player.hit2_x = mlx->player.x - sqrt(
			hypo * hypo - ((1 - y) * (1 - y)));
	mlx->player.hit2_y = (int)mlx->player.y + 1;
	while (mlx->player.hit2_y <= mlx->map.g_height && mlx->player.hit2_x
		>= 0 && ft_check_hit(mlx, 's',
			mlx->player.hit2_x, mlx->player.hit2_y) != '1')
	{
		hypo = ((1 - y) + i) / cos(angle - (PI / 2));
		mlx->player.hit2_x = (int)mlx->player.x + x - sqrt(
				hypo * hypo - (((1 - y) + i) * ((1 - y) + i)));
		mlx->player.hit2_y = (int)mlx->player.y + 1 + i;
		i++;
	}
	return (hypo);
}
