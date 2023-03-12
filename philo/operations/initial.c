/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initial.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marolive <marolive@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 18:18:43 by marolive          #+#    #+#             */
/*   Updated: 2023/03/11 21:33:43 by marolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void arg_value(t_data *data, int argc, char **argv)
{
    data->start_time = get_time();
    data->number_of_philos = atoi_ws(argv[1]);
    data->time_to_die = atoi_ws(argv[2]);
    data->time_to_eat = atoi_ws(argv[3]);
    data->time_to_sleep = atoi_ws(argv[4]);
    if(argc == 6)
        data->num_time_eating = atoi_ws(argv[5]);
    else
        data->num_time_eating = -1;
    data->ph = malloc(sizeof(t_philo) * data->number_of_philos);
    data->mutex_fork = malloc(sizeof(pthread_mutex_t) * data->number_of_philos);
}

void philo_create(t_data *data)
{
    int i;

    i = 0;
    while (i < data->number_of_philos)
    {
        data->ph[i].id = i;
        data->ph[i].l_fork = i;
        data->ph[i].index_philo = i + 1;
        if(i != data->number_of_philos - 1)
            data->ph[i].r_fork = i + 1;
        else
            data->ph[i].r_fork = 0;
        data->ph[i].table = data;
        data->ph[i].last_meal = 0;
        data->ph[i].ate = 0;
        pthread_create(&data->ph[i].philo, NULL, &routine, &data->ph[i]);
        i++;
    }
    if (data->number_of_philos != 1)
        scan_dead(data->ph);
}

void    init_mutex(t_data *data)
{
    int i;
    
    i = 0;
    pthread_mutex_init(&data->mutex_dead, NULL);
    pthread_mutex_init(&data->mutex_meal, NULL);
    pthread_mutex_init(&data->mutex_print, NULL);
    while (i < data->number_of_philos)
    {
        pthread_mutex_init(&data->mutex_fork[i], NULL);
        i++;
    }
}

void    philo_value(t_data *data)
{
    if(data->number_of_philos == 0)
    {
        printf("Don't pass zero Philosophers!\n");
        return ;
    }
}
