/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marolive <marolive@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 08:01:14 by marolive          #+#    #+#             */
/*   Updated: 2023/03/11 21:26:58 by marolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void take_fork(t_philo *philo)
{
   if ((philo->id % 2) != 0 && philo->index_philo != philo->table->number_of_philos)
   {
      pthread_mutex_lock(&philo->table->mutex_fork[philo->l_fork]);
      print_act(philo, "has taken a fork");
      pthread_mutex_lock(&philo->table->mutex_fork[philo->r_fork]);
      print_act(philo, "has taken a fork");
   }
   else
   {
      pthread_mutex_lock(&philo->table->mutex_fork[philo->r_fork]);
      print_act(philo, "has taken a fork");
      pthread_mutex_lock(&philo->table->mutex_fork[philo->l_fork]);
      print_act(philo, "has taken a fork");
   }
}

void sleeping(t_philo *philo)
{
   print_act(philo, "is sleeping");
   sleep_easy(philo->table->time_to_sleep, philo);
}

void thinking(t_philo *philo)
{
   print_act(philo, "is thinking");
}

void eating(t_philo *philo)
{
   if ((philo->id % 2) != 0)
   {
      print_act(philo, "is eating");
      pthread_mutex_lock(&philo->table->mutex_meal);
      philo->last_meal = now_time(philo);
      pthread_mutex_unlock(&philo->table->mutex_meal);
      philo->ate += 1;
      sleep_easy(philo->table->time_to_eat , philo);
      pthread_mutex_unlock(&philo->table->mutex_fork[philo->l_fork]);
      pthread_mutex_unlock(&philo->table->mutex_fork[philo->r_fork]);
   }
   else
   {
      print_act(philo, "is eating");
      pthread_mutex_lock(&philo->table->mutex_meal);
      philo->last_meal = now_time(philo);
      pthread_mutex_unlock(&philo->table->mutex_meal);
      philo->ate += 1;
      sleep_easy(philo->table->time_to_eat, philo);
      pthread_mutex_unlock(&philo->table->mutex_fork[philo->r_fork]);
      pthread_mutex_unlock(&philo->table->mutex_fork[philo->l_fork]);
   }
}
