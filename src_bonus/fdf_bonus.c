#include "fdf_bonus.h"
#include <math.h>
#define MAX(a,b) (a > b ? a : b)
#define MIN(a,b) (a < b ? a : b)
#define MOD(a) ((a < 0) ? -a : a )

void projection(float *x, float *y, int z, t_fdf *tab)
{
	// isometric projection
	if(tab->projection == false)
	{
		*x = (*x - *y) * cos(0.8);
		*y = (*x + *y) * sin(0.8) - z;
	}
	// cabinet projection
	else
	{
		*x = *x + 0.5 * z * cos(0.8);
		*y = *y + 0.5 * z * sin(0.8);
		*x = *x * cos(0.8 + tab->rotation) - *y * sin(0.8 + tab->rotation);
		*y = *x * sin(0.8) + *y * cos(0.8) - z;
	}
}

void	trace_line(float x0, float y0, float x1, float y1,t_fdf *tab)
{
// isometric projection
	int z0 = tab->map[(int)y0][(int)x0];
	int z1 = tab->map[(int)y1][(int)x1];
// zoom
	x0 *= tab->zoom;
	y0 *= tab->zoom;
	x1 *= tab->zoom;
	y1 *= tab->zoom;

// adaptation
	z0 *= tab->h_view;
	z1 *= tab->h_view;

// projection
	projection(&x0,&y0,z0,tab);
	projection(&x1,&y1,z1,tab);

// allignement
	x0 += tab->h_move;
	y0 += tab->v_move;
	x1 += tab->h_move;
	y1 += tab->v_move;
	
	float x_step = x1 - x0;
	float y_step = y1 - y0;
	int max = MAX(MOD(x_step), MOD(y_step));
	x_step /= max;
	y_step /= max;
	while((int)(x0 - x1) || (int)(y0 - y1))
	{
		mlx_pixel_put(tab->p_mlx, tab->p_win, x0, y0, 0xBAFFE8 + 100 * MAX(MOD(z1),MOD(z0)));
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
