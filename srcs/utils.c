/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscarama <gscarama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 16:53:46 by gscarama          #+#    #+#             */
/*   Updated: 2022/10/22 17:10:01 by gscarama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/philo.h"

void	ft_msleep(long ms)
{
	struct timeval head;
	struct timeval row;
	long	res;

	gettimeofday(&head, NULL);
	res = 0;
	while (res < ms)
	{
		usleep(800);
		gettimeofday(&row, NULL);
		res = (row.tv_sec - head.tv_sec) * 1000
			+ (row.tv_usec - head.tv_usec) / 1000;
	}
}
