/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_philos.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dilopez- <dilopez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 16:06:06 by dilopez-          #+#    #+#             */
/*   Updated: 2022/09/03 16:09:27 by dilopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GET_PHILOS_H
# define FT_GET_PHILOS_H

# include "structs.h"

# include <stdlib.h>

static t_philo	*ft_new_philo(int id, t_philo *before, t_data *data);

#endif