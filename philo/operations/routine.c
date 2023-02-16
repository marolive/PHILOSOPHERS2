/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marolive <marolive@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 12:27:50 by marolive          #+#    #+#             */
/*   Updated: 2023/02/16 09:26:12 by marolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void init(t_data *data, int argc, char **argv)
{
    data->number_of_philos = atoi_ws(argv[1]);
    data->time_to_die = atoi_ws(argv[2]);
    data->time_to_eat = atoi_ws(argv[3]);
    data->time_to_sleep = atoi_ws(argv[4]);
    if(argc == 6)
        data->num_time_eating = atoi_ws(argv[5]);
    else
        data->num_time_eating = -1;
}
void value(t_data *data)
{
    int i;

    i = 0;
    while (i < data->number_of_philos)
    {
        data->ph[i].id = i;
        data->ph[i].name_philo = i + 1;
        data->ph[i].l_fork = i;
        if(i != data->number_of_philos - 1)
            data->ph[i].r_fork = i + 1;
        else
            data->ph[i].r_fork = 0;
        i++;
    }
    data->ph->last_meal = 0;
}

void *routine(void *arg)
{
    t_philo *philo;
    
    philo = arg;
    
}