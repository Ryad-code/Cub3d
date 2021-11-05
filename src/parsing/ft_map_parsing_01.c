/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_parsing_01.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaouedj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 13:24:44 by mlaouedj          #+#    #+#             */
/*   Updated: 2021/11/05 13:24:46 by mlaouedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

char	*ft_fill_line(t_mlx *mlx, char *str)
{
	int		i;
	char	*res;

	i = 0;
	res = malloc(sizeof(char) * (mlx->map.g_width + 1));
	if (res == NULL)
		return (NULL);
	while (str[i])
	{
		res[i] = str[i];
		i++;
	}
	while (mlx->map.g_width - i > 0)
	{
		res[i] = '1';
		i++;
	}
	free(str);
	res[i] = '\0';
	return (res);
}

void	ft_replace_spaces(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == ' ')
			str[i] = '1';
		i++;
	}
}

void	ft_replace_dir(t_mlx *mlx)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (mlx->map.grid[j])
	{
		while (i < ft_strlen(mlx->map.grid[j]))
		{
			if (mlx->map.grid[j][i] == 'N' || mlx->map.grid[j][i] == 'E' ||
				mlx->map.grid[j][i] == 'S' || mlx->map.grid[j][i] == 'W')
				mlx->map.grid[j][i] = '0';
			i++;
		}
		i = 0;
		j++;
	}
}

void	ft_fill_grid(t_mlx *mlx)
{
	int	i;

	i = 0;
	while (i < mlx->map.g_height)
	{
		mlx->map.grid[i] = ft_fill_line(mlx, mlx->map.grid[i]);
		ft_replace_spaces(mlx->map.grid[i]);
		i++;
	}
}
