/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgarg <lgarg@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 03:00:29 by lgarg             #+#    #+#             */
/*   Updated: 2021/08/05 03:00:44 by lgarg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int static	if_if(char *str)
{
	int	i;

	i = 0;
	return (str[i] == ' ' || str[i] == '\t'
		|| str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r');
}

int	ft_atoi(char *str)
{
	int	sign;
	int	nbr;
	int	num;

	sign = 1;
	nbr = 0;
	num = 19;
	while (if_if(str))
		str++;
	if (*str == '-')
	{
		sign = -sign;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		if (!num--)
			return ((1 + sign) / (-2));
		nbr = nbr * 10 + (*str - '0');
		str++;
	}
	return (nbr * sign);
}
