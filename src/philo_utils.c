/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dilopez- <dilopez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 13:00:35 by dilopez-          #+#    #+#             */
/*   Updated: 2022/09/18 07:55:13 by dilopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_utils.h"

int	ft_msleep(long milisecons, int num_philos)
{
	struct timeval	timer;

	gettimeofday(&timer, NULL);
	while (milisecons > ft_timecomp(timer))
		usleep(2 * num_philos);
	return (0);
}

long	ft_timecomp(struct timeval timer)
{
	struct timeval	tp;
	long			result;

	gettimeofday(&tp, NULL);
	result = (tp.tv_sec * 1000) + (tp.tv_usec / 1000);
	result -= (timer.tv_sec * 1000) + (timer.tv_usec / 1000);
	return (result);
}
