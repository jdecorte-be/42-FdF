#include "fdf.h"

// Working
void	trace_line(t_fdf *tab)
{
	int i1 = 2 * (tab->y2 - tab->y1);
	int d = i1 - (tab->x2 - tab->x1);
	int x = tab->x1;
	int y = tab->y1;
	while(x <= tab->x2)
	{
		mlx_pixel_put (tab->p_mlx, tab->p_win, x, y, 255);
		d += i1;
		if (d >= 0)
		{
			y++;
			d -= 2 * (tab->x2 - tab->x1);
		}
		x++;
	}
}
