/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initial.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marolive <marolive@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 18:18:43 by marolive          #+#    #+#             */
/*   Updated: 2023/03/03 17:01:47 by marolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void arg_value(t_data *data, int argc, char **argv)
{
    int i = atoi_ws(argv[1] -1);
    pthread_mutex_init(&data->mutex_print, NULL);
    data->number_of_philos = atoi_ws(argv[1]);
    data->time_to_die = atoi_ws(argv[2]);
    data->time_to_eat = atoi_ws(argv[3]);
    data->time_to_sleep = atoi_ws(argv[4]);
    if(argc == 6)
        data->num_time_eating = atoi_ws(argv[5]);
    else
        data->num_time_eating = -1;
    while (i > 0)
    {
        pthread_mutex_init(&data->ph->mutex_fork[i--], NULL);
    }
}

void phi_value(t_data *data)
{
    int i;

    i = 0;
    while (i < data->number_of_philos)
    {
        usleep(200);
        data->ph[i].id = i;
        data->ph[i].index_philo = i + 1;
        data->ph[i].l_fork = i;
        data->ph[i].last_meal = get_time() / 1000;
        if(i != data->number_of_philos - 1)
            data->ph[i].r_fork = i + 1;
        else
            data->ph[i].r_fork = 0;
        pthread_create(&data->ph->philo[i], NULL, &routine, &data->ph[i]);
        i++;
    }
    i = 0;
    while (i < data->number_of_philos)
    {
        pthread_join(*data->ph[i].philo, NULL);
        i++;
    } 
}
