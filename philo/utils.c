/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamellal <mamellal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 18:45:28 by mamellal          #+#    #+#             */
/*   Updated: 2022/06/02 07:52:15 by mamellal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_isalpha(char *ch)
{
	int	i;

	i = 0;
	while (ch[i])
	{
		if ((ch[i] >= 'a' && ch[i] <= 'z') || (ch[i] >= 'A' && ch[i] <= 'Z'))
			return (1);
		i++;
	}
	return (0);
}

int	ft_isascii(char *a)
{
	int	i;

	i = 0;
	if (a[i] == '+')
	{
		i++;
		if (!a[i])
			return (1);
	}
	else if (a[i] == '-')
		return (1);
	while (a[i])
	{
		if (!(a[i] >= 48 && a[i] <= 57))
			return (1);
		i++;
	}
	return (0);
}

int	check_errors(char **av)
{
	int	i;

	i = 1;
	while (av[i])
	{
		if (ft_isalpha(av[i]) || ft_isascii(av[i]))
		{
			write(1, "error\n", 7);
			return (1);
		}
		i++;
	}
	return (0);
}

int	ft_atoi(const char *str)
{
	int					i;
	int					sign;
	unsigned long int	n;

	sign = 1;
	n = 0;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+' )
	{
		if (str[i] == '-')
		sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		n = n * 10 + (str[i] - '0');
			i++;
		if (n >= 9223372036854775807 && sign == 1)
			return (-1);
		if (n > 9223372036854775807 && sign == -1)
			return (0);
	}
	return ((int)(n * sign));
}
