#include "fdf.h"

int main(int ac, char **ag)
{
	t_fdf *tab;

	(void)ac;
	tab = malloc(sizeof(t_fdf));
	tab->fd = open(ag[1], O_RDONLY);
	tab->p_mlx = mlx_init();
	mlx_new_window(tab->p_mlx,1000,700,"Im the title");
	mlx_loop(tab->p_mlx);
}

// gcc -Wall -Wextra -Werror -I minilibx -L ../minilibx_macos -lmlx -framework OpenGL -framework AppKit fdf.c