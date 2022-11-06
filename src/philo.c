/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dilopez- <dilopez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 12:41:20 by dilopez-          #+#    #+#             */
/*   Updated: 2022/09/18 08:34:42 by dilopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

#include <stdlib.h>

int	main(int argc, char *argv[])
{
	if (argc < 5)
	{
		ft_error_args();
		return (1);
	}
	ft_philo(argc, argv);
	return (0);
}

static void	ft_philo(int argc, char *argv[])
{
	t_data	data;
	int		i;

	i = -1;
	ft_get_args(&data, argc, argv);
	if (data.num_philos == 0)
		return ;
	ft_get_philos(&data);
	pthread_mutex_init(&data.print, 0);
	pthread_mutex_init(&data.bifurcation, 0);
	pthread_mutex_lock(&data.bifurcation);
	while (++i < data.num_philos)
	{
		pthread_mutex_lock(&data.print);
		pthread_create(&data.lst_philo->thread, 0, ft_philo_states, &data);
		pthread_detach(data.lst_philo->thread);
		pthread_mutex_lock(&data.print);
		data.lst_philo = data.lst_philo->right;
		pthread_mutex_unlock(&data.print);
	}
	gettimeofday(&data.init_time, NULL);
	pthread_mutex_unlock(&data.bifurcation);
	ft_check_deads_and_eats(&data);
	usleep(data.num_philos * 10);
	ft_exit_program(&data);
}

static void	ft_check_deads_and_eats(t_data *data)
{
	t_data	aux;
	int		num_limit_eats_complete;

	aux = *data;
	num_limit_eats_complete = 0;
	while (1)
	{
		if (aux.lst_philo->limit_eat + (aux.num_philos / 86) < \
			ft_timecomp(aux.init_time))
		{
			pthread_mutex_lock(&data->print);
			printf("%ld %d is died\n", ft_timecomp(aux.init_time) - 1, \
					aux.lst_philo->id);
			break ;
		}
		if (aux.num_limit_eats > -1 && aux.lst_philo->num_eats > \
			aux.num_limit_eats)
			num_limit_eats_complete++;
		if (num_limit_eats_complete == aux.num_philos)
		{
			pthread_mutex_lock(&aux.print);
			break ;
		}
		aux.lst_philo = aux.lst_philo->right;
	}
}

static void	ft_exit_program(t_data *data)
{
	t_philo	*philos;
	t_philo	*aux;

	philos = data->lst_philo;
	(philos->left)->right = 0;
	while (philos != 0)
	{
		aux = philos->right;
		free(philos);
		philos = aux;
	}
}

void	ft_error_args(void)
{
	printf("\n\x1b[31m ========== Error: Invalid arguments ==========\x1b[37m\n\n");
	printf("1. number_of_philosophers\n");
	printf("2. time_to_die\n");
	printf("3. time_to_eat\n");
	printf("4. time_to_sleep\n");
	printf("5. [number_of_times_each_philosopher_must_eat]\n\n");
}
