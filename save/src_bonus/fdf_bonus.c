#include "fdf_bonus.h"
#include <math.h>
#define MAX(a,b) (a > b ? a : b)
#define MIN(a,b) (a < b ? a : b)
#define MOD(a) ((a < 0) ? -a : a )


int	fade(int h)
{
	if (h > 100)
		return (0xFFDF8D);
	if (h > 75)
		return (0xFFDE7A);
	if (h > 50)
		return (0xFFC568);
	if (h > 25)
		return (0xFD996B);
	if (h > 15)
		return (0xF7856C);
	if (h > 10)
		return (0xF06E6C);
	if (h > 5)
		return (0xD9576B);
	if (h > 0)
		return (0xA44369);
	if (h > -10)
		return (0x833F68);
	if (h > -20)
		return (0x833F68);
	if (h > -50)
		return (0x5E3C65);
	return (0x3F3A63);
}

void projection(float *x, float *y, int *z, t_fdf *tab)
{
	int x_tmp = *x;
	int y_tmp = *y;

	// rotation
	*x = (x_tmp - tab->width * 1.5) * cos(tab->rotation) - (y_tmp - tab->height * 1.5) * sin(tab->rotation);
	*y = (x_tmp - tab->width * 1.5) * sin(tab->rotation) + (y_tmp - tab->height * 1.5) * cos(tab->rotation);

	// isometric projection
	if(tab->projection == false)
	{
		*x = (*x - *y) * cos(0.8);
		*y = (*x + *y) * sin(0.8) - *z;
	}
	// cabinet projection
	else
	{
		*x = *x + 0.5 * cos(-1) * *z;
		*y = *y+ 0.5 * sin(-1) * *z;
	}
}

void put_pxl(t_fdf *tab, int x, int y, int color)
{
	int		i;

	i = (x * tab->data.pixel_bits / 8) + (y * tab->data.line_bytes);
	tab->data.img[i] = color;
	tab->data.img[++i] = color >> 8;
	tab->data.img[++i] = color >> 16;
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
	z0 *= tab->zoom;
	z1 *= tab->zoom;

// adaptation
	z0 *= tab->h_view;
	z1 *= tab->h_view;

// projection
	projection(&x0,&y0,&z0,tab);
	projection(&x1,&y1,&z1,tab);

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
		if(x0 < 1000 && y0 < 800 && x0 > 0 && y0 > 0)
			put_pxl(tab, x0, y0, fade(MAX(z0,z1)));
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
