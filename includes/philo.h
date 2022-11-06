/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dilopez- <dilopez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 13:00:12 by dilopez-          #+#    #+#             */
/*   Updated: 2022/09/15 14:05:24 by dilopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "structs.h"

# include <sys/time.h>
# include <string.h>
# include <stdio.h>

static void	ft_exit_program(t_data *data);
static void	ft_philo(int argc, char *argv[]);
static void	ft_check_deads_and_eats(t_data *data);

void		ft_get_args(t_data *data, int argc, char *argv[]);
long		ft_timecomp(struct timeval timer);
void		*ft_philo_states(void *param);
void		ft_get_philos(t_data *data);
void		ft_error_args(void);

#endif