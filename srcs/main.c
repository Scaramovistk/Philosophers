/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscarama <gscarama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 14:50:43 by gscarama          #+#    #+#             */
/*   Updated: 2022/10/21 17:25:13 by gscarama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/philo.h"

void	output(t_data *dta, t_philo *philo, int sig)
{
	int	time; // Stated Time - current time

	time = dta->n_philo;
	if (sig == 1)
		printf("%dMs %d has taken a fork\n", time, philo->pos);
	else if (sig == 2)
	{
		printf("%dMs %d is eating\n", time, philo->pos);
		philo->eated++;
		// Delay dta->t_eat
	}
	else if (sig == 3)
	{
		printf("%dMs %d is sleeping\n", time, philo->pos);
		//Delay dta->t_sleep || Time now + time eating
	}
	else if (sig == 4)
		printf("%dMs %d is thinking\n", time, philo->pos);
	else if (sig == 5)
		printf("%dMs %d died\n", time, philo->pos);
}

void	*philo(void *pt_philo)
{
	t_philo *philo;

	philo = (t_philo *)pt_philo;
	while (philo->dta->musteat > philo->eated)
	{
		int time; // Stated Time - current time
		time = 45;
		pthread_mutex_lock(philo->l_fork);
		output(philo->dta, philo, 1);
		pthread_mutex_lock(philo->r_fork);
		output(philo->dta, philo, 1);
		//Start Eating (Delay)
		output(philo->dta, philo, 2);
		//Finishi eating
		pthread_mutex_unlock(philo->l_fork);
		pthread_mutex_unlock(philo->r_fork);
		//Start Sleeping (Delay)
		output(philo->dta, philo, 3);
		//Start Thinking
		output(philo->dta, philo, 4);
		//??? Check if is Dead ???
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
			pthread_join(dta.philo[row].thread, NULL); //Take output para parar se morrer
			row++;
		}
		//Free Data
		
	}
	return (0);
}
