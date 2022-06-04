/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamellal <mamellal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 11:49:12 by mamellal          #+#    #+#             */
/*   Updated: 2022/05/30 18:33:05 by mamellal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "philo.h"

void	write_die(t_data *vs, int i)
{
	pthread_mutex_lock(&vs->info->thred_mut);
	printf("%ld ms %d is die\n", (g_time() - vs[i].lm), vs[i].ph_id);
}

time_t	g_time(void)
{
	struct timeval	time;
	long long		p;

	gettimeofday(&time, NULL);
	p = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	return (p);
}

void	ft_sleep(long nb)
{
	long long	b;

	b = g_time() + nb;
	while (g_time() < b)
		usleep(100);
}

void	write_msg(t_data *vars, char *msg)
{
	pthread_mutex_lock(&vars->info->thred_mut);
	printf("%ld ms %d %s\n", g_time() - vars->info->ti_start, vars->ph_id, msg);
	pthread_mutex_unlock(&vars->info->thred_mut);
}
