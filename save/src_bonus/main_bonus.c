/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: decortejohn <decortejohn@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 11:52:52 by decortejohn       #+#    #+#             */
/*   Updated: 2022/02/06 12:10:49 by decortejohn      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	draw_background(t_fdf *tab, int color)
{
	int	x;
	int	y;
	int	i;

	i = 0;
	y = 0;
	while (++y < 800)
	{
		x = 0;
		while (++x < 1000)
		{
			i = (x * tab->data.pixel_bits / 8) + (y * tab->data.line_bytes);
			tab->data.img[i] = color;
			tab->data.img[++i] = color >> 8;
			tab->data.img[++i] = color >> 16;
		}
	}
}

// pannel of commands
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
	mlx_string_put (tab->p_mlx, tab->p_win, 20, 150,
		0xFFFFFF, "E - Increase zoom");
	mlx_string_put (tab->p_mlx, tab->p_win, 20, 170,
		0xFFFFFF, "Q - Decrease zoom");
	mlx_string_put (tab->p_mlx, tab->p_win, 20, 190,
		0xFFFFFF, "< - Left rotation");
	mlx_string_put (tab->p_mlx, tab->p_win, 20, 210,
		0xFFFFFF, "> - Right rotation");
	if (tab->projection == false)
		mlx_string_put (tab->p_mlx, tab->p_win, 20, 230,
			0xFFFFFF, "Mode - Isometric");
	else
		mlx_string_put (tab->p_mlx, tab->p_win, 20, 230,
			0xFFFFFF, "Mode - Cabinet");
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

// keys handling
int	event(int key, t_fdf *tab)
{
	if (key == 53)
		mlx_destroy_window(tab->p_mlx, tab->p_win);
	if (key == 14)
		tab->zoom += 2;
	if (key == 12 && tab->zoom - 2 >= 2)
		tab->zoom -= 2;
	if (key == 0)
		tab->h_move += 20;
	if (key == 2)
		tab->h_move -= 20;
	if (key == 13)
		tab->v_move += 20;
	if (key == 1)
		tab->v_move -= 20;
	if (key == 35)
	{
		if (tab->projection == false)
			tab->projection = true;
		else
			tab->projection = false;
	}
	if (key == 15)
		tab->h_view += 0.01;
	if (key == 3)
		tab->h_view -= 0.01;
	if (key == 123)
		tab->rotation -= 0.1;
	if (key == 124)
		tab->rotation += 0.1;
	show_map(tab);
	return (0);
}

int	main(int ac, char **ag)
{
	t_fdf	*tab;

	if (ac != 2)
		ft_putstr_fd("ERROR\n", 2);
	tab = malloc(sizeof(t_fdf));
	tab->projection = false;
	tab->rotation = 0;
	tab->h_view = 0.01;
	tab->flip = 1;
	tab->h_move = 500;
	tab->v_move = 50;
	tab->ag = ag;
	tab->p_mlx = mlx_init();
	readfile(tab);
	tab->p_win = mlx_new_window(tab->p_mlx, 1000, 800, ag[1]);
	tab->zoom = MAX(1000 / tab->width, 2);
	show_map(tab);
	mlx_do_key_autorepeaton(tab->p_mlx);
	mlx_hook(tab->p_win, 2, (1L << 0), event, tab);
	mlx_loop(tab->p_mlx);
}
