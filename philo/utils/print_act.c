/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_act.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marolive <marolive@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 16:53:44 by marolive          #+#    #+#             */
/*   Updated: 2023/03/11 20:47:52 by marolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void print_act(t_philo *philo, char *str)
{
    pthread_mutex_lock(&philo->table->mutex_print);
    pthread_mutex_lock(&philo->table->mutex_dead);
    if (philo->table->is_dead == 0)
        printf("%ld %d %s\n", now_time(philo), philo->index_philo, str);
    pthread_mutex_unlock(&philo->table->mutex_dead);
    pthread_mutex_unlock(&philo->table->mutex_print);
}