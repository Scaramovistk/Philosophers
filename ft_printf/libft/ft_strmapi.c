/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscarama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 20:13:42 by gscarama          #+#    #+#             */
/*   Updated: 2022/01/20 08:29:45 by gscarama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	row;
	char			*nstr;

	if (!s || !f)
		return (NULL);
	nstr = malloc(sizeof(char) * ft_strlen(s) + 1);
	if (!(nstr))
		return (NULL);
	row = 0;
	while (s[row])
	{
		nstr[row] = f(row, s[row]);
		row++;
	}
	nstr[row] = '\0';
	return (nstr);
}
