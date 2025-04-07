/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlima-so <jlima-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 21:07:35 by jlima-so          #+#    #+#             */
/*   Updated: 2025/04/07 08:24:31 by jlima-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(char *str)
{
	char *ret;

	ret = malloc(ft_strlen(str) + 1);
	ret = ft_strcpy(ret ,str);
	return (ret);
}

unsigned int	ft_strlen(char *s)
{
	int	ind;

	ind = 0;
	while (s[ind])
		ind++;
	return (ind);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	ind;

	ind = 0;
	while (src[ind] != '\0')
	{
		dest[ind] = src[ind];
		ind++;
	}
	dest[ind] = '\0';
	return (dest);
}

char	*ft_strcat(char *dest, char *src)
{
	int	ind;
	int	ind2;

	ind = 0;
	ind2 = ft_strlen(dest);
	while (src[ind] != '\0')
	{
		dest[ind2] = src[ind];
		ind++;
		ind2++;
	}
	dest[ind2] = '\0';
	return (dest);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		total;
	char	*dest;

	if ((char *)s1 == NULL && (char *)s2 == NULL)
		return (NULL);
	if (s1 == NULL)
		return (ft_strdup((char *)s2));
	if (s2 == NULL)
		return (ft_strdup((char *)s1));
	total = ft_strlen((char *)s1) + ft_strlen((char *)s2);
	dest = malloc(total + 1);
	if (dest == NULL)
		return (NULL);
	dest = ft_strcpy(dest, (char *)s1);
	free ((char *)s1);
	dest = ft_strcat(dest, (char *)s2);
	return (dest);
}

char	*next_line(char *str)
{
	char *ret;
	int len;

	while (*str && *str != '\n')
		str++;
	if (*str == '\n')
		str++;
	len = ft_strlen(str);
	if (len == 0)
		return (NULL);
	ret = malloc(len + 1);
	ret = ft_strdup(str);
	return (ret);
}

int check (char *str)
{
	while (*str)
	{
		if (*str == '\n')
			return (0);
		str++;
	}
	return (1);
}

char	*get_next_line(int fd)
{
	static char		*keep;
	char		*ret;
	int 		i;

	i = 1;
	ret = NULL;
	if (keep == NULL)
	{
		keep = malloc(BUFFER_SIZE + 1);
		i = read (fd, keep, BUFFER_SIZE);
		ret = ft_strjoin(ret, keep);
		if (i == 0 && *ret == 0)
			return (NULL);
	}
	else
		keep = next_line(keep);
	while (check(ret) && i != 0)
	{
		i = read (fd, keep, BUFFER_SIZE);
		ret = ft_strjoin(ret, keep);
	}
	return (ret);
}