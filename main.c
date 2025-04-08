#include "get_next_line.h"
#include <stdio.h>

int main(void)
{
	int		i;
	char	*ret;
	// char	*a;

	// a = "\n\n\nola";a
	// char *ret="ola bom dia \n1olla ola\n";
	// char ret1[50]="eu vou dizer/";
// 
	 i = open("teste.txt", O_RDWR, 00700);
	// 
	i = 100000000;
	ret = get_next_line(i);
	printf("NEXT LINE IS:%s", ret);
	if (ret != NULL)
		free (ret);
	ret = get_next_line(i);
	printf("NEXT LINE IS:%s", ret);
	if (ret != NULL)
		free (ret);
	ret = get_next_line(i);
	printf("NEXT LINE IS:%s", ret);
	if (ret != NULL)
		free (ret);
	ret = get_next_line(i);
	printf("NEXT LINE IS:%s", ret);
	if (ret != NULL)
		free (ret);
	ret = get_next_line(i);
	printf("NEXT LINE IS:%s", ret);
	if (ret != NULL)
		free (ret);
	ret = get_next_line(i);
	printf("NEXT LINE IS:%s", ret);
	if (ret != NULL)
		free (ret);
	ret = get_next_line(i);
	printf("NEXT LINE IS:%s", ret);
	if (ret != NULL)
		free (ret);
	ret = get_next_line(i);
	printf("NEXT LINE IS:%s", ret);
	if (ret != NULL)
		free (ret);
	ret = get_next_line(i);
	printf("NEXT LINE IS:%s", ret);
	if (ret != NULL)
		free (ret);
	ret = get_next_line(i);
	printf("NEXT LINE IS:%s", ret);
	if (ret != NULL)
		free (ret);
	ret = get_next_line(i);
	printf("NEXT LINE IS:%s", ret);
	if (ret != NULL)
		free (ret);
		

	ret = get_next_line(i);
	printf("NEXT LINE IS:%s", ret);
	if (ret != NULL)
		free (ret);

	ret = get_next_line(i);
	printf("NEXT LINE IS:%s", ret);
	if (ret != NULL)
		free (ret);

	ret = get_next_line(i);
	printf("NEXT LINE IS:%s", ret);
	if (ret != NULL)
		free (ret);

}