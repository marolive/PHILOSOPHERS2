/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marolive <marolive@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 08:48:45 by marolive          #+#    #+#             */
/*   Updated: 2023/01/14 19:51:16 by marolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

int	atoi_ws(const char *str)
{
	long			resul;
	unsigned int	i;
	long			neg;

	neg = 1;
	resul = 0;
	i = 0;
	while (str[i] == '\t' || str[i] == '\f' || str[i] == '\n'
		|| str[i] == '\r' || str[i] == '\v' || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		printf("no needed sign!\n");
		return (0);
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		resul = resul * 10 + str[i] - '0';
		i++;
	}
	return ((int)resul * neg);
}
