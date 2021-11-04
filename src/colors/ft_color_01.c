#include "../../cub3D.h"

int	ft_convert_rgb_1(t_color *color)
{
	char	*res;
	char	*str1;
	char	*str2;
	char	*str3;

	res = malloc(sizeof(char) * 7);
	if ((ft_atoi(color->col1) > 255 || ft_atoi(color->col1) < 0)
		|| (ft_atoi(color->col2) > 255 || ft_atoi(color->col2) < 0)
		|| (ft_atoi(color->col3) > 255 || ft_atoi(color->col3) < 0))
		return (-1);
	str1 = ft_int_to_hex(ft_atoi(color->col1));
	str2 = ft_int_to_hex(ft_atoi(color->col2));
	str3 = ft_int_to_hex(ft_atoi(color->col3));
	res = ft_convert_rgb_2(res, str1, str2, str3);
	color->color = ft_hexa_to_int(res);
	free(res);
	return (0);
}

char	*ft_convert_rgb_2(char *res, char *s1, char *s2, char *s3)
{
	res[0] = s1[0];
	res[1] = s1[1];
	res[2] = s2[0];
	res[3] = s2[1];
	res[4] = s3[0];
	res[5] = s3[1];
	res[6] = '\0';
	free(s1);
	free(s2);
	free(s3);
	return (res);
}

int	ft_check_color_str(char *str)
{
	int	i;
	int	res;
	int	res1;

	i = ft_space(str);
	res = 0;
	res1 = 0;
	if ((str[i] != 'F' && str[i] != 'C') || ft_strlen(&str[i]) < 5)
		return (-1);
	i++;
	while (str[i])
	{
		if (str[i] != ',' && str[i] != ' ' && ft_is_num(str[i]) < 0)
			return (-1);
		if (str[i] == ',')
			res++;
		else if (ft_is_num(str[i]) == 0)
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
	int		i;
	int		j;
	char	*res;

	i = ft_space(str);
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
	str = ft_strndup_1(res, ft_strlen(res));
	free(res);
	return (str);
}
