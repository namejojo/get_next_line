#ifndef __GETNEXTLINE__
#define __GETNEXTLINE__

#include <stdio.h> // delete
#include <fcntl.h> // delete
#include <unistd.h>
#include <stdlib.h>

char	*get_next_line(int fd);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strcpy(char *dest, char *src);
char	*ft_strcat(char *dest, char *src);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_remain(char *keep);
char	**ft_split_once(char *str, int size);
int		check(char *str);
unsigned int	ft_strlen(char *s);
char	*next_line(char *str);

#endif