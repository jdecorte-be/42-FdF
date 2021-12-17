#include "fdf_bonus.h"
#define MAX(a,b) (a > b ? a : b)

// pannel of commands
void pannel(t_fdf *tab)
{
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
		tab->zoom += 2;
	// zoom -
	if (key == 12 && tab->zoom - 2 >= 2)
		tab->zoom -= 2;
	// left
	if (key == 0)
		tab->h_move += 20;
	// right
	if (key == 2)
		tab->h_move -= 20;
	// up
	if (key == 13)
		tab->v_move += 20;
	// down
	if (key == 1)
		tab->v_move -= 20;
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
	if (key == 123)
		tab->rotation -= 0.1;
	if (key == 124)
		tab->rotation += 0.1;
	mlx_clear_window(tab->p_mlx,tab->p_win);
	pannel(tab);
	tracing(tab);
	printf("%d \n", key);
	return 0;
}

// main
int main(int ac, char **ag)
{
	if(ac != 2)
		printf("ERROR\n");
	t_fdf *tab;

	tab = malloc(sizeof(t_fdf));
	tab->projection = false;
	tab->rotation = 0;
	tab->h_view = 2;
	tab->flip = 1;
	tab->h_move = 500;
	tab->v_move = 50;
	tab->ag = ag;
	tab->p_mlx = mlx_init();
	readfile(tab);
	tab->p_win = mlx_new_window(tab->p_mlx, 1000, 800, ag[1]);
	tab->zoom = 600/(MAX(tab->height-1,3));
	pannel(tab);
	tracing(tab);
	mlx_do_key_autorepeaton(tab->p_mlx);
	mlx_hook(tab->p_win, 2, (1L << 0), event, tab);
	mlx_loop(tab->p_mlx);
}

// gcc -Wall -Wextra -Werror -I minilibx -L minilibx_macos -lmlx -framework OpenGL -framework AppKit fdf.c main.c parse.c libft/libft.a 