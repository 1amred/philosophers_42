/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamellal <mamellal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 11:49:26 by mamellal          #+#    #+#             */
/*   Updated: 2022/05/31 13:35:16 by mamellal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	fct_die(t_data *vs)
{
	int		i;

	while (1)
	{
		i = -1;
		while (++i < vs->info->num_of_philo)
		{
			pthread_mutex_lock(&vs->info->param_mutexes);
			if (g_time() - vs[i].lm >= vs->info->time_to_die)
			{
				write_die(vs, i);
				return (1);
			}
			pthread_mutex_unlock(&vs->info->param_mutexes);
		}
		i = -1;
		pthread_mutex_lock(&vs->info->param_mutexes);
		while (++i < vs->info->num_of_philo)
			if (vs[i].number_of_eat != vs->info->noft_e_philo_must_eat)
				break ;
		pthread_mutex_unlock(&vs->info->param_mutexes);
		if (i == vs->info->num_of_philo)
			break ;
	}
	return (1);
}

void	sleeping(t_data *vs)
{
	pthread_mutex_lock(&vs->info->thred_mut);
	printf("%ld ms %d sleeping\n", (g_time() - vs->info->ti_start), vs->ph_id);
	pthread_mutex_unlock(&vs->info->thred_mut);
	ft_sleep(vs->info->time_to_sleep);
}

void	thinking(t_data *vs)
{
	pthread_mutex_lock(&vs->info->thred_mut);
	printf("%ld ms %d thinking\n", (g_time() - vs->info->ti_start), vs->ph_id);
	pthread_mutex_unlock(&vs->info->thred_mut);
}

void	eat(t_data *vars)
{
	pthread_mutex_lock(vars->right_fork);
	write_msg(vars, "has taken a right fork");
	pthread_mutex_lock(vars->left_fork);
	write_msg(vars, "has taken a left fork");
	write_msg(vars, "is eating");
	pthread_mutex_lock(&vars->info->param_mutexes);
	vars->lm = g_time();
	vars->number_of_eat++;
	pthread_mutex_unlock(&vars->info->param_mutexes);
	ft_sleep(vars->info->time_to_eat);
	pthread_mutex_unlock(vars->right_fork);
	pthread_mutex_unlock(vars->left_fork);
}

void	init_forks(t_data *philos, pthread_mutex_t *forks, int size)
{
	int	i;
	int	k;

	i = 0;
	while (i < size)
	{
		pthread_mutex_init(&forks[i], NULL);
		i++;
	}
	i = 0;
	while (i < size)
	{
		philos[i].left_fork = &forks[i];
		k = (i + 1) % size;
		philos[i].right_fork = &forks[k];
		i++;
	}
}
