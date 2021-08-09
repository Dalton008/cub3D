/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_for_spr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjammie <mjammie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 16:50:18 by mjammie           #+#    #+#             */
/*   Updated: 2021/08/09 16:50:42 by mjammie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	init_f_spr(t_f_sprs *st)
{
	st->sprite_x = 0;
	st->sprite_y = 0;
	st->inv_det = 0;
	st->transform_x = 0;
	st->transform_y = 0;
	st->spr_scrn_x = 0;
	st->v_move_screen = 0;
	st->spr_h = 0;
	st->draw_start_y = 0;
	st->draw_end_y = 0;
	st->spr_w = 0;
	st->draw_start_x = 0;
	st->draw_end_x = 0;
	st->tex_x = 0;
	st->tex_y = 0;
	st->color = 0;
}

void	new_init_spr(t_all *all, int i)
{
	all->f_spr.sprite_x = all->sprites.x[i] - all->player.posX;
	all->f_spr.sprite_y = all->sprites.y[i] - all->player.posY;
	all->f_spr.inv_det = 1.0 / (all->player.planeX * all->player.dirY - \
		all->player.dirX * all->player.planeY);
	all->f_spr.transform_x = all->f_spr.inv_det * (all->player.dirY * \
		all->f_spr.sprite_x - all->player.dirX * all->f_spr.sprite_y);
	all->f_spr.transform_y = all->f_spr.inv_det * \
		(-all->player.planeY * all->f_spr.sprite_x + all->player.planeX * \
		all->f_spr.sprite_y);
	all->f_spr.spr_scrn_x = (int)((SCREEN_WIDTH / 2) * \
		(1 + all->f_spr.transform_x / all->f_spr.transform_y));
	all->f_spr.v_move_screen = (int)(0.0 / all->f_spr.transform_y);
	all->f_spr.spr_h = abs((int)(SCREEN_HEIGHT / \
		(all->f_spr.transform_y))) / 1;
	all->f_spr.draw_start_y = -all->f_spr.spr_h / 2 + \
		SCREEN_HEIGHT / 2 + all->f_spr.v_move_screen;
}
