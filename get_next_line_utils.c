/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlima-so <jlima-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 10:00:20 by jlima-so          #+#    #+#             */
/*   Updated: 2025/04/08 10:00:44 by jlima-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line"

void	next_lines(char *ret)
{
	int	ind;
	int	add;

	add = ft_strlen(ret);
	ind = 0;
	while (ret[ind + add] && ret[ind])
	{
		ret[ind] = ret[ind + add];
		ind++;
	}
	if (ret[ind + add] == '\0')
		ret[ind] = '\0';
}

int	ft_strlen(char *str)
{
	int	ind;

	ind = 0;
	while (str[ind])
	{
		ind++;
		if (str[ind - 1] == '\n')
			return (ind);
	}
	return (ind);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*ret;
	int		ind;

	if (s1 == NULL)
	{
		s1 = malloc (1);
		s1[0] = '\0';	
	}
	ret = malloc (ft_strlen(s1) + ft_strlen(s2) + 1);
	ind = 0;
	while (s1[ind])
	{
		ret[ind] = s1[ind];
		ind++;
	}
	free (s1);
	while (*s2)
	{
		ret[ind] = *(s2);
		ind++;
		s2++;
		if(*(s2 - 1) == '\n')
			break;
	}
	ret[ind] = '\0';
	return (ret);
}

int		check(char *str)
{
	while (*str)
	{
		if (*str == '\n')
			return (0);
		str++;
	}
	return (1);
}

void	ft_bzero(void *s, size_t n)
{
	while (n-- > 0)
		((char *)s)[n] = 0;
}