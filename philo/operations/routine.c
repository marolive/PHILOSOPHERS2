/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marolive <marolive@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 12:27:50 by marolive          #+#    #+#             */
/*   Updated: 2023/03/11 18:21:57 by marolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"



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