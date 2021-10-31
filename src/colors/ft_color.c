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

char	*ft_int_to_hex(unsigned long nb)
{
	char tab_hex[16];
	char	*res;
	char	tmp;

	res = malloc(sizeof(char) * 3);
	if (res == NULL)
		return (NULL);
	ft_defhex(tab_hex);
	if (nb >= 16)
	{
		res[0] = tab_hex[nb % 16];
		nb = nb / 16;
		res[1] = tab_hex[nb];
	}
	else
	{
		res[0] = tab_hex[nb];
		res[1] = '0';
	}
	res[2] = '\0';
	tmp = res[0];
	res[0] = res[1];
	res[1] = tmp;
	return (res);
}

int	ft_get_index(char c)
{
	int	i;
	char	tab_hex[16];

	i = 0;
	ft_defhex(tab_hex);
	while (tab_hex[i] != c && i < 16)
		i++;
	return (i);

}

long	ft_hexa_to_int(char *str)
{
	int	i;
	long	res;
	char tab_hex[16];

	i = 0;
	res = 0;
	ft_defhex(tab_hex);
	while (str[i])
	{
		res = res + (ft_get_index(str[i]) * (pow(16, ft_strlen(str) - (i + 1))));
		i++;
	}
	return (res);
}

int	ft_convert_rgb(t_color *color)
{
	char	*res;
	char	*str1;
	char	*str2;
	char	*str3;

	res = malloc(sizeof(char) * 7);
	if ((ft_atoi(color->col1) > 255 || ft_atoi(color->col1) < 0) || (ft_atoi(color->col2) > 255 || ft_atoi(color->col2) < 0) || (ft_atoi(color->col3) > 255 || ft_atoi(color->col3) < 0))
		return (-1);
	str1 = ft_int_to_hex(ft_atoi(color->col1));
	str2 = ft_int_to_hex(ft_atoi(color->col2));
	str3 = ft_int_to_hex(ft_atoi(color->col3));
	res[0] = str1[0];
	res[1] = str1[1];
	res[2] = str2[0];
	res[3] = str2[1];
	res[4] = str3[0];
	res[5] = str3[1];
	res[6] = '\0';
	free(str1);
	free(str2);
	free(str3);
	color->color = ft_hexa_to_int(res);
	free(res);
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
	if (color->col1 == NULL || ft_strlen(color->col1) < 1)
		return (-1);
	i++;
	while (color->str[i] && ft_is_num(color->str[i]) == 0)
	{
		i++;
		j++;
	}
	color->col2 = ft_strndup_1(&color->str[i - j], j);
	if (color->col2 == NULL || ft_strlen(color->col2) < 1)
		return (-1);
	i++;
	j = 0;
	while (color->str[i] && ft_is_num(color->str[i]) == 0)
	{
		i++;
		j++;
	}
	color->col3 = ft_strndup_1(&color->str[i - j], j);
	if (color->col3 == NULL || ft_strlen(color->col3) < 1)
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
	if (ft_check_colors(&mlx->arg.c) < 0)
		return (-1);
	if (ft_check_colors(&mlx->arg.f) < 0)
		return (-1);
	if (ft_convert_rgb(&mlx->arg.c) < 0)
		return (-1);
	if (ft_convert_rgb(&mlx->arg.f) < 0)
		return (-1);

	return (0);
}

