/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marolive <marolive@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 16:35:43 by marolive          #+#    #+#             */
/*   Updated: 2023/03/02 18:35:45 by marolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

time_t get_time()
{
    struct timeval time;
    gettimeofday(&time, NULL);
    return(time.tv_sec * 1000 + time.tv_usec / 1000);
}