#include "fdf.h"


// keys handling
int event(int key,t_fdf *tab)
{
	// esc to quit
	if (key == 53)
		mlx_destroy_window(tab->p_mlx,tab->p_win);
	// zoom +
	if (key == 13)
		tab->zoom += 50;
	// zoom -
	if (key == 1)
		tab->zoom -= 50;
	
	printf("%d \n", tab->zoom);
	printf("%d \n", key);
	return 0;
}

// pannel of commands
void pannel(t_fdf *tab)
{
	int i = 0;
	int j;
	while (i < 700)
	{
		j = 0;
		while(j < 1000/4)
		{
			mlx_pixel_put(tab->p_mlx, tab->p_win, j, i, 0xC3B9CE);
			j++;
		}
		i++;
	}
	
	mlx_string_put (tab->p_mlx,tab->p_win, 20, 10, 0xFFFFFF, "== COMMANDS ==");
	mlx_string_put (tab->p_mlx,tab->p_win, 20, 30, 0xFFFFFF, "4 - rotate left");
	mlx_string_put (tab->p_mlx,tab->p_win, 20, 50, 0xFFFFFF, "6 - rotate right");
}

void loop(t_fdf *tab)
{
	mlx_key_hook(tab->p_win, event, tab);
	tracing(tab);
	mlx_loop(tab->p_mlx);
}

// main
int main(int ac, char **ag)
{
	t_fdf *tab;

	(void)ac;
	tab = malloc(sizeof(t_fdf));
	tab->zoom = 50;
	tab->ag = ag;
	tab->p_mlx = mlx_init();
	tab->p_win = mlx_new_window(tab->p_mlx, 1000, 700, "jdecorte - FdF");
	readfile(tab);
	//pannel(tab);
	loop(tab);
}

// gcc -Wall -Wextra -Werror -I minilibx -L minilibx_macos -lmlx -framework OpenGL -framework AppKit fdf.c main.c parse.c libft/libft.a 