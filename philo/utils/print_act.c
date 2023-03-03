/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_act.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marolive <marolive@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 16:53:44 by marolive          #+#    #+#             */
/*   Updated: 2023/03/03 15:01:48 by marolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void print_act(t_philo *philo, char *str)
{
    pthread_mutex_lock(&philo->table->mutex_print);
    printf("%ld, %d, %s\n", get_time() / 1000, philo->index_philo, str);
    pthread_mutex_unlock(&philo->table->mutex_print);
}