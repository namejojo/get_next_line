/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlima-so <jlima-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 09:20:43 by jlima-so          #+#    #+#             */
/*   Updated: 2025/04/30 13:11:13 by jlima-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	keep[FOPEN_MAX][BUFFER_SIZE + 1];
	char		*ret;
	int			i;

	if (BUFFER_SIZE <= 0)
		return (NULL);
	i = 1;
	if (*keep[fd] == '\0')
		i = zero_read(fd, keep[fd]);
	if (i < 1 && (*keep[fd] == '\0' || !check(keep[fd])))
		return (NULL);
	ret = ft_strjoin(NULL, keep[fd]);
	while (i && check(ret))
	{
		i = zero_read(fd, keep[fd]);
		if (i < 1)
			break ;
		ret = ft_strjoin(ret, keep[fd]);
	}
	next_lines(keep[fd]);
	return (ret);
}
