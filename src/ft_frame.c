/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_frame.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaouedj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 13:23:19 by mlaouedj          #+#    #+#             */
/*   Updated: 2021/11/05 13:23:21 by mlaouedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	ft_next_frame(int keycode, t_mlx *mlx)
{
	if (mlx->frame % 2 != 0)
	{
		mlx->buff02.img = mlx_new_image(mlx->mlx, S_WIDTH, S_HEIGHT);
		mlx->buff02.addr = mlx_get_data_addr(mlx->buff02.img, &mlx->buff02.bpp,
				&mlx->buff02.l_len, &mlx->buff02.endian);
		ft_keycode(keycode, mlx);
		ft_vector_1(mlx, &mlx->buff02);
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->buff02.img, 0, 0);
		mlx_destroy_image(mlx->mlx, mlx->buff01.img);
	}
	else
	{
		mlx->buff01.img = mlx_new_image(mlx->mlx, S_WIDTH, S_HEIGHT);
		mlx->buff01.addr = mlx_get_data_addr(mlx->buff01.img, &mlx->buff01.bpp,
				&mlx->buff01.l_len, &mlx->buff01.endian);
		ft_keycode(keycode, mlx);
		ft_vector_1(mlx, &mlx->buff01);
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->buff01.img, 0, 0);
		mlx_destroy_image(mlx->mlx, mlx->buff02.img);
	}
	mlx->frame++;
	return (0);
}
