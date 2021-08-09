/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turns.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjammie <mjammie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 13:11:22 by mjammie           #+#    #+#             */
/*   Updated: 2021/08/09 15:18:44 by mjammie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	turn_left(t_all *all, double rotSpeed)
{
	double	oldDirX;
	double	oldPlaneX;

	oldDirX = all->player.dirX;
	oldPlaneX = all->player.planeX;
	all->player.dirX = all->player.dirX * cos(-rotSpeed) - all->player.dirY * \
		sin(-rotSpeed);
	all->player.dirY = oldDirX * sin(-rotSpeed) + all->player.dirY * \
		cos(-rotSpeed);
	all->player.planeX = all->player.planeX * cos(-rotSpeed) - \
		all->player.planeY * sin(-rotSpeed);
	all->player.planeY = oldPlaneX * sin(-rotSpeed) + all->player.planeY * \
		cos(-rotSpeed);
}

void	turn_right(t_all *all, double rotSpeed)
{
	double	oldDirX;
	double	oldPlaneX;

	oldDirX = all->player.dirX;
	oldPlaneX = all->player.planeX;
	all->player.dirX = all->player.dirX * cos(rotSpeed) - all->player.dirY * \
		sin(rotSpeed);
	all->player.dirY = oldDirX * sin(rotSpeed) + all->player.dirY * \
		cos(rotSpeed);
	all->player.planeX = all->player.planeX * cos(rotSpeed) - \
		all->player.planeY * sin(rotSpeed);
	all->player.planeY = oldPlaneX * sin(rotSpeed) + all->player.planeY * \
		cos(rotSpeed);
}
