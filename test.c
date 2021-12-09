#include "fdf.h"

void test()
{
    int fd2 = open("10-70.fdf", O_RDONLY, 0);
    char *str = get_next_line(fd2);
    free(str);
    printf("%s\n", str);
    close(fd2);
}

int main()
{
    int fd = open("10-70.fdf", O_RDONLY, 0);
    char *str = get_next_line(fd);
    printf("%s\n", str);
    test();
    str = get_next_line(fd);
    printf("%s\n", str);
}