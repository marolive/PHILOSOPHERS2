/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marolive <marolive@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 17:01:23 by marolive          #+#    #+#             */
/*   Updated: 2023/03/08 20:15:28 by marolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int main(int argc, char **argv)
{
    t_data  data;

    if (argc == 5 || argc == 6)
    {
        int i = 0;
        data.ph = malloc(sizeof(t_philo) * data.number_of_philos);
        data.mutex_fork = malloc(sizeof(pthread_mutex_t) * data.number_of_philos);
        if(valid_digit(argv))
            return (0);
        init_mutex(&data);
        arg_value(&data, argc, argv);
        philo_create(&data);
        
        while (i < data.number_of_philos)
        {
            pthread_join(data.ph[i].philo, NULL);
            i++;
        } 
    }
    else
        printf("Invalid number of arguments!\n");
    return (0);
}
