/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_text_parsing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaouedj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 13:24:59 by mlaouedj          #+#    #+#             */
/*   Updated: 2021/11/05 13:25:01 by mlaouedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

int	ft_space(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (-1);
	while (str[i] == ' ')
	{
		i++;
	}
	return (i);
}

int	ft_check_text(char *str, char *text)
{
	int	i;
	int	len;

	i = ft_space(str);
	len = ft_strlen(str);
	if (len - i < 6)
		return (-1);
	if (str[i] != text[0] || str[i + 1] != text[1])
		return (-1);
	i = i + 2;
	i = i + ft_space(&str[i]);
	if (str[i] != '.' || str[i + 1] != '/')
		return (-1);
	return (0);
}

char	*ft_text(char *str)
{
	int		i;
	char	*tmp;

	i = 0;
	while (str[i] && str[i] != '.')
		i++;
	tmp = ft_strdup(&str[i]);
	free(str);
	str = ft_strdup(tmp);
	free(tmp);
	return (str);
}

int	ft_parse_text(t_mlx *mlx)
{
	if (ft_check_text(mlx->arg.no, "NO") < 0)
		return (-1);
	mlx->arg.no = ft_text(mlx->arg.no);
	if (ft_check_text(mlx->arg.so, "SO") < 0)
		return (-1);
	mlx->arg.so = ft_text(mlx->arg.so);
	if (ft_check_text(mlx->arg.we, "WE") < 0)
		return (-1);
	mlx->arg.we = ft_text(mlx->arg.we);
	if (ft_check_text(mlx->arg.ea, "EA") < 0)
		return (-1);
	mlx->arg.ea = ft_text(mlx->arg.ea);
	return (0);
}
