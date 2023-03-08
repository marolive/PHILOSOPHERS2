/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marolive <marolive@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 08:01:14 by marolive          #+#    #+#             */
/*   Updated: 2023/03/08 20:17:44 by marolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void take_fork(t_philo *philo)
{
   if ((philo->id % 2) != 0)
   {
      pthread_mutex_lock(&philo->table->mutex_fork[philo->l_fork]);
      print_act(philo, "pegou o f_left!");
      pthread_mutex_lock(&philo->table->mutex_fork[philo->r_fork]);
      print_act(philo, "pegou o f_right!");
   }
   else
   {
      pthread_mutex_lock(&philo->table->mutex_fork[philo->r_fork]);
      print_act(philo, "pegou o f_right!");
      pthread_mutex_lock(&philo->table->mutex_fork[philo->l_fork]);
      print_act(philo, "pegou o f_left!");
   }
}

void sleeping(t_philo *philo)
{
   print_act(philo, "sleeping!");
   sleep_easy(philo->table->time_to_sleep, philo);
}

void thinking(t_philo *philo)
{
   print_act(philo, "thinking!");
}

void eating(t_philo *philo)
{
   if ((philo->id % 2) != 0)
   {
/*       pthread_mutex_lock(&philo->table->mutex_fork[philo->l_fork]);
      print_act(philo, "pegou o f_left!");
      pthread_mutex_lock(&philo->table->mutex_fork[philo->r_fork]);
      print_act(philo, "pegou o f_right!"); */
      print_act(philo, "eating!");
      sleep_easy(philo->table->time_to_eat , philo);
      pthread_mutex_unlock(&philo->table->mutex_fork[philo->l_fork]);
      pthread_mutex_unlock(&philo->table->mutex_fork[philo->r_fork]);
   }
   else
   {
/*       pthread_mutex_lock(&philo->table->mutex_fork[philo->r_fork]);
      print_act(philo, "pegou o f_right!");
      pthread_mutex_lock(&philo->table->mutex_fork[philo->l_fork]);
      print_act(philo, "pegou o f_left!"); */
      print_act(philo, "eating!");
      sleep_easy(philo->table->time_to_eat, philo);
      pthread_mutex_unlock(&philo->table->mutex_fork[philo->r_fork]);
      pthread_mutex_unlock(&philo->table->mutex_fork[philo->l_fork]);
   }
}
