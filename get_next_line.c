#include "get_next_line.h"

char* get_next_line(int fd)
{
	char *ret;
	char buff;
	int i = 1;
	int ind;
	
	ret = (char*)ft_calloc(1,100);
	buff = 'a';
	ind = 0;
	while(buff != '\n' && i == 1)
	{
		i = read(fd, &buff, 1);
		ret[ind] = buff;
		ind++;
	}
	if(i == 0)
		return(NULL);
	return(ret);
}