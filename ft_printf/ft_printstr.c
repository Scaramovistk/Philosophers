/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscarama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 20:13:42 by gscarama          #+#    #+#             */
/*   Updated: 2022/02/18 08:29:45 by gscarama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printstr(char *str, char c)
{
	if (c == 'c')
	{
		write(1, &str, 1);
		return (1);
	}
	else
	{
		if (!str)
		{
			ft_putstr_fd("(null)", 1);
			return (6);
		}
		ft_putstr_fd(str, 1);
		return (ft_strlen(str));
	}
}
