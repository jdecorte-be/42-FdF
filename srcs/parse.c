#include "fdf.h"

// get height
int getheight(t_fdf *tab)
{
	int fd = open(tab->ag[1], O_RDONLY, 0);
	int i = 0;
	char *str;
	while((str = get_next_line(fd)))
	{
		str = get_next_line(fd);
		i++;
		free(str);
	}
	close(fd);
	return i;
}

// get width
int getwidth(t_fdf *tab)
{
	int i = 0;
	int fd = open(tab->ag[1], O_RDONLY, 0);
	char **strsplited = ft_split(get_next_line(fd), ' ');
	while(*strsplited)
	{
		strsplited++;
		i++;
	}
	close(fd);
	return i;
}

// malloc file
int **mallocfile(t_fdf *tab)
{
	tab->width = getwidth(tab);
	tab->height = getheight(tab);
	int **res = malloc(sizeof(int *) * (tab->height + 1));
	int i = 0;
	char **str;
	int fd = open(tab->ag[1], O_RDONLY);
	int j;
	while(i < tab->height)
	{
		j = 0;
		str = ft_split(get_next_line(fd), ' ');
		while(*str)
		{
			str++;
			j++;
		}
		res[i] = malloc(sizeof(int) * (j + 1));
		i++;
	}
	return res;
}

void printmap(int i,int j,int **A)
{
    printf("\n");
    int m,n;
    for (m=0;m<i;m++)
        {
            for (n=0;n<j;n++)
            {
                printf("A[%d,%d]=%d\n",m,n,A[m][n]);
            }
        }
}

// read file and return int**
void readfile(t_fdf *tab)
{
	int **file = mallocfile(tab);
	int fd = open(tab->ag[1], O_RDONLY);
	char *str;
	int j = 0;
	int i;
	while((str = get_next_line(fd)))
	{
		i = 0;
		char **fdsplit = ft_split(str, ' ');
		while(fdsplit[i])
		{
			file[j][i] = ft_atoi(fdsplit[i]);
			i++;
		}
		j++;
		free(fdsplit);
	}
	tab->map = file;
}

