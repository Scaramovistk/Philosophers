/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscarama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 20:13:42 by gscarama          #+#    #+#             */
/*   Updated: 2022/02/18 08:29:45 by gscarama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_sizenbr(unsigned int nbr)
{
	int	size;

	size = 0;
	while (nbr > 0)
	{
		nbr = nbr / 10;
		size++;
	}
	return (size);
}

int	ft_printnbr(int nbr)
{
	int	size;

	size = 0;
	ft_putnbr_fd(nbr, 1);
	if (nbr <= 0)
	{
		nbr *= -1;
		size++;
	}
	size += ft_sizenbr(nbr);
	return (size);
}
