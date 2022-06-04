/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamellal <mamellal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 20:10:52 by mamellal          #+#    #+#             */
/*   Updated: 2022/05/31 12:40:28 by mamellal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include<pthread.h>
# include<sys/time.h>
# include<unistd.h>
# include<stdio.h>
# include<string.h>
# include<stdlib.h>
# include <limits.h>

typedef struct s_data // one time
{
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*left_fork;
	long			lm;
	int				ph_id;
	struct s_philo	*info;
	int				number_of_eat;
}	t_data;

typedef struct s_philo
{
	pthread_mutex_t	thred_mut;
	pthread_mutex_t	*last_meals;
	pthread_mutex_t	param_mutexes;
	int				num_of_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				noft_e_philo_must_eat;
	time_t			ti_start;
	t_data			*data;
	pthread_t		*thread;
}	t_philo;

int		ft_atoi(const char *str);
time_t	g_time(void);
int		wait_fct(t_data *vars);
void	ft_sleep(long nb);
void	write_msg(t_data *philo, char *msg);
int		fct_die(t_data *vars);
void	init_forks(t_data *philos, pthread_mutex_t *forks, int size);
void	sleeping(t_data *ok);
void	eat(t_data *ok);
int		check_errors(char **av);
void	thinking(t_data *ok);
void	write_die(t_data *vs, int i);
#endif