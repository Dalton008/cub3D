/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max_height_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjammie <mjammie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 18:08:15 by mjammie           #+#    #+#             */
/*   Updated: 2021/08/09 18:08:24 by mjammie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	max_height_map(t_all *all)
{
	int	y;

	y = 0;
	all->map_max_width = 0;
	while (all->map_c[y])
	{
		if (all->map_max_width < (int)ft_strlen(all->map_c[y]))
			all->map_max_width = (int)ft_strlen(all->map_c[y]);
		y++;
	}
	all->map_max_height = y;
}
