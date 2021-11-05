/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_03.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaouedj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 13:24:28 by mlaouedj          #+#    #+#             */
/*   Updated: 2021/11/05 13:24:30 by mlaouedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

int	ft_get_opt(t_mlx *mlx, char *file)
{
	int		i;
	int		res;
	int		fd;
	char	*line;

	i = 0;
	res = 0;
	fd = open(file, O_RDONLY);
	while (get_next_line(fd, &line))
	{
		res = ft_get_text(mlx, line, &res);
		res = ft_get_color(mlx, line, &res);
		if (res < 6)
			i++;
		free(line);
	}
	close(fd);
	free(line);
	if (res != 6)
		return (-1);
	return (i);
}

int	ft_get_text(t_mlx *mlx, char *line, int	*res)
{
	int	i;

	i = *res;
	if (ft_is_opt("NO", line) == 0)
	{
		mlx->arg.no = ft_strdup(line);
		i++;
	}
	else if (ft_is_opt("SO", line) == 0)
	{
		mlx->arg.so = ft_strdup(line);
		i++;
	}
	else if (ft_is_opt("WE", line) == 0)
	{
		mlx->arg.we = ft_strdup(line);
		i++;
	}
	else if (ft_is_opt("EA", line) == 0)
	{
		mlx->arg.ea = ft_strdup(line);
		i++;
	}
	return (i);
}

int	ft_get_color(t_mlx *mlx, char *line, int *res)
{
	int	i;

	i = *res;
	if (ft_is_opt("F ", line) == 0)
	{
		mlx->arg.f.str = ft_strdup(line);
		i++;
	}
	if (ft_is_opt("C ", line) == 0)
	{
		mlx->arg.c.str = ft_strdup(line);
		i++;
	}
	return (i);
}

void	ft_get_g_dim(t_mlx *mlx, char *file)
{
	int		tab[4];
	char	*line;

	tab[0] = 0;
	tab[1] = open(file, O_RDONLY);
	tab[2] = 0;
	tab[3] = 0;
	while (get_next_line(tab[1], &line))
	{
		if (ft_is_line(line) == 0 && tab[0] == 0)
		{
			if (ft_strlen(line) > tab[3])
				tab[3] = ft_strlen(line);
			tab[2]++;
		}
		if (ft_is_line(line) != 0 && tab[2] > 0)
			tab[0] = 1;
		free(line);
	}
	free(line);
	mlx->map.g_width = tab[3];
	mlx->map.g_height = tab[2];
	close(tab[1]);
}
