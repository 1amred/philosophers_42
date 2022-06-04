/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamellal <mamellal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 20:05:52 by mamellal          #+#    #+#             */
/*   Updated: 2022/05/31 12:57:58 by mamellal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philo.h"

void	*fct_r(void *philo)
{
	t_data	*vars;
	int		i;

	i = 0;
	vars = (t_data *)philo;
	if (vars->ph_id % 2 == 0)
		usleep(100);
	while (1)
	{
		eat(vars);
		if (vars->number_of_eat == vars->info->noft_e_philo_must_eat)
			break ;
		sleeping(vars);
		thinking(vars);
	}
	return (0);
}

void	create_threads(t_philo *ph)
{
	int	i;

	i = -1;
	ph->ti_start = g_time();
	while (++i < ph->num_of_philo)
	{
		ph->data[i].number_of_eat = 0;
		ph->data[i].ph_id = i + 1;
		ph->data[i].info = ph;
		ph->data[i].lm = g_time();
		if (pthread_create(&(ph->thread[i]), NULL, &fct_r, &(ph->data[i])) != 0)
		{
			printf("failed1\n");
			return ;
		}
	}
	if (fct_die(ph->data))
		return ;
}

int	get_args(t_philo *philo, char **av, int ac)
{
	philo->num_of_philo = ft_atoi(av[1]);
	if (philo->num_of_philo == 0)
		return (1);
	philo->time_to_die = ft_atoi(av[2]);
	philo->time_to_eat = ft_atoi(av[3]);
	philo->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		philo->noft_e_philo_must_eat = ft_atoi(av[5]);
	else
		philo->noft_e_philo_must_eat = -1;
	return (0);
}

int	main(int ac, char **av)
{
	int				i;
	t_philo			*philo;
	pthread_mutex_t	*forks;

	if (ac < 5 || ac > 6)
		return (0);
	if (check_errors(av))
		return (0);
	philo = malloc(sizeof(t_philo));
	if (get_args(philo, av, ac))
		return (0);
	philo->data = malloc(sizeof(t_data) * philo->num_of_philo);
	philo->thread = malloc(sizeof(pthread_t) * philo->num_of_philo);
	pthread_mutex_init(&philo->thred_mut, NULL);
	i = -1;
	pthread_mutex_init(&philo->param_mutexes, NULL);
	forks = malloc(sizeof(*forks) * philo->num_of_philo);
	init_forks(philo->data, forks, philo->num_of_philo);
	create_threads(philo);
}
