#include "get_next_line.h"

static void	ft_free(void *var)
{
	free(var);
	var = NULL;
}

static char	*ft_split_line(char **str)
{
	int		pos;
	char	*line;
	char	*temp;

	pos = 0;
	while ((*str)[pos] != '\0')
	{
		if ((*str)[pos] == '\n')
		{
			pos++;
			break ;
		}
		pos++;
	}
	if (pos == 0 || !*str)
		return (NULL);
	temp = *str;
	line = ft_substr(temp, 0, pos);
	*str = ft_strdup(&(*str)[pos]);
	ft_free(temp);
	return (line);
}

static ssize_t	ft_get_line(char **str, char **buffer, char **line, int fd)
{
	ssize_t	size;
	char	*temp;

	size = 1;
	while (!ft_strchr(*str, '\n') && size)
	{
		size = read(fd, *buffer, BUFFER_SIZE);
		(*buffer)[size] = '\0';
		temp = *str;
		*str = ft_strjoin(temp, *buffer);
		free(temp);
	}
	*line = ft_split_line(str);
	if (size == 0 && !(*str)[0])
	{
		free(*str);
		*str = NULL;
		return (0);
	}
	if (!*line)
		ft_free(*line);
	return (size);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*buffer;
	char		*line;
	ssize_t		size;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	if (read(fd, buffer, 0) < 0)
	{
		ft_free(buffer);
		return (NULL);
	}
	if (!str)
		str = ft_strdup("");
	size = ft_get_line(&str, &buffer, &line, fd);
	ft_free(buffer);
	if (size <= 0 && !line)
		return (NULL);
	return (line);
}