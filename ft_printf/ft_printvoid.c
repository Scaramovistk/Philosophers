/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printvoid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscarama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 20:13:42 by gscarama          #+#    #+#             */
/*   Updated: 2022/02/18 08:29:45 by gscarama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putptr(unsigned long long nb)
{
	if (nb >= 16)
	{
		ft_putptr(nb / 16);
		nb %= 16;
	}
	if (nb > 9)
		ft_putchar_fd(nb + 87, 1);
	else
		ft_putchar_fd(nb + '0', 1);
}

static int	ft_sizeptr(unsigned long long nbr)
{
	int	size;

	size = 2;
	if (nbr == 0)
		size++;
	while (nbr > 0)
	{
		nbr = nbr / 16;
		size++;
	}
	return (size);
}

int	ft_printvoid(unsigned long long nbr)
{
	ft_putstr_fd("0x", 1);
	if (nbr < 0)
	{
		nbr *= -1;
		ft_putchar_fd('-', 1);
	}
	ft_putptr(nbr);
	return (ft_sizeptr(nbr));
}
