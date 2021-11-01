#ifndef FDF_H
# define FDF_H

# include <math.h>
# include "../minilibx_macos/mlx.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct s_fdf
{
	int		fd;
	void 	*p_mlx;
	void	*p_win;
	int		x1;
	int		y1;
	int		x2;
	int		y2;

}		t_fdf;


char	*get_next_line(int fd);
int	ft_isdigit(int character);

#endif