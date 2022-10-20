/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscarama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 23:13:42 by gscarama          #+#    #+#             */
/*   Updated: 2022/01/20 08:29:45 by gscarama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_size(int n)
{
	int				size;
	unsigned int	nb;

	nb = n;
	size = 1;
	if (n < 0)
	{
		nb = n * -1;
		size++;
	}
	else
		nb = n;
	while (nb >= 10)
	{
		nb /= 10;
		size++;
	}
	return (size);
}

static void	ft_convnbr(char *str, int size, unsigned int n)
{
	while (n != 0)
	{
		str[size - 1] = (n % 10) + '0';
		n /= 10;
		size--;
	}
}

char	*ft_itoa(int n)
{
	int				size;
	char			*str;
	unsigned int	nb;

	size = ft_size(n);
	nb = n;
	str = malloc(sizeof(char) * (size + 1));
	if (str == NULL)
		return (0);
	str[size] = '\0';
	if (n == 0)
	{
		str[0] = '0';
		return (str);
	}
	if (n < 0)
	{
		str[0] = '-';
		nb *= -1;
	}
	ft_convnbr(str, size, nb);
	return (str);
}
