/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjammie <mjammie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 14:04:59 by mjammie           #+#    #+#             */
/*   Updated: 2021/08/02 14:28:59 by mjammie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

char	*ft_strdup(const char *str)
{
	char	*n_str;
	int		n;
	int		len;

	n = 0;
	len = 0;
	while (str[len])
		len++;
	n_str = (char *) malloc(sizeof(*str) * (len + 1));
	if (n_str == 0)
		return (0);
	while (str[n] != 0)
	{
		n_str[n] = str[n];
		n++;
	}
	n_str[n] = 0;
	return (n_str);
}
