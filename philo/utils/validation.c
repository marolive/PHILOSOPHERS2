/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marolive <marolive@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 19:43:07 by marolive          #+#    #+#             */
/*   Updated: 2023/03/11 18:51:16 by marolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

int    valid_digit(char **argv)
{
    int i;
    int j;

    i = 1;
    while(argv[i])
    {
        j = 0;
        while (argv[i][j])
        {
            if(argv[i][0] == '-' || argv[i][0] == '+')
            {
                printf("Don't pass sign!\n");
                return(1);
            }
            if(!(argv[i][j] >= '0' && argv[i][j] <= '9'))
            {
                printf("Pass only numerical value!\n");
                return (1);
            }
            j++;
        }
        i++;
    }
    return (0);
}

void is_dead(t_philo *philo)
{
    if ((now_time(philo) - philo->last_meal) > philo->table->time_to_die)
    {
        pthread_mutex_lock(&philo->table->mutex_dead);
        if (philo->table->is_dead == 0)
        {
            pthread_mutex_lock(&philo->table->mutex_print);
            printf("%ld, %d, %s\n", now_time(philo), philo->index_philo, "died");
            philo->table->is_dead = 1;
            pthread_mutex_unlock(&philo->table->mutex_print);
        }
        pthread_mutex_unlock(&philo->table->mutex_dead);
    }
}
int one_fork(t_philo *philo)
{
    pthread_mutex_lock(&philo->table->mutex_dead);
    if(philo->table->number_of_philos == 1)
    {
        pthread_mutex_lock(&philo->table->mutex_print);
        printf("%ld, %d, %s\n", now_time(philo), philo->index_philo, "has taken a fork");
        printf("%ld, %d, %s\n", now_time(philo), philo->index_philo, "died");
        pthread_mutex_unlock(&philo->table->mutex_print);
        return(1);
    }
    pthread_mutex_unlock(&philo->table->mutex_dead);
    return (0);
}

void destroy_mutex(t_data *data)
{
    int i;

    i = 0;
    pthread_mutex_destroy(&data->mutex_dead);
    pthread_mutex_destroy(&data->mutex_print);
    while(i < data->number_of_philos)
        pthread_mutex_destroy(&data->mutex_fork[i++]);
}