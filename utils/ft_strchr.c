/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjammie <mjammie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 14:05:13 by mjammie           #+#    #+#             */
/*   Updated: 2021/08/02 14:28:53 by mjammie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

char	*ft_strchr(const char *str, int c)
{
	int		n;

	n = 0;
	while (str[n])
	{
		if (str[n] == c)
			return ((char *)str + n);
		n++;
	}
	if (c == 0)
		return ((char *)str + n);
	return (0);
}
