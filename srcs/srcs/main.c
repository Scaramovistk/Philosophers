/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscarama <gscarama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 14:50:43 by gscarama          #+#    #+#             */
/*   Updated: 2022/10/26 17:49:08 by gscarama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/philo.h"

void	output(t_data *dta, t_philo *philo, int sig)
{
	int		time;

	time = diff_time(dta->t_started);
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
		ft_msleep(philo->dta->t_sleep);
	}
	else if (sig == 4)
		printf("%dMs %d is thinking\n", time, philo->pos);
	else if (sig == 5)
		printf("%dMs %d died\n", time, philo->pos);
}

int	is_dead(t_data *dta, t_philo *philo)
{
	int	time;

	time = diff_time(dta->philo->last_meal);
	if (time >= dta->t_die)
	{
		output(dta, philo, 5);
		return (0);
	}
	return (1);
}

void	*philo(void *pt_philo)
{
	t_philo *philo;

	philo = (t_philo *)pt_philo;
	if (philo->pos % 2 == 0)
		usleep(200);
	while (philo->eated < philo->dta->musteat
		&& is_dead(philo->dta, philo)) // Find best solution if they die
	{
		pthread_mutex_lock(philo->l_fork);
		output(philo->dta, philo, 1);

		pthread_mutex_lock(philo->r_fork);
		output(philo->dta, philo, 1);

		gettimeofday(&philo->last_meal, NULL);
		output(philo->dta, philo, 2);

		pthread_mutex_unlock(philo->l_fork);
		pthread_mutex_unlock(philo->r_fork);
		
		output(philo->dta, philo, 3);

		output(philo->dta, philo, 4);
	}
	return ((void *)-1);
}

void	thread_monitor(t_data *dta)
{
	int	row;

	while (1)
	{
		usleep(200);
		row = 0;
		while (row < dta->n_philo)
		{
			if (is_dead(dta, &dta->philo[row])
			|| dta->philo[row].eated >= dta->musteat)
				return ;
			row++;
		}
	}
}

void	free_threads(t_data *dta)
{
	int	row;
	row = 0;
	while (row < dta->n_philo)
	{
		pthread_mutex_destroy(&dta->forks[row]);
		row++;
	}
	free(dta->philo);
	free(dta->forks);
	// free(dta->n_philo);
	// free(dta->t_die);
	// free(dta->t_eat);
	// free(dta->t_sleep);
}

int	main(int ac, char **av)
{
	t_data	dta;
	int	row;

	if (check_and_init(&dta, ac, av) && create_table(&dta))
	{
		row = 0;
		//thread_monitor(&dta);
		while (row < dta.n_philo)
		{
			gettimeofday(&dta.t_started, NULL);
			pthread_join(dta.philo[row].thread, NULL); //Take output para parar se morrer
			row++;
		}

		//Free Data

	}
	return (0);
}
