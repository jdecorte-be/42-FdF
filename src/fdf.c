#include "fdf.h"
#include "mlx.h"

int getheight(t_fdf *tab)
{
	char *str = get_next_line(tab->fd);
	int i = 1;
	while(str)
	{
		str = get_next_line(tab->fd);
		i++;
	}
	return i;
}

int getweight(t_fdf *tab)
{
	char *str = get_next_line(tab->fd);
	int i = -1;
	int count = 0;
	while(str[++i])
	{
		if(ft_isdigit(str[++i]) != 0)
			count++;
	}
	return count;
}

void readfile(t_fdf *tab)
{
	int height = getheight(tab);
	int weight = getweight(tab);

	printf("%d %d", height, weight);
}






// pannel of commands
void pannel(t_fdf *tab)
{
	mlx_string_put (tab->p_mlx,tab->p_win, 20, 10, 255, "== COMMANDS ==");
	mlx_string_put (tab->p_mlx,tab->p_win, 20, 30, 255, "4 - rotate left");
	mlx_string_put (tab->p_mlx,tab->p_win, 20, 50, 255, "6 - rotate right");
}

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

// main
int main(int ac, char **ag)
{
	t_fdf *tab;

	(void)ac;
	tab = malloc(sizeof(t_fdf));

	tab->fd = open(ag[1], O_RDONLY);
	tab->p_mlx = mlx_init();
	tab->p_win = mlx_new_window(tab->p_mlx, 1000, 700, "jdecorte - FdF");
	readfile(tab);
	pannel(tab);
	mlx_loop(tab->p_mlx);
}

// gcc ../libft/libft.a fdf.c ../libft/libft.a -L /usr/local/lib/ -lmlx -framework OPenGL -framework Appkit
