#include "../../cub3D.h"

int	ft_is_num(char c)
{
	if (c > '9' || c < '0')
		return (-1);
	return (0);
}

void	ft_defhex(char tab[16])
{
	int	i;
	int	j;

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
	char	tab_hex[16];
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
	int		i;
	char	tab_hex[16];

	i = 0;
	ft_defhex(tab_hex);
	while (tab_hex[i] != c && i < 16)
		i++;
	return (i);
}

long	ft_hexa_to_int(char *str)
{
	int		i;
	long	res;
	char	tab_hex[16];

	i = 0;
	res = 0;
	ft_defhex(tab_hex);
	while (str[i])
	{
		res = res + (ft_get_index(str[i]) * (pow(16,
						ft_strlen(str) - (i + 1))));
		i++;
	}
	return (res);
}
