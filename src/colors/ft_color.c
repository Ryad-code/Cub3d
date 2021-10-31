#include "../../cub3D.h"

int	ft_is_num(char c)
{
	if (c > '9' || c < '0')
		return (-1);
	return (0);
}

void	ft_defhex(char tab[16])
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < 10)
	{
		tab[i] = i + 48;
		i++;
	}
	while (i < 16)
	{
		tab[i] = 'a' + j;
		i++;
		j++;
	}
}

int	*ft_puthex(unsigned long nb)
{
//	char tab_hex[16];
	int i;

	i = 0;
//	ft_defhex(tab_hex);
	if (nb >= 16)
	{
		ft_puthex(nb / 16);
		ft_puthex(nb % 16);
	}
	else
		i++;
//		ft_putchar(tab_hex[nb]);
	return (0);
}

int	ft_check_color_str(char *str)
{
	int 	i;
	int	res;
	int	res1;

	i = 0;
	res = 0;
	res1 = 0;
	while (str[i])
	{
		if (str[i] != ',' && ft_is_num(str[i]) < 0)
			return (-1);
		if (str[i] == ',')
			res++;
		else if (ft_is_num(str[i] == 0))
			res1++;
		i++;
	}
	if (res != 2)
		return (-2);
	if (res1 < 3 || res1 > 9)
		return (-3);
	return (0);
}

char	*ft_get_colors(char *str)
{
	int	i;
	int	j;
	char	*res;

	i = 0;
	j = 0;
	res = malloc(sizeof(char) * 12);
	if (res == NULL)
		return (NULL);
	while (str[i])
	{
		if (ft_is_num(str[i]) == 0 || str[i] == ',')
		{
			res[j] = str[i];
			j++;
		}
		i++;
	}
	res[j] = '\0';
	free(str);
	str = ft_strndup(res, ft_strlen(res));
	free(res);
	return (str);
}

int	ft_check_colors(t_color *color)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (color->str[i] && ft_is_num(color->str[i]) == 0)
		i++;
	color->col1 = ft_strndup_1(color->str, i);
	if (color->col1 == NULL)
		return (-1);
	i++;
	while (color->str[i] && ft_is_num(color->str[i]) == 0)
	{
		i++;
		j++;
	}
	color->col2 = ft_strndup_1(&color->str[i - j], j);
	if (color->col2 == NULL)
		return (-1);
	i++;
	j = 0;
	while (color->str[i] && ft_is_num(color->str[i]) == 0)
	{
		i++;
		j++;
	}
	color->col3 = ft_strndup_1(&color->str[i - j], j);
	if (color->col3 == NULL)
		return (-1);
	return (0);
}


int	ft_parse_colors(t_mlx *mlx)
{
	if (ft_get_colors(mlx->arg.c.str) == NULL)
		return (-1);
	if (ft_get_colors(mlx->arg.c.str) == NULL)
		return (-1);
	mlx->arg.c.str = ft_get_colors(mlx->arg.c.str);
	mlx->arg.f.str = ft_get_colors(mlx->arg.f.str);
	if (ft_check_color_str(mlx->arg.c.str) < 0)
		return (-1);
	if (ft_check_color_str(mlx->arg.f.str) < 0)
		return (-1);
	if (ft_check_colors(&mlx->arg.c < 0))
		return (-1);
	if (ft_check_colors(&mlx->arg.f < 0))
		return (-1);
	return (0);
}

