#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

char *get_next_line(int fd);
int ft_check(char *str);
char *ft_strcpy(char *dest, char *src);
char *ft_strcat(char *dest, char *src);
char *ft_strjoin(char *s1, char *s2);
int ft_remain(char *keep);
char **ft_split_once(char *str, int size);
int ft_checkend(char *str);
 
unsigned int ft_strlen(char *s)
{
	int ind;
	
	ind = 0;
	while(s[ind])
		ind++;
	return(ind);
}

char *ft_strcpy(char *dest, char *src)
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

char* ft_strcat(char *dest, char *src)
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

int main(void)
{
	int i;
	char* ol;
	
	i = open("teste.txt", O_CREAT | O_RDWR, 00700);

	ol = get_next_line(i);
	printf("%s",ol);
	free(ol);
	ol = get_next_line(i);
	printf("%s",ol);
	free(ol);
	ol = get_next_line(i);
	printf("%s",ol);
	free(ol);
	ol = get_next_line(i);
	printf("%s",ol);
	free(ol);
	ol = get_next_line(i);
	printf("%s",ol);
	free(ol);
	ol = get_next_line(i);
	printf("%s",ol);
	free(ol);
	ol = get_next_line(i);
	printf("%s",ol);
	free(ol);
	ol = get_next_line(i);
	printf("%s",ol);
	free(ol);
	ol = get_next_line(i);
	printf("%s",ol);
	free(ol);
	ol = get_next_line(i);
	printf("%s",ol);
	free(ol);ol = get_next_line(i);
	printf("%s",ol);
}

char *get_next_line(int fd)
{
	static int i = -2;
	char* hold;
	char* keep;
	char** temp;
	static char* sta;

	keep = (char*)malloc(BUFFER_SIZE + 1);
	hold = (char*)malloc(BUFFER_SIZE + 1);
	if(sta != NULL)
	{
		keep = ft_strcpy(keep, sta);
	}
	if (i != -2);
		//free(sta);
	while(ft_check(hold) == 0 && i != 0)
	{
		i = read(fd, hold, BUFFER_SIZE);
		keep = ft_strjoin(keep, hold);
	}
	if(ft_check(keep) == 0 && i == 0)
	{
		free(hold);
		free(keep);
		return(0);
	}
	temp = ft_split_once(keep, ft_strlen(keep));
	sta = (char*)malloc(ft_strlen(temp[1]));
	sta = ft_strcpy(sta, temp[1]);
	keep = (char*)malloc(ft_strlen(temp[0]));
	keep = ft_strcpy(keep, temp[0]);
	/*
	free(hold);
	free(temp[0]);
	free(temp[1]);
	free(temp);
	*/
	return(keep);
}

int ft_check(char *str)
{
	int ind;

	ind = 0;
	while(str[ind])
	{
		if(str[ind] == '\n')
			return (1);
		ind++;
	}
	return(0);
}

int ft_remain(char *keep)
{
	int ind;

	ind = 0;
	while(keep[ind] != '\n')
		ind++;
	if(keep[ind + 1] == '\0')
		return(0);
	return(1);
}

char **ft_split_once(char *str, int size)
{
	int count;
	int ind;
	char **ret;

	ret = (char**)malloc(2 * sizeof(char*));
	ind = -1;
	count = 0;
	while(str[count] != '\n')
		count++;
	ret[0] = (char*)malloc(count);
	ret[1] = (char*)malloc(size - count + 1);
	count = 0;
	while(str[ind++] != '\n')
		ret[0][ind] = str[ind];
	while(str[ind])
	{
		ret[1][count] = str[ind];
		count++;
		ind++;
	}
	//free(str);
	return(ret);
}

char *ft_strjoin(char *s1, char *s2)
{
	int total;
	char *dest;

	total = ft_strlen((char*)s1) + ft_strlen((char*)s2);
	dest = malloc((total + 1) * sizeof(char));
	ft_strcpy(dest, (char*)s1);
	ft_strcat(dest, (char*)s2);
	//free(s1);
	return(dest);
}