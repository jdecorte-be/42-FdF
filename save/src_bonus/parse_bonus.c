#include "fdf_bonus.h"

// get height
int getheight(t_fdf *tab)
{
	int fd = open(tab->ag[1], O_RDONLY);
	int i = 0;
	char *str = get_next_line(fd);
	while(str)
	{
		printf("%s ", str);
		i++;
		free(str);
		str = get_next_line(fd);
	}
	close(fd);
	printf("%d======= \n", i);
	return i;
}

// get weight
int getweight(t_fdf *tab)
{
	int fd = open(tab->ag[1], O_RDONLY);
	char **s_str = ft_split(get_next_line(fd), ' ');
	int i = 0;
	while(s_str[i])
		i++;
	free(s_str);
	close(fd);
	return i;
}

// malloc file
int **mallocfile(t_fdf *tab)
{
	tab->width = getweight(tab);
	tab->height = getheight(tab);
	int **res = malloc(sizeof(int *) * tab->height);
	int i = 0;
	while(i < tab->height)
	{
		res[i] = malloc(sizeof(int) * tab->width );
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
	char *str = get_next_line(fd);
	int j = 0;
	int i;
	while(j < tab->height)
	{
		char **s_str = ft_split(str, ' ');
		i = 0;
		while(i < tab->width)
		{
			file[j][i] = ft_atoi(s_str[i]);
			i++;
		}
		str = get_next_line(fd);
		free(s_str);
		j++;
	}
	tab->map = file;
	close(fd);
}

