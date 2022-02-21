/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: decortejohn <decortejohn@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 17:30:06 by decortejohn       #+#    #+#             */
/*   Updated: 2022/02/11 16:41:16 by decortejohn      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	key_p2(int key, t_fdf *tab)
{
	if (key == 35 && tab->projection == false)
		tab->projection = true;
	else if (key == 35)
		tab->projection = false;
	if (key == 15)
		tab->h_view += 0.01;
	if (key == 3)
		tab->h_view -= 0.01;
	if (key == 123)
		tab->rotation -= 0.1;
	if (key == 124)
		tab->rotation += 0.1;
}

void	ft_free_tab(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

int	find_max(int num1, int num2)
{
	if (num1 > num2)
		return (num1);
	else
		return (num2);
}

int	find_mod(int num)
{
	if (0 > num)
		return (-num);
	return (num);
}
