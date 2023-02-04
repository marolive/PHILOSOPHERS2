/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marolive <marolive@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 17:57:51 by marolive          #+#    #+#             */
/*   Updated: 2023/02/04 17:15:52 by marolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>

typedef struct  s_philo
{
    int             index;
    int             fork;
    int             time_to_eat;
    int             time_to_die;
    int             time_to_sleep;
    int             number_of_philosophers;
    pthread_t       philo;
    pthread_mutex_t *mutex_fork;
    pthread_mutex_t *mutex_print;
    pthread_mutex_t *mutex_monitor;
}               t_philo;


int valid_digit(int argc, char **argv);
int atoi_ws(const char *str);

#endif