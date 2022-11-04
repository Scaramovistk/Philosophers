/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscarama <gscarama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 14:50:43 by gscarama          #+#    #+#             */
/*   Updated: 2022/11/04 13:25:35 by gscarama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*thread_monitor(void *p_dta)
{
	int		row;
	int		eated;
	t_data	*dta;

	dta = (t_data *)p_dta;
	ft_msleep(dta->t_die * 0.9);
	while (1)
	{
		row = 0;
		eated = 0;
		while (row < dta->n_philo)
		{
			if (dta->philo[row].eated >= dta->musteat)
				eated++;
			if (is_dead(dta, &dta->philo[row])
				|| eated == dta->n_philo)
			{
				dta->run = 0;
				free_threads(dta);
				return ((void *)0);
			}
			row++;
		}
		usleep(200);
	}
}

void	output(t_data *dta, t_philo *philo, int sig)
{
	int	time;

	time = diff_time(&dta->t_started);
	if (sig == 1)
		printf("%d %d has taken a fork\n", time, philo->pos);
	else if (sig == 2)
	{
		printf("%d %d is eating\n", time, philo->pos);
		gettimeofday(&philo->last_meal, NULL);
		philo->eated++;
		ft_msleep(philo->dta->t_eat);
	}
	else if (sig == 3)
	{
		printf("%d %d is sleeping\n", time, philo->pos);
		ft_msleep(dta->t_sleep);
	}
	else if (sig == 4)
		printf("%d %d is thinking\n", time, philo->pos);
	else if (sig == 5)
		printf("%d %d died\n", time, philo->pos);
}

void	*philo(void *pt_philo)
{
	t_philo	*philo;

	philo = (t_philo *)pt_philo;
	if (philo->pos % 2 == 0)
		usleep(200);
	while (philo->dta->run == 1)
	{
		pthread_mutex_lock(philo->l_fork);
		output(philo->dta, philo, 1);
		pthread_mutex_lock(philo->r_fork);
		output(philo->dta, philo, 1);
		output(philo->dta, philo, 2);
		pthread_mutex_unlock(philo->l_fork);
		pthread_mutex_unlock(philo->r_fork);
		output(philo->dta, philo, 3);
		output(philo->dta, philo, 4);
	}
	return ((void *)-1);
}

int	main(int ac, char **av)
{
	t_data	dta;
	int		row;

	if (check_and_init(&dta, ac, av) && create_table(&dta))
	{
		row = 0;
		pthread_join(dta.th_monitor, NULL);
		while (row < dta.n_philo && dta.run == 1)
		{
			pthread_join(dta.philo[row].thread, NULL);
			row++;
		}
		free_threads(&dta);
	}
	return (0);
}
