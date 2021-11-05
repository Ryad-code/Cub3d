/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaouedj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 13:23:57 by mlaouedj          #+#    #+#             */
/*   Updated: 2021/11/05 13:24:00 by mlaouedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

int	ft_checking(t_mlx *mlx, int ac, char **av)
{
	if (ft_args(ac, av) < 0)
	{
		printf("Error\n");
		return (-1);
	}
	if (ft_get_infos(mlx, av[1]) < 0 || ft_parse_text(mlx) < 0
		|| ft_parse_map(mlx) < 0 || ft_parse_colors(mlx) < 0)
	{
		ft_free_data(mlx);
		printf("Error\n");
		return (-1);
	}
	return (0);
}

int	ft_exit(t_mlx *mlx)
{
	ft_next_frame(65307, mlx);
	return (0);
}
