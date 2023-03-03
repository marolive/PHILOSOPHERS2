/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marolive <marolive@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 19:43:07 by marolive          #+#    #+#             */
/*   Updated: 2023/03/02 11:52:15 by marolive         ###   ########.fr       */
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