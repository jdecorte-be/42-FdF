#include "fdf.h"
#include <math.h>
#define MAX(a,b) (a > b ? a : b)
#define MOD(a) ((a < 0) ? -a : a)

void projection(float *x, float *y, int z)
{
	*x = (*x - *y) * cos(0.8);
	*y = (*x + *y) * sin(0.8) - z;
}

// Working
void	trace_line(float x0, float y0, float x1, float y1,t_fdf *tab)
{
// isometric projection
	int z0 = tab->map[(int)y0][(int)x0];
	int z1 = tab->map[(int)y1][(int)x1];
	printf("%d %d \n", z0, z1);

// zoom
	x0 *= tab->zoom;
	y0 *= tab->zoom;
	x1 *= tab->zoom;
	y1 *= tab->zoom;
// projection
	projection(&x0,&y0,z0);
	projection(&x1,&y1,z1);

// allignement
	x0 += 600;
	y0 += 200;
	x1 += 600;
	y1 += 200;
	tab->color = 0xffffff;
	if(z0 > 0|| z1 > 0)
		tab->color = 0xDE6564;

	float x_step = x1 - x0;
	float y_step = y1 - y0;
	int max = MAX(MOD(x_step), MOD(y_step));
	x_step /= max;
	y_step /= max;
	while((int)(x0 - x1) || (int)(y0 - y1))
	{
		mlx_pixel_put(tab->p_mlx, tab->p_win, x0, y0, tab->color);
		x0 += x_step;
		y0 += y_step;
	}
}

//draw all point
void tracing(t_fdf *tab)
{
	int i = 0;
	int j;

	while(i < tab->height)
	{
		j = 0;
		while(j < tab->width)
		{
			if (j < tab->width - 1)
				trace_line(j, i, j + 1, i, tab);
			if (i < tab->height - 1)
				trace_line(j, i, j , i  + 1, tab);
			j++;
		}
		i++;
	}
}
