/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marolive <marolive@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 17:57:51 by marolive          #+#    #+#             */
/*   Updated: 2023/03/08 20:13:58 by marolive         ###   ########.fr       */
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
    pthread_t       philo;
    t_data          *table;
}   t_philo;

typedef struct s_data
{
    long            time_to_eat;
    long            time_to_die;
    long            time_to_sleep;
    long          start_time;
    int             number_of_philos;
    int             num_time_eating;
    pthread_mutex_t mutex_print;
    pthread_mutex_t *mutex_fork;
    pthread_mutex_t *mutex_monitor;
    t_philo         *ph;
}   t_data;


int valid_digit(char **argv);
long atoi_ws(const char *str);

void arg_value(t_data *data, int argc, char **argv);
void init_mutex(t_data *data);
void philo_create(t_data *data);

void *routine(void *arg);
void take_fork(t_philo *philo);
void sleeping(t_philo *philo);
void thinking(t_philo *philo);
void eating(t_philo *philo);

long get_time();
void sleep_easy(long duration, t_philo *philo);
long now_time(t_philo *philo);
void print_act(t_philo *philo, char *str);

#endif