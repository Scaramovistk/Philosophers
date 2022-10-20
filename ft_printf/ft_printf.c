/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscarama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 20:13:42 by gscarama          #+#    #+#             */
/*   Updated: 2022/02/18 08:29:45 by gscarama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_printflag(char str, va_list ptr)
{
	int	len;

	len = 1;
	if (str == 'c' || str == 's')
		len = ft_printstr(va_arg(ptr, char *), str);
	else if (str == 'p')
		len = ft_printvoid(va_arg(ptr, unsigned long long));
	else if (str == 'd' || str == 'i')
		len = ft_printnbr(va_arg(ptr, int));
	else if (str == 'u')
		len = ft_printunnbr(va_arg(ptr, unsigned int));
	else if (str == 'x' || str == 'X')
		len = ft_printhex(str, va_arg(ptr, unsigned int));
	else if (str == '%')
		write(1, "%", 1);
	return (len);
}

static char	ft_checkflag(char str)
{
	if (str == 'c' || str == 's' || str == 'p'
		|| str == 'd' || str == 'i' || str == 'u'
		|| str == 'x' || str == 'X' || str == '%')
		return (1);
	else
		return (0);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		len;
	va_list	ptr;

	va_start(ptr, str);
	i = 0;
	len = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			if (!ft_checkflag(str[i + 1]))
				return (len);
			len += ft_printflag(str[i + 1], ptr);
			i += 2;
		}
		else
		{
			ft_putchar_fd(str[i], 1);
			len++;
			i++;
		}
	}
	va_end(ptr);
	return (len);
}
