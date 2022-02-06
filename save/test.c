#include "fdf.h"


int main()
{
    int fd = open("10-70.fdf", O_RDONLY, 0);
    char *str = get_next_line(fd);
    printf("%s\n", str);
    str = get_next_line(fd);
    printf("%s\n", str);
}