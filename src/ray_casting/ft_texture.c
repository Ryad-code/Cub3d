/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_texture.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaouedj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 13:25:37 by mlaouedj          #+#    #+#             */
/*   Updated: 2021/11/05 13:25:39 by mlaouedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

int	ft_init_texture(t_mlx *mlx)
{
	mlx->text_e.img = mlx_xpm_file_to_image(mlx->mlx, mlx->arg.ea,
			&mlx->text_e.img_width, &mlx->text_e.img_height);
	mlx->text_s.img = mlx_xpm_file_to_image(mlx->mlx, mlx->arg.so,
			&mlx->text_s.img_width, &mlx->text_s.img_height);
	mlx->text_w.img = mlx_xpm_file_to_image(mlx->mlx, mlx->arg.we,
			&mlx->text_w.img_width, &mlx->text_w.img_height);
	mlx->text_n.img = mlx_xpm_file_to_image(mlx->mlx, mlx->arg.no,
			&mlx->text_n.img_width, &mlx->text_n.img_height);
	if (mlx->text_e.img && mlx->text_s.img && mlx->text_w.img
		&& mlx->text_n.img)
		ft_init_texture_2(mlx);
	else
		return (-1);
	return (0);
}

void	ft_init_texture_2(t_mlx *mlx)
{
	mlx->text_e.addr = mlx_get_data_addr
		(mlx->text_e.img, &mlx->text_e.bit_per_pixel,
			 &mlx->text_e.line_lenght, &mlx->text_e.endian);
	mlx->text_s.addr = mlx_get_data_addr
		(mlx->text_s.img, &mlx->text_s.bit_per_pixel, &mlx->text_s.line_lenght,
			 &mlx->text_s.endian);
	mlx->text_w.addr = mlx_get_data_addr
		(mlx->text_w.img, &mlx->text_w.bit_per_pixel,
			&mlx->text_w.line_lenght, &mlx->text_w.endian);
	mlx->text_n.addr = mlx_get_data_addr
		(mlx->text_n.img, &mlx->text_n.bit_per_pixel, &mlx->text_n.line_lenght,
			 &mlx->text_n.endian);
}

double	ft_hit(t_mlx *mlx)
{
	double	hit;

	if (mlx->player.dir == 'e')
		hit = mlx->player.f_hit_y - (int)mlx->player.f_hit_y;
	else if (mlx->player.dir == 'n')
		hit = mlx->player.f_hit_x - (int)mlx->player.f_hit_x;
	else if (mlx->player.dir == 'w')
		hit = (int)mlx->player.f_hit_y + 1 - mlx->player.f_hit_y;
	else if (mlx->player.dir == 's')
		hit = (int)mlx->player.f_hit_x + 1 - mlx->player.f_hit_x;
	return (hit);
}

unsigned int	ft_get_pixel(t_mlx *mlx, t_text *text, int w_pix, int w_size)
{
	int	x;
	int	y;
	int	diff;

	x = (int)nearbyint(ft_hit(mlx) * (double)text->img_width);
	y = (int)nearbyint(((double)w_pix / (double)w_size) * text->img_height);
	diff = (mlx->ray.wall_height - S_HEIGHT);
	if (mlx->ray.wall_height > S_HEIGHT)
		y = (int)nearbyint(((double)(w_pix + diff / 2)
					/ (double)mlx->ray.wall_height) * text->img_height);
	return (*(unsigned int *)(text->addr + (y * text->line_lenght
			+ x * (text->bit_per_pixel / 8))));
}

t_text	*ft_choose_text(t_mlx *mlx)
{
	if (mlx->player.dir == 'e')
		return (&mlx->text_e);
	else if (mlx->player.dir == 's')
		return (&mlx->text_s);
	else if (mlx->player.dir == 'w')
		return (&mlx->text_w);
	else if (mlx->player.dir == 'n')
		return (&mlx->text_n);
	return (NULL);
}
