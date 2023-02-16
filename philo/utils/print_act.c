/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_act.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marolive <marolive@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 16:53:44 by marolive          #+#    #+#             */
/*   Updated: 2023/02/16 08:09:07 by marolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void print_act(t_data *data, char *str)
{
    pthread_mutex_lock(&data->mutex_print);
    printf("%ld, %d, %s\n", get_time(), data->ph->name_philo, str);
    pthread_mutex_unlock(&data->mutex_print);
}