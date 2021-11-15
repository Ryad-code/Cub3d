#include "get_next_line.h"

char	*ft_strdup(char *s1)
{
	int		i;
	char	*res;

	i = 0;
	res = malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!(res))
		return (NULL);
	while (s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*dst;
	int		i;

	if (!s1 || !s2)
		return (NULL);
	dst = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!(dst))
		return (NULL);
	i = 0;
	while (i < ft_strlen(s1))
	{
		dst[i] = s1[i];
		i++;
	}
	while (i < (ft_strlen(s1) + ft_strlen(s2)))
	{
		dst[i] = s2[i - ft_strlen(s1)];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
		{
			return ((char *)(s + i));
		}
		i++;
	}
	if (c == '\0')
		return ((char *)(s + i));
	return (NULL);
}

char	*ft_substr(char *s, int start, int len)
{
	int		i;
	int		j;
	char	*res;

	if (s == NULL || start >= ft_strlen(s) || len == 0)
		return (ft_strdup(""));
	i = 0;
	j = 0;
	res = malloc(sizeof(char) * (len + 1));
	if (!(res))
		return (NULL);
	while (i < start)
		i++;
	while (s[i + j] && j < len)
	{
		res[j] = s[i + j];
		j++;
	}
	res[j] = '\0';
	return (res);
}
