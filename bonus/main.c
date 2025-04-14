#include "get_next_line_bonus.h"
#include <stdio.h>

int main(void)
{
    int             i;
    int             i2;
    char    *ret;

    i = open("test", O_RDONLY);
    i2 = open("teste.txt", O_RDONLY);
    // do {
    //         ret = get_next_line(i);
    //         printf("%s", ret);
    //         if (ret != NULL)
    //                 free (ret);
    // } while (ret != NULL);
	ret = get_next_line(i);
	printf("%s", ret);
	if (ret != NULL)
		free (ret);

	 ret = get_next_line(i2);
	 printf("%s", ret);
	 if (ret != NULL)
	     free (ret);

	ret = get_next_line(i);
	printf("%s", ret);
	if (ret != NULL)
		free (ret);

	ret = get_next_line(i2);
	printf("%s", ret);
	if (ret != NULL)
		free (ret);

	ret = get_next_line(10);
	printf("%s", ret);
	if (ret != NULL)
		free (ret);

}