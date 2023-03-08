/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marolive <marolive@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 16:35:43 by marolive          #+#    #+#             */
/*   Updated: 2023/03/07 19:40:51 by marolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

long get_time()
{
    long mili;
    
    struct timeval time;
    gettimeofday(&time, NULL);
    mili = time.tv_sec * 1000;
    mili += time.tv_usec / 1000;
    return (mili);
}

long now_time(t_philo *philo)
{
    long start;

    start = philo->table->start_time;
    return (get_time() - start);
}

void sleep_easy(long duration, t_philo *philo)
{
    long start;

    start = now_time(philo);
    while(now_time(philo) - start < duration)
        usleep(100);
}