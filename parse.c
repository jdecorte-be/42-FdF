#include "fdf.h"

// get height
int getheight(t_fdf *tab)
{
	int fd = open(tab->ag[1], O_RDONLY);
	int i = 0;
	char *str = get_next_line(fd);
	while(str)
	{
		str = get_next_line(fd);
		i++;
	}
	return i;
}

// get width
int getwidth(t_fdf *tab)
{
	int fd = open(tab->ag[1], O_RDONLY);
	char *str = get_next_line(fd);
	int i = 0;
	int count = 0;
	while(str[i])
	{
		if(ft_isdigit(str[i]) != 0)
			count++;
		i++;
	}
	return count;
}

// malloc file
int **mallocfile(t_fdf *tab)
{
	tab->height = getheight(tab);
	tab->width = getwidth(tab);
	int **res = malloc(sizeof(int *) * tab->height);
	int i = 0;

	while(i < tab->height)
	{
		res[i] = malloc(sizeof(int) * tab->width);
		i++;
	}
	return res;
}

// read file and return int**
void readfile(t_fdf *tab)
{
	int **file = mallocfile(tab);
	int fd = open(tab->ag[1], O_RDONLY);
	char *str = get_next_line(fd);
	int j = 0;
	int i;
	printf("%d\n", j);
	while(str)
	{
		i = 0;
		char **fdsplit = ft_split(str, ' ');
		while(fdsplit[i])
		{
			file[j][i] = ft_atoi(fdsplit[i]);
			i++;
		}
		str = get_next_line(fd);
		j++;
		free(fdsplit);
	}
	printf("%d\n", j);


}