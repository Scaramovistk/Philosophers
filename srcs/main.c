/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscarama <gscarama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 14:50:43 by gscarama          #+#    #+#             */
/*   Updated: 2022/11/02 17:07:46 by gscarama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/philo.h"

void	output(t_data *dta, t_philo *philo, int sig)
{
	int	time;

	time = diff_time(&dta->t_started);
	if (sig == 1)
		printf("%dMs %d has taken a fork\n", time, philo->pos);
	else if (sig == 2)
	{
		printf("%dMs %d is eating\n", time, philo->pos);
		ft_msleep(philo->dta->t_eat);
		gettimeofday(&philo->last_meal, NULL);
		philo->eated++;
	}
	else if (sig == 3)
	{
		printf("%dMs %d is sleeping\n", time, philo->pos);
		ft_msleep(dta->t_sleep);
	}
	else if (sig == 4)
		printf("%dMs %d is thinking\n", time, philo->pos);
	else if (sig == 5)
		printf("%dMs %d died\n", time, philo->pos);
}

void	*philo(void *pt_philo)
{
	t_philo	*philo;

	philo = (t_philo *)pt_philo;
	if (philo->pos % 2 == 0)
		usleep(200);
	while (philo->eated < philo->dta->musteat && philo->dta->run == 1)
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
		gettimeofday(&dta.t_started, NULL);
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
