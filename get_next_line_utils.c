#include "get_next_line.h"

void *ft_calloc(size_t nmemb, size_t size)
{
	void *ret;
	size_t ind;

	if(nmemb == 0 || size == 0)
		return(NULL);
	ret = malloc(size * nmemb);
	while(ind <= nmemb * size)
		((char *)ret)[ind++] = '\0';
	return(ret);
}