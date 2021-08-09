/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjammie <mjammie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 18:19:25 by mjammie           #+#    #+#             */
/*   Updated: 2021/08/09 15:17:19 by mjammie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	move_up(t_all *all, double moveSpeed)
{
	if (all->map[(int)(all->player.posX + all->player.dirX * moveSpeed)] \
		[(int)(all->player.posY)] == 0)
		all->player.posX += all->player.dirX * moveSpeed;
	if (all->map[(int)(all->player.posX)][(int)(all->player.posY + \
		all->player.dirY * moveSpeed)] == 0)
		all->player.posY += all->player.dirY * moveSpeed;
}

void	move_down(t_all *all, double moveSpeed)
{
	if (all->map[(int)(all->player.posX - all->player.dirX * moveSpeed)] \
		[(int)(all->player.posY)] == 0)
		all->player.posX -= all->player.dirX * moveSpeed;
	if (all->map[(int)(all->player.posX)][(int)(all->player.posY - \
		all->player.dirY * moveSpeed)] == 0)
		all->player.posY -= all->player.dirY * moveSpeed;
}

void	move_left(t_all *all, double moveSpeed)
{
	if (all->map[(int)(all->player.posX - all->player.dirY * moveSpeed)] \
		[(int)(all->player.posY)] == 0)
		all->player.posX -= all->player.dirY * moveSpeed;
	if (all->map[(int)(all->player.posX)][(int)(all->player.posY + \
		all->player.dirX * moveSpeed)] == 0)
		all->player.posY += all->player.dirX * moveSpeed;
}

void	move_right(t_all *all, double moveSpeed)
{
	if (all->map[(int)(all->player.posX + all->player.dirY * moveSpeed)] \
		[(int)(all->player.posY)] == 0)
		all->player.posX += all->player.dirY * moveSpeed;
	if (all->map[(int)(all->player.posX)][(int)(all->player.posY - \
		all->player.dirX * moveSpeed)] == 0)
		all->player.posY -= all->player.dirX * moveSpeed;
}

void	moves(t_all *all, int keycode)
{
	double	moveSpeed;
	double	rotSpeed;

	rotSpeed = 0.1;
	moveSpeed = 0.1;
	if (keycode == 13 || keycode == 126)
		move_up(all, moveSpeed);
	if (keycode == 1 || keycode == 125)
		move_down(all, moveSpeed);
	if (keycode == 124)
		turn_left(all, rotSpeed);
	if (keycode == 123)
		turn_right(all, rotSpeed);
	if (keycode == 0)
		move_left(all, moveSpeed);
	if (keycode == 2)
		move_right(all, moveSpeed);
}
