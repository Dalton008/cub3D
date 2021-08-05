/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgarg <lgarg@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 02:34:00 by lgarg             #+#    #+#             */
/*   Updated: 2021/08/05 03:00:59 by lgarg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	lenght_l;

	lenght_l = ft_strlen(little);
	if (lenght_l == 0)
		return ((char *)big);
	while (len >= lenght_l)
	{
		if (*big == *little && (ft_strncmp(big, little, lenght_l) == 0))
			return ((char *)big);
		big++;
		len--;
	}
	return (0);
}
