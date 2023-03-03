/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marolive <marolive@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 17:01:23 by marolive          #+#    #+#             */
/*   Updated: 2023/03/03 16:23:18 by marolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int main(int argc, char **argv)
{
    t_data  data;
    t_philo philo;

    if (argc == 5 || argc == 6)
    {
        philo.philo = malloc(sizeof(pthread_t) * data.number_of_philos);
        if(valid_digit(argv))
            return (0);
        arg_value(&data, argc, argv);
        phi_value(&data);
        

    }
    else
        printf("Invalid number of arguments!\n");
    return (0);
}
