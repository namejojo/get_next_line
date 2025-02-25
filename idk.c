#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int ft_count(char *str)
{
	int ind;
	int count;

	count = 0;
	ind = 0;
	while(str[ind])
	{
		if(str[ind] == '\n')
			count++;
		ind++;
	}
	return(count);
}

int ft_check(char *str)
{
	int ind;

	ind = 0;
	while(str[ind])
	{
		if(str[ind] == '\n')
			return(1);
		ind++;
	}
	return(0);
}

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

unsigned int ft_strlen(char *s)
{
	int ind;
	
	ind = 0;
	while(s[ind])
		ind++;
	return(ind);
}

static char *ft_strcpy(char *dest, char *src)
{
	int ind;
	
	ind = 0;
	while (src[ind] != '\0')
	{
		dest[ind] = src[ind];
		ind++;
	}
	dest[ind] = '\0';
	return (dest);
}

static char* ft_strcat(char *dest, char *src)
{
	int ind;
	int ind2;

	ind = 0;
	ind2 = ft_strlen(dest);
	while(src[ind] != '\0')
		dest[ind2++] = src[ind++];
	dest[ind2] = '\0';
	return(dest);
}

char *ft_strjoin(char const *s1, char const *s2)
{
	int total;
	char *dest;

	total = 0;
	total = ft_strlen((char*)s1) + ft_strlen((char*)s2);
	dest = ft_calloc((total + 1), 1);
	ft_strcpy(dest, (char*)s1);
	ft_strcat(dest, (char*)s2);
	return(dest);
}

char **ft_split_once(char *str, int size)
{
	int count;
	int ind;
	char **ret;

	ret = (char**)ft_calloc(2,sizeof(char*));
	ind = -1;
	count = 0;
	while(str[count] != '\n')
		count++;
	ret[0] = (char*)ft_calloc(count, 1);
	ret[1] = (char*)ft_calloc(size - count + 1, 1);
	count = 0;
	while(str[ind++] != '\n')
		ret[0][ind] = str[ind];
	while(str[ind])
	{
		ret[1][count] = str[ind];
		count++;
		ind++;
	}
	return(ret);
}

void ft_free(char **ret, char *temp, char *buff)
{
	free(ret[0]);
	free(ret);
	free(temp);
	free(buff);
}

char* get_next_line(int fd)
{
	static int i = -2;
	static char **ret;
	char *temp;
	char *buff;

	if(i == -3)
		return(NULL);
	temp = (char*)malloc(BUFFER_SIZE);
	buff = (char*)malloc(BUFFER_SIZE);
	if(i > -1)
	{
		temp = ft_strjoin(temp, ret[1]);
		free(ret[1]);
	}
	while(ft_check(buff) == 0 && i != 0)
	{
		i = read(fd, buff, BUFFER_SIZE);
		temp = ft_strjoin(temp, buff);
	}
	if((i == 0 && ft_count(temp) < 2))
	{
		ft_free(ret, temp, buff);
		i = -3;
		return(NULL);
	}
	ret = ft_split_once(temp, ft_strlen(temp));
	return(ret[0]);
}

int main(void)
{
	int i;
	
	i = open("teste.txt", O_CREAT | O_RDWR, 00700);
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
	/*
	get_next_line(i);
	get_next_line(i);
	get_next_line(i);
	get_next_line(i);
	get_next_line(i);
	get_next_line(i);
	get_next_line(i);
	get_next_line(i);
	*/
}