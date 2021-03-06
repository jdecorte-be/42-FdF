/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: decortejohn <decortejohn@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 12:17:01 by decortejohn       #+#    #+#             */
/*   Updated: 2022/02/16 14:53:32 by decortejohn      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

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

int	getwidth(t_fdf *tab)
{
	int		fd;
	char	**s_str;
	int		i;
	char	*gnl;

	fd = open(tab->ag[1], O_RDONLY, 0777);
	if (fd == -1)
		exit(-1);
	gnl = get_next_line(fd);
	s_str = ft_split(gnl, ' ');
	i = 0;
	if (s_str == NULL)
		exit(-1);
	while (s_str[i])
		i++;
	ft_free_tab(s_str);
	free(gnl);
	close(fd);
	return (i);
}

int	**mallocfile(t_fdf *tab)
{
	int	**res;
	int	i;

	tab->width = getwidth(tab);
	tab->height = getheight(tab);
	res = malloc(sizeof(int *) * tab->height);
	if (!res)
		exit(-1);
	i = 0;
	while (i < tab->height)
	{
		res[i] = malloc(sizeof(int) * tab->width);
		if (!res[i])
			exit(-1);
		i++;
	}
	return (res);
}

void	readfile(t_fdf *tab)
{
	char	*str;
	char	**s_str;
	int		fd;
	int		j;
	int		i;

	tab->map = mallocfile(tab);
	fd = open(tab->ag[1], O_RDONLY, 0777);
	str = get_next_line(fd);
	j = 0;
	while (str)
	{
		s_str = ft_split(str, ' ');
		i = 0;
		while (i < tab->width)
		{
			tab->map[j][i] = ft_atoi(s_str[i]);
			i++;
		}
		ft_free_tab(s_str);
		free(str);
		str = get_next_line(fd);
		j++;
	}
	close(fd);
}
