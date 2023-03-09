/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marolive <marolive@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 17:01:23 by marolive          #+#    #+#             */
/*   Updated: 2023/03/09 19:11:45 by marolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int main(int argc, char **argv)
{
    t_data  data;

    if (argc == 5 || argc == 6)
    {
        int i = 0;
        data.faliceu = 0;
        if(valid_digit(argv))
            return (0);
        arg_value(&data, argc, argv);
        init_mutex(&data);
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
