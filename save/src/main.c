#include "fdf.h"


// pannel of commands
void pannel(t_fdf *tab)
{
	// int i = 0;
	// int j;
	// while (i < 700)
	// {
	// 	j = 0;
	// 	while(j < 1000)
	// 	{
	// 		mlx_pixel_put(tab->p_mlx, tab->p_win, j, i, 0x1B1B1B);
	// 		j++;
	// 	}
	// 	i++;
	// }

	mlx_string_put (tab->p_mlx,tab->p_win, 20, 10, 0xB6B6B6 , "== COMMANDS ==");
	mlx_string_put (tab->p_mlx,tab->p_win, 20, 30, 0xB6B6B6 , "A - Shift to left");
	mlx_string_put (tab->p_mlx,tab->p_win, 20, 50, 0xB6B6B6 , "D - Shift to right");
	mlx_string_put (tab->p_mlx,tab->p_win, 20, 70, 0xB6B6B6 , "P - Change projection");
	if(tab->projection == false)
		mlx_string_put (tab->p_mlx,tab->p_win, 20, 90, 0xB6B6B6 , "Mode - Isometric");
	else
		mlx_string_put (tab->p_mlx,tab->p_win, 20, 90, 0xB6B6B6 , "Mode - Cabinet");
}

// keys handling
int event(int key,t_fdf *tab)
{
	// esc to quit
	if (key == 53)
		mlx_destroy_window(tab->p_mlx,tab->p_win);
	// zoom +
	if (key == 14)
		tab->zoom += 10;
	// zoom -
	if (key == 12 && tab->zoom - 10 > 0)
		tab->zoom -= 10;
	// left
	if (key == 0)
		tab->h_move += 50;
	// right
	if (key == 2)
		tab->h_move -= 50;
	// up
	if (key == 13)
		tab->v_move += 50;
	// down
	if (key == 1)
		tab->v_move -= 50;
	// projection
	if (key == 35)
	{
		if(tab->projection == false)
			tab->projection = true;
		else
			tab->projection = false;
	}
	// up
	if (key == 15)
		tab->h_view += 2;
	// down
	if (key == 3)
		tab->h_view -= 2;
	mlx_clear_window(tab->p_mlx,tab->p_win);
	pannel(tab);
	tracing(tab);
	printf("%d \n", key);
	return 0;
}


// main
int main(int ac, char **ag)
{
	if(ac == 2)
	{
		t_fdf *tab;

		tab = malloc(sizeof(t_fdf));
		tab->projection = false;
		tab->h_view = 2;
		tab->h_move = 700;
		tab->v_move = 200;
		tab->zoom = 20;
		tab->ag = ag;
		tab->p_mlx = mlx_init();
		tab->p_win = mlx_new_window(tab->p_mlx, 1000, 700, "jdecorte - FdF");
		readfile(tab);
		pannel(tab);
		tracing(tab);
		mlx_do_key_autorepeaton(tab->p_mlx);
		mlx_key_hook(tab->p_win, event, tab);
		mlx_loop(tab->p_mlx);
	}
}

// gcc -Wall -Wextra -Werror -I minilibx -L minilibx_macos -lmlx -framework OpenGL -framework AppKit fdf.c main.c parse.c libft/libft.a 