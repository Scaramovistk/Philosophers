/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscarama <gscarama@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 20:13:42 by gscarama          #+#    #+#             */
/*   Updated: 2022/01/20 08:29:45 by gscarama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_copy(unsigned char *dest, unsigned char *serc, size_t n)
{
	size_t	i;

	i = 0;
	if (dest > serc)
	{
		while (n > 0)
		{
			dest[n - 1] = serc[n - 1];
			n--;
		}
	}
	else
	{
		while (i < n)
		{
			dest[i] = serc[i];
			i++;
		}
	}
}

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char	*dest;
	unsigned char	*serc;

	if (!dst && !src)
		return (NULL);
	dest = (unsigned char *) dst;
	serc = (unsigned char *) src;
	ft_copy(dest, serc, n);
	return (dest);
}
