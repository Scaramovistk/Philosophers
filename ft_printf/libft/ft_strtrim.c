/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscarama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 20:13:42 by gscarama          #+#    #+#             */
/*   Updated: 2022/01/20 08:29:45 by gscarama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_find(const char *set, char c)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	size_t		size;
	size_t		end;
	int			tmp;
	char		*trimed;

	if (!s1)
		return (NULL);
	tmp = 0;
	while (ft_find(set, s1[tmp]))
		tmp++;
	size = tmp;
	tmp = ft_strlen(s1) - 1;
	while (ft_find(set, s1[tmp]) && tmp > 0)
		tmp--;
	end = tmp + 1;
	if (size >= end)
		end = size;
	trimed = malloc(sizeof(*s1) * (end - size + 1));
	if (!trimed)
		return (NULL);
	if (size < end)
		ft_memcpy(trimed, &s1[size], (end - size));
	trimed[end - size] = '\0';
	return (trimed);
}
