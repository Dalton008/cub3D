/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjammie <mjammie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 18:19:25 by mjammie           #+#    #+#             */
/*   Updated: 2021/08/08 18:24:37 by mjammie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	moves_up_down(t_all *all)
{

}

void	moves(t_all *all, int keycode)
{
	double moveSpeed;
	double rotSpeed;
	double oldDirX;
	double oldPlaneX;

	rotSpeed = 0.1;
	moveSpeed = 0.1;
	oldDirX = all->player.dirX;
	oldPlaneX = all->player.planeX;
	if (keycode == 13 || keycode == 126) //w
	{
		if (all->map[(int)(all->player.posX + all->player.dirX * moveSpeed)][(int)(all->player.posY)] == 0) 
			all->player.posX += all->player.dirX * moveSpeed;
		if (all->map[(int)(all->player.posX)][(int)(all->player.posY + all->player.dirY * moveSpeed)] == 0) 
			all->player.posY += all->player.dirY * moveSpeed;
	}
	if (keycode == 1 || keycode == 125) //s
	{
		if (all->map[(int)(all->player.posX - all->player.dirX * moveSpeed)][(int)(all->player.posY)] == 0) 
			all->player.posX -= all->player.dirX * moveSpeed;
		if (all->map[(int)(all->player.posX)][(int)(all->player.posY - all->player.dirY * moveSpeed)] == 0) 
			all->player.posY -= all->player.dirY * moveSpeed;
	}
	if (keycode == 124) //d = 2
	{
		all->player.dirX = all->player.dirX * cos(-rotSpeed) - all->player.dirY * sin(-rotSpeed);
		all->player.dirY = oldDirX * sin(-rotSpeed) + all->player.dirY * cos(-rotSpeed);
		all->player.planeX = all->player.planeX * cos(-rotSpeed) - all->player.planeY * sin(-rotSpeed);
		all->player.planeY = oldPlaneX * sin(-rotSpeed) + all->player.planeY * cos(-rotSpeed);
	}
	if (keycode == 123) //a = 0
	{
		all->player.dirX = all->player.dirX * cos(rotSpeed) - all->player.dirY * sin(rotSpeed);
		all->player.dirY = oldDirX * sin(rotSpeed) + all->player.dirY * cos(rotSpeed);
		all->player.planeX = all->player.planeX * cos(rotSpeed) - all->player.planeY * sin(rotSpeed);
		all->player.planeY = oldPlaneX * sin(rotSpeed) + all->player.planeY * cos(rotSpeed);
	}
	if (keycode == 0)
	{
		if (all->map[(int)(all->player.posX - all->player.dirY * moveSpeed)][(int)(all->player.posY)] == 0) 
			all->player.posX -= all->player.dirY * moveSpeed;
		if (all->map[(int)(all->player.posX)][(int)(all->player.posY + all->player.dirX * moveSpeed)] == 0) 
			all->player.posY += all->player.dirX * moveSpeed;
	}
	if (keycode == 2)
	{
		if (all->map[(int)(all->player.posX + all->player.dirY * moveSpeed)][(int)(all->player.posY)] == 0) 
		all->player.posX += all->player.dirY * moveSpeed;
		if (all->map[(int)(all->player.posX)][(int)(all->player.posY - all->player.dirX * moveSpeed)] == 0) 
			all->player.posY -= all->player.dirX * moveSpeed;
	}
}