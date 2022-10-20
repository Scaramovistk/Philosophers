/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscarama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 23:13:42 by gscarama          #+#    #+#             */
/*   Updated: 2022/01/15 08:29:45 by gscarama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	len;
	size_t	row;

	row = 0;
	len = ft_strlen(src);
	if (size == 0)
		return (len);
	while (row < (size - 1) && src[row])
	{
		dest[row] = src[row];
		row++;
	}
	dest[row] = '\0';
	return (len);
}
