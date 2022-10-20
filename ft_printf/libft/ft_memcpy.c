/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscarama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 23:13:42 by gscarama          #+#    #+#             */
/*   Updated: 2022/01/15 08:29:45 by gscarama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*dst;
	unsigned char	*origin;

	if (dest == NULL && src == NULL)
		return (NULL);
	dst = (unsigned char *)dest;
	origin = (unsigned char *)src;
	i = 0;
	while (n > i)
	{
		dst[i] = origin[i];
		i++;
	}
	return (dest);
}
