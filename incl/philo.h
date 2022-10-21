/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscarama <gscarama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 14:50:43 by gscarama          #+#    #+#             */
/*   Updated: 2022/10/21 15:13:49 by gscarama         ###   ########.fr       */
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
	int			last_meal;
	int			eated;
	pthread_t	thread;
	t_mutex		*r_fork;
	t_mutex		*l_fork;
	struct s_data	*dta;
}	t_philo;

typedef struct s_data
{
	t_philo	*philo;
	t_mutex	*forks;
	int		n_philo;
	int		t_die;
	int		t_eat;
	int		t_sleep;
	int		t_started;
	int		musteat;
}	t_data;

#endif