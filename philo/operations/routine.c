/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marolive <marolive@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 12:27:50 by marolive          #+#    #+#             */
/*   Updated: 2023/03/03 17:10:52 by marolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void *routine(void *arg)
{
    t_philo *philo;
    
    philo = (t_philo *)arg;
    if ((philo->index_philo % 2) == 0)
        usleep(33000);
    while(1)
    {
        eating(philo);
        usleep(300);
        sleeping(philo);
        usleep(300);
        thinking(philo); 
        //sleep(1);
    }
}