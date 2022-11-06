/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_philos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dilopez- <dilopez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 18:03:00 by dilopez-          #+#    #+#             */
/*   Updated: 2022/09/17 11:10:52 by dilopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_get_philos.h"

static t_philo	*ft_new_philo(int id, t_philo *before, t_data *data);

void	ft_get_philos(t_data *data)
{
	int		i;
	t_philo	*new;
	t_philo	*aux;

	data->lst_philo = 0;
	aux = 0;
	i = 1;
	while (i <= data->num_philos)
	{
		new = ft_new_philo(i, aux, data);
		if (!aux)
		{
			aux = new;
			data->lst_philo = aux;
		}
		else
		{
			aux->right = new;
			aux = aux->right;
		}
		i++;
	}
	aux->right = data->lst_philo;
	(data->lst_philo)->left = aux;
}

static t_philo	*ft_new_philo(int id, t_philo *before, t_data *data)
{
	t_philo	*new;

	new = (t_philo *)malloc(1 * sizeof(t_philo));
	new->id = id;
	pthread_mutex_init(&new->fork_right, 0);
	new->left = before;
	new->right = 0;
	new->num_eats = 0;
	new->limit_eat = data->time_die;
	return (new);
}
