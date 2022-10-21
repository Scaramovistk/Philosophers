/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_and_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscarama <gscarama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 16:23:57 by gscarama          #+#    #+#             */
/*   Updated: 2022/10/21 16:33:52 by gscarama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/philo.h"

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
				if (!ft_isdigit(av[read][row]))
				{
					return (ft_error());
				}
				row++;
			}
			read++;
		}
		dta->n_philo = ft_atoi(av[1]);//Number of philosopher
		if (dta->n_philo < 1)
			return (ft_error());
		dta->t_die = ft_atoi(av[2]);//Time to Die
		dta->t_eat = ft_atoi(av[3]);//Time to eat
		dta->t_sleep = ft_atoi(av[4]);//Time to sleep
		if (ac == 6)
			dta->musteat = ft_atoi(av[5]);// Number of times each philosopher must eat
		else
			dta->musteat = 2147483647;
	}
	else
		return (ft_error());
	return (1);
}

int	create_forks(t_mutex *forks, int n_philo)
{
	int	row;

	forks = malloc(sizeof(t_mutex) * n_philo);
	if (forks == NULL)
		return (-1);
	row = 0;
	while (row < n_philo)
	{
		if (pthread_mutex_init(&forks[row], NULL))
			return (-1);
		row++;
	}
	return (1);
}

int	create_table(t_data *dta)
{
	int	row;

	dta->philo = malloc(sizeof(t_philo) * dta->n_philo);
	if (!create_forks(dta->forks, dta->n_philo) || !dta->philo)
		return (ft_error());
	row = 0;
	while (row < dta->n_philo)
	{
		if (pthread_create(&dta->philo[row].thread, NULL, &philo, &dta->philo[row]))
			return (ft_error());
		dta->philo[row].dta = dta;
		dta->philo[row].pos = row + 1;
		dta->philo[row].last_meal = 0;
		dta->philo[row].eated = 0;
		dta->philo[row].l_fork = &dta->forks[row];
		dta->philo[row].r_fork = &dta->forks[(row + dta->n_philo - 1) % dta->n_philo];
		//printf("Philosofer: %i, L_Fork: %i, R_Fork: %i\n", dta->philo[row].pos, row, ((row + dta->n_philo - 1) % dta->n_philo));
		row++;
	}
	return (1);
}

int	ft_error(void)
{
	printf("*****Error*****\n");//Especificar melhor sobre o Input
	printf("Input Order Should be: ./philo {Number of Philosophers} ");
	printf("{Time to Die} {Time to Eat} {Time to Sleep} ");
	printf("{Number of Times Each Philosopher Must Eat}\n");
	printf("The 4 First inputs are madatory\n");
	return (-1);
}
