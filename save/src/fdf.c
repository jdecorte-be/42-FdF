#include "fdf.h"
#include <math.h>
#define MAX(a,b) (a > b ? a : b)
#define MOD(a) ((a < 0) ? -a : a)

void projection(float *x, float *y, int z, t_fdf *tab)
{
	(void)tab;
	// isometric projection
	*x = (*x - *y) * cos(0.8);
	*y = (*x + *y) * sin(0.8) - z;
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
	tab->color = 0xffffff;
	if(z0 > 9 && z1 > 9)
		tab->color = 0xFF4242;
	else if(z0 > 5 && z1 > 5)
		tab->color = 0xFF6242;
	else if(z0 > 2 && z1 > 2)
		tab->color = 0xFF8D42;
	else if(z0 > -1 && z1 > -1)
		tab->color = 0xFFB842;
	else if(z0 > -5 && z1 > -5)
		tab->color = 0xFFD742;
	else if(z0 > -10 && z1 > -10)
		tab->color = 0xFFF442;
	else if(z0 > -20 && z1 > -20)
		tab->color = 0xD7FF42;

	float x_step = x1 - x0;
	float y_step = y1 - y0;
	int max = MAX(MOD(x_step), MOD(y_step));
	x_step /= max;
	y_step /= max;
	while((int)(x0 - x1) || (int)(y0 - y1))
	{
		put_pxl(tab, x0, y0, 0xABCDEF);
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
