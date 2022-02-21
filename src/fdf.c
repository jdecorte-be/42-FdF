/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: decortejohn <decortejohn@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 16:54:51 by decortejohn       #+#    #+#             */
/*   Updated: 2022/02/09 13:57:54 by jdecorte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	fade(int h)
{
	if (h > 100)
		return (0xFFDF8D);
	if (h > 75)
		return (0xFFDE7A);
	if (h > 50)
		return (0xFFC568);
	if (h > 25)
		return (0xFD996B);
	if (h > 15)
		return (0xF7856C);
	if (h > 10)
		return (0xF06E6C);
	if (h > 5)
		return (0xD9576B);
	if (h > 0)
		return (0xA44369);
	if (h > -10)
		return (0x833F68);
	if (h > -20)
		return (0x833F68);
	if (h > -50)
		return (0x5E3C65);
	return (0x3F3A63);
}

void	projection(float *x, float *y, int *z, t_fdf *tab)
{
	int	x_tmp;
	int	y_tmp;

	*z = tab->map[(int)*y][(int)*x];
	*z *= tab->zoom;
	*z *= tab->h_view;
	*y *= tab->zoom;
	*x *= tab->zoom;
	y_tmp = *y;
	x_tmp = *x;
	*x = (*x - *y) * cos(0.8);
	*y = (*x + *y) * sin(0.8) - *z;
}

void	put_pxl(t_fdf *tab, int x, int y, int color)
{
	int		i;

	i = (x * tab->data.pixel_bits / 8) + (y * tab->data.line_bytes);
	tab->data.img[i] = color;
	tab->data.img[++i] = color >> 8;
	tab->data.img[++i] = color >> 16;
}

void	trace_line(float x0, float y0, t_fdf *tab)
{
	int		z0;
	int		z1;
	float	x_step;
	float	y_step;
	int		max;

	projection(&x0, &y0, &z0, tab);
	projection(&tab->x1, &tab->y1, &z1, tab);
	x0 += tab->h_move;
	y0 += tab->v_move;
	tab->x1 += tab->h_move;
	tab->y1 += tab->v_move;
	x_step = tab->x1 - x0;
	y_step = tab->y1 - y0;
	max = find_max(find_mod(x_step), find_mod(y_step));
	x_step /= max;
	y_step /= max;
	while ((int)(x0 - tab->x1) || (int)(y0 - tab->y1))
	{
		if (x0 < 1000 && y0 < 800 && x0 > 0 && y0 > 0)
			put_pxl(tab, x0, y0, fade(find_max(z0, z1)));
		x0 += x_step;
		y0 += y_step;
	}
}

void	tracing(t_fdf *tab)
{
	int	i;
	int	j;

	i = 0;
	while (i < tab->height)
	{
		j = 0;
		while (j < tab->width)
		{
			if (j < tab->width - 1)
			{
				tab->x1 = j + 1;
				tab->y1 = i;
				trace_line(j, i, tab);
			}
			if (i < tab->height - 1)
			{
				tab->x1 = j;
				tab->y1 = i + 1;
				trace_line(j, i, tab);
			}
			j++;
		}
		i++;
	}
}
