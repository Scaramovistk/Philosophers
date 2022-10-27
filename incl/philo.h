/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscarama <gscarama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 14:50:43 by gscarama          #+#    #+#             */
/*   Updated: 2022/10/27 15:35:03 by gscarama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
#define PHILO_H

#include "../ft_printf/ft_printf.h"
#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/time.h>

typedef pthread_mutex_t t_mutex;

typedef struct s_philo
{
	int			pos;
	int			eated;
	pthread_t	thread;
	t_mutex		*r_fork;
	t_mutex		*l_fork;
	struct s_data	*dta;
	struct timeval	last_meal;
	//unsigned long last_meal;
}	t_philo;

typedef struct s_data
{
	t_philo	*philo;
	t_mutex	*forks;
	int		n_philo;
	int		t_die;
	int		t_eat;
	int		t_sleep;
	int		musteat;
	struct timeval	t_started;
}	t_data;

int		create_table(t_data *dta);
int		check_and_init(t_data *dta, int ac, char **av);

void	ft_msleep(long ms);
int		diff_time(struct timeval *begin);

int		is_dead(t_data *dta, t_philo *philo);
void	output(t_data *dta, t_philo *philo, int sig);
void	*philo(void *pt_philo);

int		ft_error(void);

#endif