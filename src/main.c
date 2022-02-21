/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: decortejohn <decortejohn@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 11:52:52 by decortejohn       #+#    #+#             */
/*   Updated: 2022/02/16 14:52:00 by decortejohn      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_background(t_fdf *tab, int color)
{
	int	x;
	int	y;

	y = 0;
	while (++y < 800)
	{
		x = 0;
		while (++x < 1000)
			put_pxl(tab, x, y, color);
	}
}

void	pannel(t_fdf *tab)
{
	mlx_string_put (tab->p_mlx, tab->p_win, 20, 10, 0xFFFFFF, "<< COMMANDS >>");
	mlx_string_put (tab->p_mlx, tab->p_win, 20, 30, 0xFFFFFF, "W - Move up");
	mlx_string_put (tab->p_mlx, tab->p_win, 20, 50, 0xFFFFFF, "S - Move down");
	mlx_string_put (tab->p_mlx, tab->p_win, 20, 70, 0xFFFFFF, "A - Move left");
	mlx_string_put (tab->p_mlx, tab->p_win, 20, 90,
		0xFFFFFF, "D - Move right");
	mlx_string_put(tab->p_mlx, tab->p_win, 20, 110,
		0xFFFFFF, "R - Increase depth");
	mlx_string_put (tab->p_mlx, tab->p_win, 20, 130,
		0xFFFFFF, "F - Decrease depth");
}

void	show_map(t_fdf *tab)
{
	mlx_clear_window(tab->p_mlx, tab->p_win);
	tab->img = mlx_new_image(tab->p_mlx, 1000, 800);
	tab->data.img = mlx_get_data_addr(tab->img, &tab->data.pixel_bits,
			&tab->data.line_bytes, &tab->data.endian);
	draw_background(tab, 0x181C26);
	tracing(tab);
	mlx_put_image_to_window(tab->p_mlx, tab->p_win, tab->img, 0, 0);
	pannel(tab);
}

int	event(int key, t_fdf *tab)
{
	if (key == 53)
	{
		mlx_destroy_window(tab->p_mlx, tab->p_win);
		exit(0);
	}
	if (key == 0)
		tab->h_move += 20;
	if (key == 2)
		tab->h_move -= 20;
	if (key == 13)
		tab->v_move += 20;
	if (key == 1)
		tab->v_move -= 20;
	if (key == 15)
		tab->h_view += 0.01;
	if (key == 3)
		tab->h_view -= 0.01;
	show_map(tab);
	return (0);
}

int	main(int ac, char **ag)
{
	t_fdf	*tab;

	if (ac != 2)
		exit(-1);
	tab = malloc(sizeof(t_fdf));
	if (!tab)
		exit(-1);
	tab->h_view = 0.01;
	tab->h_move = 500;
	tab->v_move = 50;
	tab->ag = ag;
	tab->p_mlx = mlx_init();
	readfile(tab);
	tab->p_win = mlx_new_window(tab->p_mlx, 1000, 800, ag[1]);
	tab->zoom = find_max(1000 / tab->width, 2);
	show_map(tab);
	mlx_do_key_autorepeaton(tab->p_mlx);
	mlx_hook(tab->p_win, 2, (1L << 0), event, tab);
	mlx_loop(tab->p_mlx);
}
