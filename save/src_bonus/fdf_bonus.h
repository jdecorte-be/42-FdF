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

#define MAX(a,b) (a > b ? a : b)
#define MOD(a) ((a < 0) ? -a : a )
#define MIN(a,b) (a < b ? a : b)

typedef enum {false, true} bool;

typedef struct s_img_data
{
	int pixel_bits;
	int line_bytes;
	int endian;
	char *img;
}	t_img_data;

typedef struct s_fdf
{
	t_img_data data;
	t_img_data back_data;
	void *background;
	void	*img;
	void 	*p_mlx;
	void	*p_win;
	char	**ag;
	int height;
	int width;
	int **map;
	float zoom;
	int color;
	int h_move;
	int v_move;
	bool projection;
	float h_view;
	float rotation;
	int flip;
}		t_fdf;

void put_pxl(t_fdf *tab, int x, int y, int color);
char	*get_next_line(int fd);
int	ft_isdigit(int character);
void readfile(t_fdf *tab);
void tracing(t_fdf *tab);

#endif