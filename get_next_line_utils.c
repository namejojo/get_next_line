// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   get_next_line_utils.c                              :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: jlima-so <jlima-so@student.42.fr>          +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2025/04/07 14:18:56 by jlima-so          #+#    #+#             */
// /*   Updated: 2025/04/07 15:33:51 by jlima-so         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "get_next_line.h"

// unsigned int	ft_strlen(char *s)
// {
// 	int	ind;

// 	ind = 0;
// 	while (s[ind])
// 		ind++;
// 	return (ind);
// }

// char	*ft_strcpy(char *dest, char *src)
// {
// 	int	ind;

// 	ind = 0;
// 	while (src[ind] != '\0')
// 	{
// 		dest[ind] = src[ind];
// 		ind++;
// 	}
// 	dest[ind] = '\0';
// 	return (dest);
// }

// char	*ft_strcpy_to_line(char *dest, char *src)
// {
// 	int	ind;

// 	ind = 0;
// 	while (src[ind] != '\0' && src[ind - 1] != '\n')
// 	{
// 		dest[ind] = src[ind];
// 		ind++;
// 	}
// 	dest[ind] = '\0';
// 	return (dest);
// }

// char	*ft_strcat_to_line(char *dest, char *src)
// {
// 	int	ind;
// 	int	ind2;

// 	ind = 0;
// 	ind2 = ft_strlen(dest);
// 	while (src[ind] != '\0' && src[ind] != '\n')
// 	{
// 		dest[ind2] = src[ind];
// 		ind++;
// 		ind2++;
// 	}
// 	if (src[ind] == '\n')
// 	{
// 		dest[ind2] = '\n';
// 		dest[ind2 + 1] = '\0';
// 	}
// 	else
// 		dest[ind2] = '\0';
// 	return (dest);
// }
