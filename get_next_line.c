/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlima-so <jlima-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 16:13:13 by jlima-so          #+#    #+#             */
/*   Updated: 2025/04/09 17:38:17 by jlima-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>




char	*get_next_line(int fd)
{
	static char	keep[BUFFER_SIZE + 1];
	char		*ret;
	int			i;

	if (read(fd, &i, 0) == -1)
		return (NULL);
	i = 1;
	if (*keep == '\0')
	{
		ft_bzero(keep, BUFFER_SIZE + 1);
		i = read (fd, keep, BUFFER_SIZE);
	}
	if (i < 1 && (*keep == '\0' || !check(keep)))
		return (NULL);
	ret = ft_strjoin(NULL, keep);
	while (i && check(ret))
	{
		ft_bzero(keep, BUFFER_SIZE + 1);
		i = read (fd, keep, BUFFER_SIZE);
		if (i < 1)
			break ;
		ret = ft_strjoin(ret, keep);
	}
	next_lines(keep);
	return (ret);
}
