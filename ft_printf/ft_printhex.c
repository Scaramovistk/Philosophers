/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscarama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 20:13:42 by gscarama          #+#    #+#             */
/*   Updated: 2022/02/18 08:29:45 by gscarama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_sizepnbr(unsigned int nbr)
{
	int	size;

	size = -1;
	if (nbr == 0)
		return (0);
	while (nbr > 0)
	{
		nbr = nbr / 16;
		size++;
	}
	return (size);
}

static char	*ft_putbase(unsigned int nbr)
{
	unsigned int	i;
	int				size;
	char			*str;

	size = ft_sizepnbr(nbr);
	str = malloc(sizeof(char) * (size + 1));
	if (str == NULL)
		return (0);
	str[size + 1] = '\0';
	while (size >= 0)
	{
		i = nbr % 16;
		nbr = nbr / 16;
		if (i > 9)
			str[size] = (i + 87);
		else
			str[size] = (i + '0');
		size--;
	}
	return (str);
}

int	ft_printhex(char c, unsigned int nbr)
{
	char	*str;
	int		i;

	i = 0;
	str = ft_putbase(nbr);
	if (str == NULL)
		return (0);
	if (c == 'X')
	{
		while (str[i])
		{
			str[i] = ft_toupper(str[i]);
			i++;
		}
	}
	ft_putstr_fd(str, 1);
	i = ft_strlen(str);
	free(str);
	return (i);
}
