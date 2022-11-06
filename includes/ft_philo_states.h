/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_states.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dilopez- <dilopez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 16:10:16 by dilopez-          #+#    #+#             */
/*   Updated: 2022/09/17 11:30:54 by dilopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PHILO_STATES_H
# define FT_PHILO_STATES_H

# include "structs.h"

# include <pthread.h>
# include <stdio.h>

static void	ft_philo_eating(t_data *data, t_philo *philo);

int			ft_msleep(long milisecons, int num_philos);
long		ft_timecomp(struct timeval timer);

#endif