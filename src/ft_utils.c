#include "../cub3D.h"

char	*ft_strndup(char *str, int n)
{
	int	i;
	char	*dest;

	i = 0;
	dest = NULL;
	if (!(dest = malloc(sizeof(char) * (n + 1))))
		return (dest);
	while (str[i])
	{
		dest[i] = str[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '0';
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int	ft_check_file(char *file)
{
	int len;

	if (!file)
		return (-1);
	len = ft_strlen(file);
	if (len < 5)
		return (-1);
	if (file[len - 1] != 'b' || file[len - 2] != 'u' || file[len - 3] != 'c' || file[len - 4] != '.')
		return (-1);
	return (0);
}

int	ft_args(int ac , char **av)
{
	if (ac != 2)
		return (-1);
	if (ft_check_file(av[1]) < 0)
		return (-2);
	if (open(av[1], O_RDONLY) < 0)
		return (-3);
	return (0);
}
