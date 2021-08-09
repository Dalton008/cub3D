/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjammie <mjammie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 14:14:50 by mjammie           #+#    #+#             */
/*   Updated: 2021/08/09 20:21:58 by mjammie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	print_celling(t_all *all, int *i, int x)
{
	if ((*i) < all->rc.draw_start)
	{
		while ((*i) < all->rc.draw_start)
		{
			my_mlx_pixel_put(&all->img, x, (*i), all->path->celling_colour);
			(*i)++;
		}
	}
}

void	print_textures(t_all *all, int *i, int x)
{
	while ((*i) < all->rc.draw_end)
	{
		all->rc.tex_y = (int)all->rc.tex_pos & (64 - 1);
		all->rc.tex_pos += all->rc.step;
		if (all->rc.side == 0)
		{
			if (all->rc.step_x > 0)
				all->rc.color = all->colors_s[all->rc.tex_x][all->rc.tex_y];
			else
				all->rc.color = all->colors_n[all->rc.tex_x][all->rc.tex_y];
		}
		else
		{
			if (all->rc.step_y < 0)
				all->rc.color = all->colors_west[all->rc.tex_x][all->rc.tex_y];
			else
				all->rc.color = all->colors_east[all->rc.tex_x][all->rc.tex_y];
			all->rc.color = (all->rc.color >> 1) & 8355711;
		}
		if (all->map[all->rc.map_x][all->rc.map_y] == 20)
			all->rc.color = all->colors_door[all->rc.tex_x][all->rc.tex_y];
		my_mlx_pixel_put(&all->img, x, (*i), all->rc.color);
		(*i)++;
	}
}

void	print_floor(t_all *all, int *i, int x)
{
	while ((*i) < SCREEN_HEIGHT)
	{
		my_mlx_pixel_put(&all->img, x, (*i), all->path->floor_colour);
		(*i)++;
	}
}

void	print_pixels(t_all *all, int x)
{
	int	i;

	i = 0;
	print_celling(all, &i, x);
	print_textures(all, &i, x);
	print_floor(all, &i, x);
}
