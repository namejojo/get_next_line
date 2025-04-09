#include "get_next_line.h"
#include <stdio.h>

int main(void)
{
        int             i;
        char    *ret;

        i = open("teste.txt", O_RDONLY);
        do {
                ret = get_next_line(i);
                printf("%s", ret);
                if (ret != NULL)
                        free (ret);
        } while (ret != NULL);
// 		ret = get_next_line(i);
// 		printf("%s", ret);
// 		if (ret != NULL)
// 			free (ret);
// // 
//         ret = get_next_line(i);
//         printf("%s", ret);
//         if (ret != NULL)
//             free (ret);
// // 
// 		ret = get_next_line(i);
// 		printf("%s", ret);
// 		if (ret != NULL)
// 		free (ret);
// // 
// 		ret = get_next_line(i);
// 		printf("%s", ret);
// 		if (ret != NULL)
// 				free (ret);
// // 
// 	printf("this fd is wronaaag\n");

// 		ret = get_next_line(10000);
// 		printf("%s", ret);
// 		if (ret != NULL)
// 				free (ret);
}