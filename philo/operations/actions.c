/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marolive <marolive@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 08:01:14 by marolive          #+#    #+#             */
/*   Updated: 2023/02/16 10:23:26 by marolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void sleeping(t_data *data)
{
    print_act(data, "Durminu!");
    usleep(data->time_to_sleep * 1000);
}

void thinking(t_data *data)
{
    print_act(data, "Pensanu!");
}

void eating(t_data *data)
{
    t_philo *philo;
    
    pthread_mutex_lock(&data->mutex_fork[philo->l_fork]);
    pthread_mutex_lock(&data->mutex_fork[philo->r_fork]);
    
    
    
}
