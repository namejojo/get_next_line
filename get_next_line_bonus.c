/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlima-so <jlima-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 09:20:43 by jlima-so          #+#    #+#             */
/*   Updated: 2025/04/14 10:42:32 by jlima-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	keep[FOPEN_MAX][(int)BUFFER_SIZE + 1];
	char		*ret;
	int			i;

	if (read(fd, &i, 0) == -1 || BUFFER_SIZE <= 0)
		return (NULL);
	i = 1;
	if (*keep[fd] == '\0')
	{
		i = read (fd, keep[fd], BUFFER_SIZE);
		((char *)keep[fd])[i] = '\0';
	}
	if (i < 1 && (*keep[fd] == '\0' || !check(keep[fd])))
		return (NULL);
	ret = ft_strjoin(NULL, keep[fd]);
	while (i && check(ret))
	{
		i = read (fd, keep[fd], BUFFER_SIZE);
		((char *)keep[fd])[i] = '\0';
		if (i < 1)
			break ;
		ret = ft_strjoin(ret, keep[fd]);
	}
	next_lines(keep[fd]);
	return (ret);
}
