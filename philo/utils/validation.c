/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marolive <marolive@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 19:43:07 by marolive          #+#    #+#             */
/*   Updated: 2023/01/14 20:27:51 by marolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

int    valid_digit(int argc, char **argv)
{
    int i;
    int j;

    i = 1;
    if(argc != 3)
    {
        printf("number arguments invalid!\n");
        return (0);
    }
    while(argv[i])
    {
        j = 0;
        if(argv[i][j] == '0')
        {
            printf("invalid number!\n");
            return (0);
        }
        while(argv[i][j])
        {
            if(argv[i][j] >= '1' && argv[i][j] <= '9')
                return (1);
            j++;
        }
        i++;
    }
    return (0);
}