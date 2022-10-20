/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscarama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 20:13:42 by gscarama          #+#    #+#             */
/*   Updated: 2022/01/18 08:29:45 by gscarama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_error(int neg)
{
	if (neg > 0)
		return (-1);
	return (0);
}

static int	ft_ngspace(const char *str)
{
	int	i;

	i = 0;
	while (str[i] == '\t' || str[i] == '\v' || str[i] == '\n'
		|| str[i] == '\r' || str[i] == '\f' || str[i] == ' ')
		i++;
	if (str[i] == '-')
	{
		i++;
		i *= (-1);
	}
	else if (str[i] == '+')
		i++;
	return (i);
}

int	ft_atoi(const char *str)
{
	int		neg;
	int		i;
	int		len;
	size_t	nb;

	neg = 1;
	nb = 0;
	len = 0;
	i = ft_ngspace(str);
	if (i < 0)
	{
		neg *= -1;
		i *= -1;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb + str[i] - '0';
		if (str[i + 1] >= '0' && str[i + 1] <= '9')
			nb *= 10;
		if (len > 19)
			return (ft_error(neg));
		len++;
		i++;
	}
	return ((int)((nb) * (neg)));
}
