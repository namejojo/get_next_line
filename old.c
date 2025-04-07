// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   old.c                                              :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: jlima-so <jlima-so@student.42.fr>          +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2025/04/06 21:07:35 by jlima-so          #+#    #+#             */
// /*   Updated: 2025/04/07 16:13:04 by jlima-so         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "get_next_line.h"

// // char	*ft_strcat(char *dest, char *src)
// // {
// // 	int	ind;
// // 	int	ind2;

// // 	ind = 0;
// // 	ind2 = ft_strlen(dest);
// // 	while (src[ind] != '\0')
// // 	{
// // 		dest[ind2] = src[ind];
// // 		ind++;
// // 		ind2++;
// // 	}
// // 	dest[ind2] = '\0';
// // 	return (dest);
// // }

// char	*ft_strdup(char *str)
// {
// 	char	*ret;

// 	ret = malloc(ft_strlen(str) + 1);
// 	ret = ft_strcpy(ret, str);
// 	return (ret);
// }

// char	*this_line(char *str)
// {
// 	char	*ret;
// 	int		ind;

// 	ind = 0;
// 	ret = NULL;
// 	while (str[ind] && str[ind] != '\n')
// 		ind++;
// 	if (str[ind] == '\n')
// 		ind++;
// 	ret = malloc(ind + 1);
// 	ret = ft_strcpy_to_line(ret, str);
// 	return (ret);
// }

// char	*ft_strjoin(char *s1, char *s2)
// {
// 	char	*dest;

// 	if (s1 == NULL && s2 == NULL)
// 		return (NULL);
// 	if (s1 == NULL)
// 		return (this_line(s2));
// 	if (s2 == NULL)
// 		return (s1);
// 	dest = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
// 	if (dest == NULL)
// 		return (NULL);
// 	dest = ft_strcpy_to_line(dest, s1);
// 	free (s1);
// 	dest = ft_strcat_to_line(dest, s2);
// 	return (dest);
// }
// void	next_line(char *str)
// {
// 	char *temp;
	
// 	temp = malloc (ft_strlen(str) + 1);//////////////
// 	temp = str;
// 	while (*temp && *(temp - 1) != '\n')
// 		temp++;
// 	temp = '\0';
// 	str = ft_memmove(str, temp, ft_strlen(temp));
// }

// void	*ft_memmove(void *dest, const void *src, size_t n)
// {
// 	size_t	ind;

// 	ind = -1;
// 	if (dest > src)
// 	{
// 		while (n-- > 0)
// 			((char *)dest)[n] = ((char *)src)[n];
// 	}
// 	else
// 	{
// 		while (++ind < n)
// 			((char *)dest)[ind] = ((char *)src)[ind];
// 	}
// 	return (dest);
// }

// int check (char *str)
// {
// 	while (*str)
// 	{
// 		if (*str == '\n')
// 			return (0);
// 		str++;
// 	}
// 	return (1);
// }

// char	*get_next_line(int fd)
// {
// 	static char	keep[BUFFER_SIZE + 1];
// 	char		*ret;
// 	int 		i;

// 	ret = NULL;
// 	i = read (fd, keep, BUFFER_SIZE);
// 	ret = ft_strjoin(ret, keep);
// 	printf("ret is hereFIRST:%s|\n",ret);
// 	while (check(ret) && i != 0)
// 	{
// 		i = read (fd, keep, BUFFER_SIZE);
// 		ret = ft_strjoin(ret, keep);
// 	}
// 	printf("ret is here:%s|\n",ret);
// 	if (check(ret) && i == 0)
// 	{
// 		if (keep != NULL)
// 		return (NULL);
// 	}
// 	next_line(keep);
// 	return (ret);
// }
