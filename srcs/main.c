/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscarama <gscarama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 14:50:43 by gscarama          #+#    #+#             */
/*   Updated: 2022/10/21 15:29:48 by gscarama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/philo.h"

int	ft_error(void)
{
	printf("*****Error*****\n");
	printf("Input Order Should be: ./philo {Number of Philosophers} ");
	printf("{Time to Die} {Time to Eat} {Time to Sleep} ");
	printf("{Number of Times Each Philosopher Must Eat}\n");
	printf("The 4 First inputs are madatory\n");
	return (-1);
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
	//Initi Philo
	t_philo *philo;

	philo = (t_philo *)pt_philo;
	while (philo->dta->musteat > philo->eated) //Must eat < eated
	{
		int time; // Stated Time - current time
		time = 45;
		pthread_mutex_lock(philo->l_fork);
		output(philo->dta, philo, 1);
		pthread_mutex_lock(philo->r_fork);
		output(philo->dta, philo, 1);
		//Start Eating
		output(philo->dta, philo, 2);
		//Finishi eating
		pthread_mutex_unlock(philo->l_fork);
		pthread_mutex_unlock(philo->r_fork);
		//Start Sleeping (Delay)
		//Start Thinking
		//??? Check if is Dead ???
	}
	return ((void *)1);
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
				//Ver se nao tem caracteres nao numericos
				if (!ft_isdigit(av[read][row]))
				{
					return (ft_error());
				}
				row++;
			}
			read++;
		}
		dta->n_philo = ft_atoi(av[1]);//Number of philosopher
		if (dta->n_philo == 1)
		{
			//Codigo Especial
		}
		dta->t_die = ft_atoi(av[2]);//Time to Die
		dta->t_eat = ft_atoi(av[3]);//Time to eat
		dta->t_sleep = ft_atoi(av[4]);//Time to sleep
		//Condicao especial
		if (ac == 6)
			dta->musteat = ft_atoi(av[5]);// Number of times each philosopher must eat
		else
			dta->musteat = 2147483647;
	}
	else
		return (ft_error());
	return (1);
}

int	main(int ac, char **av)
{
	t_data	dta;

	//Check All args se estao dentro do esperado
	if (check_and_init(&dta, ac, av) && create_table(&dta))
	{
		int	row;

		row = 0;
		while (row < dta.n_philo)
		{
			//pthread_join(dta.philo[row].thread, NULL);
			row++;
		}
		//Free Data
		
	}
	return (0);
}