/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_parsing_02.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaouedj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 13:24:49 by mlaouedj          #+#    #+#             */
/*   Updated: 2021/11/05 13:24:52 by mlaouedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

int	ft_check_map_sides_1(t_mlx *mlx)
{
	int	i;

	i = 0;
	while (i < ft_strlen(mlx->map.grid[0]))
	{
		if (mlx->map.grid[0][i] != '1' && mlx->map.grid[0][i] != ' ')
			return (-1);
		i++;
	}
	i = 0;
	while (i < ft_strlen(mlx->map.grid[mlx->map.g_height - 1]))
	{
		if (mlx->map.grid[mlx->map.g_height - 1][i] != '1'
			&& mlx->map.grid[mlx->map.g_height - 1][i] != ' ')
			return (-2);
		i++;
	}
	if (ft_check_map_sides_2(mlx) < 0)
		return (-1);
	return (0);
}

int	ft_check_map_sides_2(t_mlx *mlx)
{
	int	i;

	i = 0;
	while (i < mlx->map.g_height)
	{
		if (mlx->map.grid[i][0] != '1' && mlx->map.grid[i][0] != ' ')
			return (-1);
		if (mlx->map.grid[i][ft_strlen(mlx->map.grid[i]) - 1] != '1' &&
				mlx->map.grid[i][ft_strlen(mlx->map.grid[i]) - 1] != ' ')
			return (-1);
		i++;
	}
	return (0);
}

int	ft_check_inside_grid_1(t_mlx *mlx)
{
	int	i;
	int	j;

	i = 1;
	j = 1;
	while (j < mlx->map.g_height - 1)
	{
		while (i < ft_strlen(mlx->map.grid[j]))
		{
			if (mlx->map.grid[j][i] == '0'
					&& ft_check_inside_grid_2(mlx, i, j) < 0)
				return (-1);
			i++;
		}
		i = 0;
		j++;
	}
	return (0);
}

int	ft_check_inside_grid_2(t_mlx *mlx, int i, int j)
{
	if (mlx->map.grid[j - 1][i] != '1' && mlx->map.grid[j - 1][i] != '0')
		return (-1);
	if (mlx->map.grid[j - 1][i - 1] != '1'
			&& mlx->map.grid[j - 1][i - 1] != '0')
		return (-2);
	if (mlx->map.grid[j - 1][i + 1] != '1' &&
			mlx->map.grid[j - 1][i + 1] != '0')
		return (-3);
	if (mlx->map.grid[j + 1][i] != '1' && mlx->map.grid[j + 1][i] != '0')
		return (-4);
	if (mlx->map.grid[j + 1][i + 1] != '1'
			&& mlx->map.grid[j + 1][i + 1] != '0')
		return (-5);
	if (mlx->map.grid[j + 1][i + 1] != '1'
			&& mlx->map.grid[j + 1][i + 1] != '0')
		return (-6);
	if (mlx->map.grid[j][i - 1] != '1' && mlx->map.grid[j][i - 1] != '0')
		return (-7);
	if (mlx->map.grid[j][i + 1] != '1' && mlx->map.grid[j][i + 1] != '0')
		return (-8);
	return (0);
}

int	ft_parse_map(t_mlx *mlx)
{
	int	out;
	int	in;

	ft_replace_dir(mlx);
	out = ft_check_map_sides_1(mlx);
	in = ft_check_inside_grid_1(mlx);
	if (in < 0 || out < 0)
		return (-1);
	ft_fill_grid(mlx);
	return (0);
}
