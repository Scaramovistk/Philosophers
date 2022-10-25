/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscarama <gscarama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 14:50:43 by gscarama          #+#    #+#             */
/*   Updated: 2022/10/25 18:28:06 by gscarama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/philo.h"

void	output(t_data *dta, t_philo *philo, int sig)
{
	int		time;
	struct	timeval now;

	gettimeofday(&now, NULL);
	time = (now.tv_sec - dta->t_started.tv_sec) * 1000
			+ (now.tv_usec - dta->t_started.tv_usec) / 1000;
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

void	is_dead(t_data *dta, t_philo *philo)
{
	int	time;
	struct	timeval now;

	gettimeofday(&now, NULL);
	time = (now.tv_sec - dta->philo->last_meal.tv_sec) * 1000
			+ (now.tv_usec - dta->philo->last_meal.tv_usec) / 1000;
	if (time >= dta->t_die)
	{
		output(dta, philo, 5);
		exit(-1); //Properly Exit
	}
}

void	*philo(void *pt_philo)
{
	t_philo *philo;

	philo = (t_philo *)pt_philo;
	while (philo->dta->musteat > philo->eated)
	{
		is_dead(philo->dta, philo);
		if (philo->pos % 2 == 0)
			usleep(200); //Not a good solution

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
		
		is_dead(philo->dta, philo); //??? Check if is Dead ???
	}
	return ((void *)-1);
}

int	main(int ac, char **av)
{
	t_data	dta;

	if (check_and_init(&dta, ac, av) && create_table(&dta))
	{
		int	row;

		row = 0;
		while (row < dta.n_philo)
		{//Seg Fault
			gettimeofday(&dta.t_started, NULL);
			pthread_join(dta.philo[row].thread, NULL); //Take output para parar se morrer
			row++;
		}
		//Free Data
		
	}
	return (0);
}
