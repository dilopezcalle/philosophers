/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dilopez- <dilopez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 16:39:03 by dilopez-          #+#    #+#             */
/*   Updated: 2022/09/15 14:04:12 by dilopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_get_args.h"

void	ft_get_args(t_data *data, int argc, char *argv[])
{
	if (ft_atoi(argv[1]) < 0 || ft_atoi(argv[2]) < 0 || ft_atoi(argv[3]) < 0 \
		|| ft_atoi(argv[4]) < 0 || (argc == 6 && ft_atoi(argv[5]) < 0))
	{
		data->num_philos = 0;
		ft_error_args();
		return ;
	}
	data->num_philos = ft_atoi(argv[1]);
	data->time_die = ft_atoi(argv[2]);
	data->time_eat = ft_atoi(argv[3]);
	data->time_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		data->num_limit_eats = ft_atoi(argv[5]);
	else
		data->num_limit_eats = -1;
}

static int	ft_atoi(const char *str)
{
	int	negative;
	int	number;
	int	i;

	negative = 0;
	number = 0;
	i = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\f' || str[i] == '\r'
		|| str[i] == '\v' || str[i] == ' ')
		i++;
	if (str[i] == '-')
		negative = 1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while ((int)str[i] >= '0' && (int)str[i] <= '9')
	{
		number = number * 10;
		number += str[i] - '0';
		i++;
	}
	if (negative == 1)
		number = -number;
	return (number);
}
