/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marolive <marolive@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 12:27:50 by marolive          #+#    #+#             */
/*   Updated: 2023/03/08 20:17:47 by marolive         ###   ########.fr       */
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
        take_fork(philo);
        eating(philo);
        sleeping(philo);
        thinking(philo); 
    }
}