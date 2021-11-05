/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color_02.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaouedj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 13:28:18 by mlaouedj          #+#    #+#             */
/*   Updated: 2021/11/05 13:28:20 by mlaouedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

int	ft_check_colors_1(t_color *color)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (color->str[i] && ft_is_num(color->str[i]) == 0)
		i++;
	color->col1 = ft_strndup_1(color->str, i);
	if (color->col1 == NULL || ft_strlen(color->col1) < 1
		|| atoi(color->col1) > 255)
		return (-1);
	i++;
	while (color->str[i] && ft_is_num(color->str[i]) == 0)
	{
		i++;
		j++;
	}
	if (ft_check_colors_2(color, i, j) < 0)
		return (-1);
	return (0);
}

int	ft_check_colors_2(t_color *color, int i, int j)
{
	color->col2 = ft_strndup_1(&color->str[i - j], j);
	if (color->col2 == NULL || ft_strlen(color->col2) < 1
		|| atoi(color->col2) > 255)
		return (-1);
	i++;
	j = 0;
	while (color->str[i] && ft_is_num(color->str[i]) == 0)
	{
		i++;
		j++;
	}
	color->col3 = ft_strndup_1(&color->str[i - j], j);
	if (color->col3 == NULL || ft_strlen(color->col3) < 1
		|| atoi(color->col3) > 255)
		return (-1);
	return (0);
}

int	ft_parse_colors(t_mlx *mlx)
{
	if (ft_check_color_str(mlx->arg.c.str) < 0)
		return (-1);
	if (ft_check_color_str(mlx->arg.f.str) < 0)
		return (-1);
	mlx->arg.c.str = ft_get_colors(mlx->arg.c.str);
	mlx->arg.f.str = ft_get_colors(mlx->arg.f.str);
	if (mlx->arg.c.str == NULL || mlx->arg.f.str == NULL)
		return (-1);
	if (ft_check_colors_1(&mlx->arg.c) < 0)
		return (-1);
	if (ft_check_colors_1(&mlx->arg.f) < 0)
		return (-1);
	if (ft_convert_rgb_1(&mlx->arg.c) < 0)
		return (-1);
	if (ft_convert_rgb_1(&mlx->arg.f) < 0)
		return (-1);
	return (0);
}
