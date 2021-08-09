/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjammie <mjammie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 13:55:42 by mjammie           #+#    #+#             */
/*   Updated: 2021/08/09 20:22:03 by mjammie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	steps(t_all *all)
{
	if (all->rc.ray_dir_x < 0)
	{
		all->rc.step_x = -1;
		all->rc.side_dist_x = (all->player.posX - all->rc.map_x) * \
			all->rc.dlt_dist_x;
	}
	else
	{
		all->rc.step_x = 1;
		all->rc.side_dist_x = (all->rc.map_x + 1.0 - all->player.posX) * \
			all->rc.dlt_dist_x;
	}
	if (all->rc.ray_dir_y < 0)
	{
		all->rc.step_y = -1;
		all->rc.side_dist_y = (all->player.posY - all->rc.map_y) * \
			all->rc.delta_dist_y;
	}
	else
	{
		all->rc.step_y = 1;
		all->rc.side_dist_y = (all->rc.map_y + 1.0 - all->player.posY) * \
			all->rc.delta_dist_y;
	}
}

void	check_hit(t_all *all)
{
	while (all->rc.hit == 0)
	{
		if (all->rc.side_dist_x < all->rc.side_dist_y)
		{
			all->rc.side_dist_x += all->rc.dlt_dist_x;
			all->rc.map_x += all->rc.step_x;
			all->rc.side = 0;
		}
		else
		{
			all->rc.side_dist_y += all->rc.delta_dist_y;
			all->rc.map_y += all->rc.step_y;
			all->rc.side = 1;
		}
		if (all->map[all->rc.map_x][all->rc.map_y] > 0 && \
			all->map[all->rc.map_x][all->rc.map_y] != 2)
		{	
			all->rc.hit = 1;
		}
	}
}

void	draw_start_end(t_all *all)
{
	all->rc.line_height = (int)(SCREEN_HEIGHT / all->rc.perp_wall_dist);
	all->rc.draw_start = -all->rc.line_height / 2 + SCREEN_HEIGHT / 2;
	if (all->rc.draw_start < 0)
		all->rc.draw_start = 0;
	all->rc.draw_end = all->rc.line_height / 2 + SCREEN_HEIGHT / 2;
	if (all->rc.draw_end >= SCREEN_HEIGHT)
		all->rc.draw_end = SCREEN_HEIGHT - 1;
	if (all->rc.side == 0)
		all->rc.wall_x = all->player.posY + all->rc.perp_wall_dist \
			* all->rc.ray_dir_y;
	else
		all->rc.wall_x = all->player.posX + all->rc.perp_wall_dist \
			* all->rc.ray_dir_x;
	all->rc.wall_x -= floor((all->rc.wall_x));
	all->rc.tex_x = (int)(all->rc.wall_x * (double)TEX_WIDTH);
	if (all->rc.side == 0 && all->rc.ray_dir_x > 0)
		all->rc.tex_x = TEX_WIDTH - all->rc.tex_x - 1;
	if (all->rc.side == 1 && all->rc.ray_dir_y < 0)
		all->rc.tex_x = TEX_WIDTH - all->rc.tex_x - 1;
	all->rc.step = 1.0 * 64 / all->rc.line_height;
	all->rc.tex_pos = (all->rc.draw_start - SCREEN_HEIGHT / 2 + \
		all->rc.line_height / 2) * all->rc.step;
}

void	print(t_all *all)
{
	int		x;

	x = 0;
	init_struct_raycasting(&all->rc);
	while (x < SCREEN_WIDTH)
	{
		new_init(all, x);
		steps(all);
		check_hit(all);
		if (all->rc.side == 0)
			all->rc.perp_wall_dist = (all->rc.map_x - all->player.posX + \
				(1 - all->rc.step_x) / 2) / all->rc.ray_dir_x;
		else
			all->rc.perp_wall_dist = (all->rc.map_y - all->player.posY + \
				(1 - all->rc.step_y) / 2) / all->rc.ray_dir_y;
		draw_start_end(all);
		all->rc.tex_y = 0;
		print_pixels(all, x);
		all->buffer[x] = all->rc.perp_wall_dist;
		x++;
	}
	print_sprite(all);
	mlx_put_image_to_window(all->mlx.mlx, all->mlx.win, all->img.img, 0, 0);
}

void	raycaster(t_all *all)
{
	all->mini.on = 1;
	all->mlx.mlx = mlx_init();
	all->mlx.win = mlx_new_window(all->mlx.mlx, SCREEN_WIDTH, SCREEN_HEIGHT, \
		"cub3D");
	all->img.img = mlx_new_image(all->mlx.mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	all->img.addr = mlx_get_data_addr(all->img.img, &all->img.bits_per_pixel, \
		&all->img.line_length, &all->img.endian);
	all->img_map.img = mlx_new_image(all->mlx.mlx, all->map_max_width * 10, \
		all->map_max_height * 10);
	all->img_map.addr = mlx_get_data_addr(all->img_map.img, \
		&all->img_map.bits_per_pixel, &all->img_map.line_length, \
		&all->img_map.endian);
	optimization_color_img(all, &all->colors_n, all->path->north_path);
	optimization_color_img(all, &all->colors_s, all->path->south_path);
	optimization_color_img(all, &all->colors_west, all->path->west_path);
	optimization_color_img(all, &all->colors_east, all->path->east_path);
	optimization_color_img(all, &all->colors_sprite, "textures/barrel.xpm");
	optimization_color_img(all, &all->colors_door, "textures/door.xpm");
	all->sprite_order = (int *)malloc(sizeof(int) * all->count_sprites);
	all->sprite_distance = (double *)malloc(sizeof(double) * \
		all->count_sprites);
	print(all);
	mlx_hook(all->mlx.win, 17, 1L << 0, close_win, &all->img);
	mlx_hook(all->mlx.win, 2, 1L << 0, key_hook, all);
	mlx_loop(all->mlx.mlx);
}
