/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscarama <gscarama@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 20:13:42 by gscarama          #+#    #+#             */
/*   Updated: 2022/01/20 08:29:45 by gscarama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	row;
	size_t	read;

	if (needle[0] == '\0')
		return ((char *)haystack);
	row = 0;
	while (haystack[row] != '\0' && row < len)
	{
		read = 0;
		while ((haystack[row + read] == needle[read]) && (read + row < len))
		{
			if (needle[read + 1] == '\0')
				return ((char *)haystack + row);
		read++;
		}
		row++;
	}
	return (0);
}
