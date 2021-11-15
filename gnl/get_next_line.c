#include "get_next_line.h"

int	get_next_line(int fd, char **line)
{
	char		buffer[BUFFER_SIZE + 1];
	static char	*stack;
	char		*tmp;
	int			rdcpt;

	rdcpt = 0;
	if (fd < 0 || BUFFER_SIZE == 0 || !line)
		return (-1);
	if (!ft_strchr(stack, '\n'))
	{
		rdcpt = read(fd, buffer, BUFFER_SIZE);
		while (rdcpt > 0)
		{
			if (!(handle_stack(&stack, &tmp, buffer, rdcpt)))
				return (-1);
			if (ft_strchr(stack, '\n'))
				break ;
			rdcpt = read(fd, buffer, BUFFER_SIZE);
		}
	}
	return (manage_output(&stack, line, rdcpt));
}

int	handle_stack(char **stack, char **tmp, char *buffer, int rdcpt)
{
	buffer[rdcpt] = '\0';
	if (!(*stack))
	{
		*stack = ft_strdup(buffer);
		if (!(*stack))
			return (-1);
	}
	else
	{
		*tmp = ft_strjoin(*stack, buffer);
		if (!(*tmp))
		{
			free(*stack);
			return (-1);
		}
		free(*stack);
		*stack = ft_strdup(*tmp);
		if (!(*stack))
		{
			free(*tmp);
			return (-1);
		}
		free(*tmp);
	}
	return (1);
}

int	manage_output(char **stack, char **line, int rdcpt)
{
	if (rdcpt < 0)
		return (-1);
	if (rdcpt == 0 && *stack == NULL)
	{
		*line = ft_strdup("");
		if (!(*line))
			return (-1);
		return (0);
	}
	else
		return (extract_line(stack, line));
}

int	handle_line(char **stack, char **line, char **tmp, int end)
{
	*line = ft_substr(*stack, 0, end);
	if (!(*line))
	{
		free(*stack);
		return (-1);
	}
	*tmp = ft_strdup((*stack) + end + 1);
	if (!(*tmp))
	{
		free(*stack);
		return (-1);
	}
	free(*stack);
	*stack = *tmp;
	return (1);
}

int	extract_line(char **stack, char **line)
{
	size_t	end;
	char	*tmp;

	end = 0;
	while ((*stack)[end] != '\n' && (*stack)[end] != '\0')
		end++;
	if ((*stack)[end] == '\n')
	{
		return (handle_line(stack, line, &tmp, end));
	}
	else
	{
		*line = ft_strdup(*stack);
		if (!(*line))
		{
			free(*stack);
			return (-1);
		}
		free(*stack);
		*stack = NULL;
		return (0);
	}
}
