/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marolive <marolive@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 12:27:50 by marolive          #+#    #+#             */
/*   Updated: 2023/03/09 19:14:04 by marolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void *routine(void *arg)
{
    t_philo *philo;
    
    philo = (t_philo *)arg;
    if ((philo->id % 2) != 0)
        usleep(1000);
    while(1)
    {
        if (philo->table->faliceu == 1)
            break ;
        take_fork(philo);
        eating(philo);
        sleeping(philo);
        thinking(philo); 
        is_dead(philo);
    }
    return (NULL);
}