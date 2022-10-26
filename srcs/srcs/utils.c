/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscarama <gscarama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 16:53:46 by gscarama          #+#    #+#             */
/*   Updated: 2022/10/26 16:51:24 by gscarama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/philo.h"

int	diff_time(struct timeval begin)
{
	struct timeval	now;
	int				time;

	gettimeofday(&now, NULL);
	time = (now.tv_sec - begin.tv_sec) * 1000
			+ (now.tv_usec - begin.tv_usec) / 1000;
	return (time);
}

void	ft_msleep(long ms)
{
	struct timeval	begin;
	long			res;

	gettimeofday(&begin, NULL);
	res = 0;
	while (res < ms)
	{
		usleep(800);
		res = diff_time(begin);
	}
}
