/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marolive <marolive@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 17:57:51 by marolive          #+#    #+#             */
/*   Updated: 2023/03/03 16:56:55 by marolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_data t_data;

typedef struct  s_philo
{
    int             id;
    int             l_fork;
    int             r_fork;
    int             index_philo;
    long            last_meal;
    pthread_t       *philo;
    pthread_mutex_t *mutex_fork;
    t_data          *table;
}   t_philo;

typedef struct s_data
{
    int             time_to_eat;
    int             time_to_die;
    int             time_to_sleep;
    int             number_of_philos;
    int             num_time_eating;
    time_t          start_time;
    pthread_mutex_t mutex_print;
    pthread_mutex_t *mutex_monitor;
    t_philo         *ph;
}   t_data;


int valid_digit(char **argv);
int atoi_ws(const char *str);

void arg_value(t_data *data, int argc, char **argv);
void phi_value(t_data *data);

void *routine(void *arg);
void sleeping(t_philo *philo);
void thinking(t_philo *philo);
void eating(t_philo *philo);

time_t get_time();
void print_act(t_philo *philo, char *str);

#endif