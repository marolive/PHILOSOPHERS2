/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marolive <marolive@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 12:27:50 by marolive          #+#    #+#             */
/*   Updated: 2023/03/11 21:33:38 by marolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void scan_dead(t_philo *philo)
{
    while(42)
    {
        pthread_mutex_lock(&philo->table->mutex_meal);
        if ((now_time(philo) - philo->last_meal) > philo->table->time_to_die)
        {
            pthread_mutex_lock(&philo->table->mutex_dead);
            philo->table->is_dead = 1;
            pthread_mutex_lock(&philo->table->mutex_print);
            printf("%ld %d %s\n", now_time(philo), philo->index_philo, "died");
            pthread_mutex_unlock(&philo->table->mutex_print);
            pthread_mutex_unlock(&philo->table->mutex_dead);
            pthread_mutex_unlock(&philo->table->mutex_meal);
            break;
        }
        pthread_mutex_unlock(&philo->table->mutex_meal);
        usleep(200);
    }
}



void *routine(void *arg)
{
    t_philo *philo;

    philo = (t_philo *)arg;
    if ((philo->id % 2) != 0)
        usleep(500);
    while(1)
    {
        pthread_mutex_lock(&philo->table->mutex_dead);
        if (philo->table->is_dead == 1 || philo->ate == philo->table->num_time_eating)
            break ;
        pthread_mutex_unlock(&philo->table->mutex_dead);
        if(one_fork(philo) == 1)
            break ;
        take_fork(philo);
        eating(philo);
        sleeping(philo);
        thinking(philo);
        is_dead(philo);
    }
    pthread_mutex_unlock(&philo->table->mutex_dead);
    return (NULL);
}