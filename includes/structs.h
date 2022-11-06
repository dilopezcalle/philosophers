/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dilopez- <dilopez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 15:45:40 by dilopez-          #+#    #+#             */
/*   Updated: 2022/09/16 09:37:45 by dilopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include <pthread.h>
# include <unistd.h>

typedef struct s_philo
{
	pthread_t		thread;
	int				id;
	int				limit_eat;
	int				num_eats;
	pthread_mutex_t	fork_right;
	struct s_philo	*left;
	struct s_philo	*right;
}					t_philo;

typedef struct s_data
{
	int				num_philos;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				num_limit_eats;
	t_philo			*lst_philo;
	pthread_mutex_t	bifurcation;
	pthread_mutex_t	print;
	struct timeval	init_time;
}					t_data;

#endif