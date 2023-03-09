/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marolive <marolive@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 19:43:07 by marolive          #+#    #+#             */
/*   Updated: 2023/03/09 19:13:37 by marolive         ###   ########.fr       */
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
    if ((philo->table->time_to_eat + philo->table->time_to_sleep) > philo->table->time_to_die)
    {
        pthread_mutex_lock(&philo->table->mutex_dead);
        if (philo->table->faliceu == 0)
        {
            print_act(philo, "faliceu!");
            philo->table->faliceu = 1;
        }
        pthread_mutex_unlock(&philo->table->mutex_dead);
    }
}