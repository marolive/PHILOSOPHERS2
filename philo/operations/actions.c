/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marolive <marolive@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 08:01:14 by marolive          #+#    #+#             */
/*   Updated: 2023/03/03 16:58:47 by marolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void sleeping(t_philo *philo)
{
   print_act(philo, "sleeping!");
   usleep(philo->table->time_to_sleep / 1000);
}

void thinking(t_philo *philo)
{
   print_act(philo, "thinking!");
}

void eating(t_philo *philo)
{
   pthread_mutex_lock(&philo->mutex_fork[philo->l_fork]);
   pthread_mutex_lock(&philo->mutex_fork[philo->r_fork]);
   print_act(philo, "pegou o l_fork!");
   print_act(philo, "pegou o r_fork!");
   print_act(philo, "eating!");
   pthread_mutex_unlock(&philo->mutex_fork[philo->l_fork]);
   pthread_mutex_unlock(&philo->mutex_fork[philo->r_fork]);
   print_act(philo, "largou o l_fork!");
   print_act(philo, "largou o r_fork!");
   printf("\n");
}
