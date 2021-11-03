#include "../cub3D.h"

char	*ft_strndup_1(char *str, int n)
{
	int		i;
	char	*dest;

	i = 0;
	dest = malloc(sizeof(char) * (n + 1));
	if (dest == NULL)
		return (NULL);
	while (str[i] && i < n)
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int	ft_atoi(const char *str)
{
	int		i;
	long	sign;
	long	nb;

	i = 0;
	sign = 1;
	nb = 0;
	while (str[i] == '\t' || str[i] == '\v' || str[i] == '\n'
		|| str[i] == '\r' || str[i] == '\f' || str[i] == ' ')
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + (str[i] - 48);
		i++;
	}
	nb = nb * sign;
	return (nb);
}

int	ft_check_file(char *file)
{
	int	len;

	if (!file)
		return (-1);
	len = ft_strlen(file);
	if (len < 5)
		return (-1);
	if (file[len - 1] != 'b' || file[len - 2] != 'u'
		|| file[len - 3] != 'c' || file[len - 4] != '.')
		return (-1);
	return (0);
}

int	ft_args(int ac, char **av)
{
	if (ac != 2)
		return (-1);
	if (ft_check_file(av[1]) < 0)
		return (-2);
	if (open(av[1], O_RDONLY) < 0)
		return (-3);
	return (0);
}
