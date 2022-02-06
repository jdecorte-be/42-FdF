/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: decortejohn <decortejohn@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 12:17:01 by decortejohn       #+#    #+#             */
/*   Updated: 2022/02/06 12:40:37 by decortejohn      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

// get height
int	getheight(t_fdf *tab)
{
	int		fd;
	char	*str;
	int		i;

	fd = open(tab->ag[1], O_RDONLY);
	i = 0;
	str = get_next_line(fd);
	while (str)
	{
		i++;
		free(str);
		str = get_next_line(fd);
	}
	close(fd);
	return (i);
}

// get weight
int	getweight(t_fdf *tab)
{
	int		fd;
	char	**s_str;
	int		i;

	fd = open(tab->ag[1], O_RDONLY);
	s_str = ft_split(get_next_line(fd), ' ');
	i = 0;
	if (s_str == NULL)
		exit(-1);
	while (s_str[i])
		i++;
	free(s_str);
	close(fd);
	return (i);
}

// malloc file
int	**mallocfile(t_fdf *tab)
{
	int	**res;
	int	i;

	tab->width = getweight(tab);
	tab->height = getheight(tab);
	res = malloc(sizeof(int *) * tab->height);
	i = 0;
	while (i < tab->height)
	{
		res[i] = malloc(sizeof(int) * tab->width);
		i++;
	}
	return (res);
}

// read file and return int**
void	readfile(t_fdf *tab)
{
	int		**file;
	int		fd;
	char	*str;
	int		j;
	int		i;
	char	**s_str;

	file = mallocfile(tab);
	fd = open(tab->ag[1], O_RDONLY);
	str = get_next_line(fd);
	j = 0;
	while (j < tab->height)
	{
		s_str = ft_split(str, ' ');
		i = 0;
		while (i < tab->width)
		{
			file[j][i] = ft_atoi(s_str[i]);
			i++;
		}
		str = get_next_line(fd);
		free(s_str);
		j++;
	}
	tab->map = file;
	close(fd);
}
