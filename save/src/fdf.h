#ifndef FDF_H
# define FDF_H

# include <math.h>
# include "../minilibx_macos/mlx.h"
# include "../libft/libft.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

typedef enum {false, true} bool;

typedef struct s_fdf
{
	void 	*p_mlx;
	void	*p_win;
	char	**ag;
	int height;
	int width;
	int **map;
	int zoom;
	int color;
	int h_move;
	int v_move;
	bool projection;
	int h_view;
}		t_fdf;


char	*get_next_line(int fd);
int	ft_isdigit(int character);
void readfile(t_fdf *tab);
void tracing(t_fdf *tab);

#endif