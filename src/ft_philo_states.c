/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_states.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dilopez- <dilopez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 08:47:47 by dilopez-          #+#    #+#             */
/*   Updated: 2022/09/18 08:22:32 by dilopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo_states.h"

void	*ft_philo_states(void *param)
{
	t_data	*data;
	t_philo	*philo;

	data = (t_data *)param;
	philo = data->lst_philo;
	pthread_mutex_unlock(&data->print);
	pthread_mutex_lock(&data->bifurcation);
	philo->limit_eat = ft_timecomp(data->init_time) + data->time_die;
	pthread_mutex_unlock(&data->bifurcation);
	if (philo->id % 2)
		ft_msleep(data->time_eat - 20, data->num_philos);
	while (1)
	{
		ft_philo_eating(data, philo);
		pthread_mutex_lock(&data->print);
		printf("%ld %d is sleeping\n", ft_timecomp(data->init_time), philo->id);
		pthread_mutex_unlock(&data->print);
		ft_msleep(data->time_sleep, data->num_philos);
		pthread_mutex_lock(&data->print);
		printf("%ld %d is thinking\n", ft_timecomp(data->init_time), philo->id);
		pthread_mutex_unlock(&data->print);
		ft_msleep((data->time_die - data->time_eat - data->time_sleep) / 4, \
					data->num_philos);
	}
	return (0);
}

static void	ft_philo_eating(t_data *data, t_philo *philo)
{
	pthread_mutex_lock(&philo->left->fork_right);
	pthread_mutex_lock(&data->print);
	printf("%ld %d has taken a fork\n", ft_timecomp(data->init_time), philo->id);
	pthread_mutex_unlock(&data->print);
	pthread_mutex_lock(&philo->fork_right);
	pthread_mutex_lock(&data->print);
	printf("%ld %d has taken a fork\n", ft_timecomp(data->init_time), philo->id);
	pthread_mutex_unlock(&data->print);
	pthread_mutex_lock(&data->print);
	printf("%ld %d is eating\n", ft_timecomp(data->init_time), philo->id);
	philo->limit_eat = ft_timecomp(data->init_time) + data->time_die;
	philo->num_eats++;
	pthread_mutex_unlock(&data->print);
	ft_msleep(data->time_eat, data->num_philos);
	pthread_mutex_unlock(&philo->left->fork_right);
	pthread_mutex_unlock(&philo->fork_right);
}
