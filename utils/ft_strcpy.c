/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjammie <mjammie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 14:04:37 by mjammie           #+#    #+#             */
/*   Updated: 2021/08/02 14:28:56 by mjammie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

char	*ft_strcpy(char *dst, char *src)
{
	int	n;

	n = 0;
	if (!dst || !src)
		return (0);
	while (src[n])
	{
		dst[n] = src[n];
		n++;
	}
	dst[n] = 0;
	return (dst);
}
