/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marolive <marolive@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 17:57:51 by marolive          #+#    #+#             */
/*   Updated: 2023/02/16 08:16:10 by marolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_data;

typedef struct  s_philo
{
    int     id;
    int     name_philo;
    int     l_fork;
    int     r_fork;
    long    last_meal;
    t_data  *table;
    pthread_t       philo;
}               t_philo;

typedef struct s_data
{
    int             time_to_eat;
    int             time_to_die;
    int             time_to_sleep;
    int             number_of_philos;
    int             num_time_eating;
    pthread_mutex_t *mutex_fork;
    pthread_mutex_t mutex_print;
    pthread_mutex_t *mutex_monitor;
    t_philo         *ph;
}       t_data;


int valid_digit(int argc, char **argv);
void init(t_data *data, int argc, char **argv);
void print_act(t_data *data, char *str);
int atoi_ws(const char *str);

#endif