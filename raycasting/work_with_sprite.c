/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   work_with_sprite.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjammie <mjammie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 13:46:24 by mjammie           #+#    #+#             */
/*   Updated: 2021/08/09 17:24:36 by mjammie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	sort_sprites(double *sprite_distance, t_all *all)
{
	int			i;
	double		temp;

	i = 0;
	temp = 0;
	while (i < all->count_sprites)
	{
		if (sprite_distance[i] < sprite_distance[i + 1])
		{
			temp = sprite_distance[i];
			sprite_distance[i] = sprite_distance[i + 1];
			sprite_distance[i + 1] = temp;
			temp = all->sprites.x[i];
			all->sprites.x[i] = all->sprites.x[i + 1];
			all->sprites.x[i + 1] = temp;
			temp = all->sprites.y[i];
			all->sprites.y[i] = all->sprites.y[i + 1];
			all->sprites.y[i + 1] = temp;
			i = 0;
		}
		i++;
	}
}

static void	draw_start_end(t_all *all, int *stripe)
{
	if (all->f_spr.draw_start_y < 0)
		all->f_spr.draw_start_y = 0;
	all->f_spr.draw_end_y = all->f_spr.spr_h / 2 + \
		SCREEN_HEIGHT / 2 + all->f_spr.v_move_screen;
	if (all->f_spr.draw_end_y >= SCREEN_HEIGHT)
		all->f_spr.draw_end_y = SCREEN_HEIGHT - 1;
	all->f_spr.spr_w = abs((int)(SCREEN_HEIGHT / \
		(all->f_spr.transform_y))) / 1;
	all->f_spr.draw_start_x = -all->f_spr.spr_w / \
		2 + all->f_spr.spr_scrn_x;
	if (all->f_spr.draw_start_x < 0)
		all->f_spr.draw_start_x = 0;
	all->f_spr.draw_end_x = all->f_spr.spr_w / \
		2 + all->f_spr.spr_scrn_x;
	if (all->f_spr.draw_end_x >= SCREEN_WIDTH)
		all->f_spr.draw_end_x = SCREEN_WIDTH - 1;
	(*stripe) = all->f_spr.draw_start_x;
}

static void	print_pixels_sp(t_all *all, int *stripe, int y, int d)
{
	while ((*stripe) < all->f_spr.draw_end_x)
	{
		all->f_spr.tex_x = (int)(256 * ((*stripe) - \
			(-all->f_spr.spr_w / 2 + all->f_spr.spr_scrn_x)) * TEX_WIDTH / \
			all->f_spr.spr_w) / 256;
		if (all->f_spr.transform_y > 0 && stripe > 0 && (*stripe) < \
			SCREEN_WIDTH && all->f_spr.transform_y < all->buffer[(*stripe)])
		{
			y = all->f_spr.draw_start_y;
			while (y < all->f_spr.draw_end_y)
			{
				d = (y - all->f_spr.v_move_screen) * 256 - SCREEN_HEIGHT * \
					128 + all->f_spr.spr_h * 128;
				all->f_spr.tex_y = ((d * TEX_HEIGHT) / all->f_spr.spr_h) / 256;
				all->f_spr.color = all->colors_sprite[0][TEX_WIDTH * \
					all->f_spr.tex_x + all->f_spr.tex_y];
				if ((all->f_spr.color & 0x00FFFFFF) != 0)
					my_mlx_pixel_put(&all->img, (*stripe), y, all->f_spr.color);
				y++;
			}
		}
		(*stripe)++;
	}
}

void	set_dis_and_or(t_all *all, int **sprite_order, double *sprite_distance)
{
	int	i;

	i = 0;
	while (i < all->count_sprites)
	{
		(*sprite_order)[i] = i;
		sprite_distance[i] = ((all->player.posX - all->sprites.x[i]) * \
			(all->player.posX - all->sprites.x[i]) + (all->player.posY \
			- all->sprites.y[i]) * (all->player.posY - all->sprites.y[i]));
		i++;
	}
}

void	print_sprite(t_all *all)
{
	int		i;
	int		y;
	int		d;
	int		stripe;

	stripe = 0;
	y = 0;
	d = 0;
	init_f_spr(&all->f_spr);
	set_dis_and_or(all, &all->sprite_order, all->sprite_distance);
	sort_sprites(all->sprite_distance, all);
	i = 0;
	while (i < all->count_sprites)
	{
		new_init_spr(all, i);
		draw_start_end(all, &stripe);
		print_pixels_sp(all, &stripe, y, d);
		i++;
	}
}
