#ifndef FDF_H
# define FDF_H

# include <math.h>
# include "../minilibx_macos/mlx.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

typedef struct s_fdf
{
	int fd;
	void  *p_mlx;

}		t_fdf;



#endif