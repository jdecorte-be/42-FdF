#include "fdf.h"

// pannel of commands
void pannel(t_fdf *tab)
{
	mlx_string_put (tab->p_mlx,tab->p_win, 20, 10, 255, "== COMMANDS ==");
	mlx_string_put (tab->p_mlx,tab->p_win, 20, 30, 255, "4 - rotate left");
	mlx_string_put (tab->p_mlx,tab->p_win, 20, 50, 255, "6 - rotate right");
}

// main
int main(int ac, char **ag)
{
	t_fdf *tab;

	(void)ac;
	tab = malloc(sizeof(t_fdf));

	tab->ag = ag;
	tab->p_mlx = mlx_init();
	tab->p_win = mlx_new_window(tab->p_mlx, 1000, 700, "jdecorte - FdF");
	readfile(tab);
	pannel(tab);
	mlx_loop(tab->p_mlx);
}

// gcc -Wall -Wextra -Werror -I minilibx -L minilibx_macos -lmlx -framework OpenGL -framework AppKit fdf.c main.c parse.c libft/libft.a 