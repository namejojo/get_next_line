#include "get_next_line.h"

int main(void)
{
	int i;
	// char *ret="ola bom dia \n1olla ola\n";
	// char ret1[50]="eu vou dizer/";
// 
	 i = open("teste.txt", O_RDWR, 00700);
	// 
	// read (i, ret, 999);
	// read (i, ret, 999);
	// ret1 = ft_strjoin(ret1, ret);
	// printf("%s", ret1);
	
	printf("%s",get_next_line(i));
	printf("%s",get_next_line(i));
	printf("%s",get_next_line(i));
	/*
	printf("%s",get_next_line(i));
	printf("%s",get_next_line(i));
	printf("%s",get_next_line(i));
	printf("%s",get_next_line(i));
	printf("%s",get_next_line(i));
	printf("%s",get_next_line(i));
	printf("%s",get_next_line(i));
	printf("%s",get_next_line(i));
	printf("%s",get_next_line(i));
	printf("%s",get_next_line(i));
	get_next_line(i);
	get_next_line(i);
	get_next_line(i);
	get_next_line(i);
	get_next_line(i);
	get_next_line(i);
	get_next_line(i);
	*/
}