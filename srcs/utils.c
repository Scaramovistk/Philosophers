/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscarama <gscarama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 16:53:46 by gscarama          #+#    #+#             */
/*   Updated: 2022/11/02 17:09:09 by gscarama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/philo.h"

int	diff_time(struct timeval *begin)
{
	struct timeval	now;
	int				time;

	gettimeofday(&now, NULL);
	time = (now.tv_sec - begin->tv_sec) * 1000
		+ (now.tv_usec - begin->tv_usec) / 1000;
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
		res = diff_time(&begin);
	}
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

void	*thread_monitor(void *p_dta)
{
	int		row;
	t_data	*dta;

	dta = (t_data *)p_dta;
	ft_msleep(2);
	while (1)
	{
		row = 0;
		while (row < dta->n_philo)
		{
			if (is_dead(dta, &dta->philo[row])
				|| dta->philo[row].eated >= dta->musteat)
			{
				dta->run = 0;
				free_threads(dta);
				return ((void *)0);
			}
			row++;
		}
		usleep(500);
	}
}
