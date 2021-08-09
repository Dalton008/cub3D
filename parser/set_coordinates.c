/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_coordinates.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjammie <mjammie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 17:59:34 by mjammie           #+#    #+#             */
/*   Updated: 2021/08/09 18:01:09 by mjammie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	set_coordinates2(t_all *all, int i, int j)
{
	if (all->map[i][j] == 35)
	{
		all->player.dirX = 1;
		all->player.dirY = 0;
		all->player.planeX = 0;
		all->player.planeY = -0.66;
	}
	else if (all->map[i][j] == 39)
	{
		all->player.dirX = 0;
		all->player.dirY = -1;
		all->player.planeX = -0.66;
		all->player.planeY = 0;
	}
	all->map[i][j] = 0;
}

void	set_coordinates(t_all *all, int i, int j)
{
	all->player.posX = (double)i + 0.5;
	all->player.posY = (double)j + 0.5;
	if (all->map[i][j] == 21)
	{
		all->player.dirX = 0;
		all->player.dirY = 1;
		all->player.planeX = 0.66;
		all->player.planeY = 0;
	}
	else if (all->map[i][j] == 30)
	{
		all->player.dirX = -1;
		all->player.dirY = 0;
		all->player.planeX = 0;
		all->player.planeY = 0.66;
	}
	set_coordinates2(all, i, j);
}
