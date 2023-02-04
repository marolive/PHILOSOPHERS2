/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marolive <marolive@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 19:43:07 by marolive          #+#    #+#             */
/*   Updated: 2023/02/04 15:53:48 by marolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

int    valid_digit(char **argv)
{
    int i;
    int j;

    i = 1;
    while((argv[i][j] >= 9 && argv[i][j] <= 13) || argv[i][j] == ' ')
        j++;
    {
        if(argv[i][j] >= '1' && argv[i][j] <= '9')
            return (1);
        j++;
    }
    return (0);
}

