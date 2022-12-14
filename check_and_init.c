/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_and_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscarama <gscarama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 16:23:57 by gscarama          #+#    #+#             */
/*   Updated: 2022/11/04 12:53:57 by gscarama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_args(t_data *dta, int ac, char **av)
{
	dta->n_philo = ft_atoi(av[1]);
	dta->t_die = ft_atoi(av[2]);
	dta->t_eat = ft_atoi(av[3]);
	dta->t_sleep = ft_atoi(av[4]);
	if (ac == 6)
		dta->musteat = ft_atoi(av[5]);
	else
		dta->musteat = 2147483647;
	if (dta->n_philo < 1 || dta->t_die < 1
		|| dta->t_eat < 1 || dta->t_sleep < 1
		|| dta->musteat < 1)
		return (1);
	return (0);
}

int	check_and_init(t_data *dta, int ac, char **av)
{
	int	row;
	int	read;

	if (ac == 5 || ac == 6)
	{
		read = 1;
		while (read < ac)
		{
			row = 0;
			while (av[read][row])
			{
				if (av[read][row] < 48 || av[read][row] > 57)
				{
					return (ft_error());
				}
				row++;
			}
			read++;
		}
		if (init_args(dta, ac, av))
			return (ft_error());
	}
	else
		return (ft_error());
	return (1);
}

int	create_forks(t_data *dta, int n_philo)
{
	int	row;

	dta->forks = malloc(sizeof(t_mutex) * n_philo);
	if (!dta->forks)
		return (-1);
	row = 0;
	while (row < n_philo)
	{
		if (pthread_mutex_init(&dta->forks[row], NULL))
			return (-1);
		row++;
	}
	return (1);
}

int	create_table(t_data *dta)
{
	int	row;

	dta->philo = malloc(sizeof(t_philo) * dta->n_philo);
	gettimeofday(&dta->t_started, NULL);
	if (!create_forks(dta, dta->n_philo) || !dta->philo)
		return (ft_error());
	if (pthread_create(&dta->th_monitor, NULL, &thread_monitor, dta))
		return (ft_error());
	row = 0;
	dta->run = 1;
	while (row < dta->n_philo)
	{
		if (pthread_create(&dta->philo[row].thread, NULL, &philo,
				&dta->philo[row]))
			return (ft_error());
		dta->philo[row].dta = dta;
		dta->philo[row].pos = row + 1;
		dta->philo[row].eated = 0;
		dta->philo[row].l_fork = &dta->forks[row];
		dta->philo[row].r_fork = &dta->forks[(row + dta->n_philo - 1)
			% dta->n_philo];
		gettimeofday(&dta->philo[row].last_meal, NULL);
		row++;
	}
	return (1);
}

int	ft_error(void)
{
	printf("\n*****Error*****\n");
	printf("Input Order Should be: ./philo {Number of Philosophers} ");
	printf("{Time to Die} {Time to Eat} {Time to Sleep} ");
	printf("{Number of Times Each Philosopher Must Eat}\n");
	printf("The 4 First inputs are madatory\n\n");
	return (0);
}
