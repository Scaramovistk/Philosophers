/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscarama <gscarama@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 20:13:42 by gscarama          #+#    #+#             */
/*   Updated: 2022/01/20 08:29:45 by gscarama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*nstr;
	size_t	size;

	if (!s)
		return (0);
	size = 0;
	while (s[start + size] && size < len)
		size++;
	nstr = malloc(sizeof(*nstr) * (size + 1));
	if (!nstr)
		return (NULL);
	if (start > ft_strlen(s))
	{
		ft_memset(nstr, 0, size + 1);
		return (nstr);
	}
	ft_strlcpy(nstr, &s[start], size + 1);
	return (nstr);
}
