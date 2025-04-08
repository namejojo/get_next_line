/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlima-so <jlima-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 16:13:13 by jlima-so          #+#    #+#             */
/*   Updated: 2025/04/08 17:34:38 by jlima-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	keep[BUFFER_SIZE + 1];
	char		*ret;
	int			i;

	i = 1;
	if (*keep == '\0')
	{
		ft_bzero(keep, BUFFER_SIZE + 1);
		i = read (fd, keep, BUFFER_SIZE);
		if (i == 0 && (*keep == '\0' || !check(keep)))
			return (NULL);
	}
	if (i == 0 && *keep == '\0')
		return (NULL);
	ret = ft_strjoin(NULL, keep);
	while (i && check(ret))
	{
		ft_bzero(keep, BUFFER_SIZE + 1);
		i = read (fd, keep, BUFFER_SIZE);
		if (i == 0)
			break ;
		ret = ft_strjoin(ret, keep);
	}
	if (i == 0 && (*keep == '\0' || !check(keep)))
		return (NULL);
	next_lines(keep);
	return (ret);
}
