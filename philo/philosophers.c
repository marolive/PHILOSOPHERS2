/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marolive <marolive@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 17:01:23 by marolive          #+#    #+#             */
/*   Updated: 2023/02/16 07:14:17 by marolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int main(int argc, char **argv)
{
    t_philo *philo;
    t_data  *data;
    
    if (argc == 5 || argc == 6)
    {
        init(&data, argc, argv);
        valid_digit(argc, argv);
        
        
    
    return (0);
}
