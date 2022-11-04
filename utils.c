/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscarama <gscarama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 16:53:46 by gscarama          #+#    #+#             */
/*   Updated: 2022/11/04 16:02:06 by gscarama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_msleep(long ms)
{
	struct timeval	begin;
	long			res;

	gettimeofday(&begin, NULL);
	res = 0;
	while (res < ms)
	{
		usleep(100);
		res = diff_time(&begin);
	}
}

int	free_threads(t_data *dta)
{
	int	row;

	row = 0;
	while (row < dta->n_philo)
	{
		pthread_mutex_destroy(&dta->forks[row]);
		row++;
	}
	return (0);
}

int	diff_time(struct timeval *begin)
{
	struct timeval	now;
	int				time;

	gettimeofday(&now, NULL);
	time = (now.tv_sec - begin->tv_sec) * 1000
		+ (now.tv_usec - begin->tv_usec) / 1000;
	return (time);
}

int	is_dead(t_data *dta, t_philo *philo)
{
	long	time;

	time = diff_time(&philo->last_meal);
	if (time >= dta->t_die)
	{
		output(dta, philo, 5);
		philo->eated = dta->musteat + 1;
		return (1);
	}
	return (0);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	len;
	int	nb;

	nb = 0;
	len = 0;
	i = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb + str[i] - '0';
		if (str[i + 1] >= '0' && str[i + 1] <= '9')
			nb *= 10;
		if (len > 10 || nb > 2147483647)
			return (-1);
		len++;
		i++;
	}
	return (nb);
}
