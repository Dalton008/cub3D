// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   work_with_map.c                                    :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: mjammie <mjammie@student.42.fr>            +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2021/08/02 15:11:34 by mjammie           #+#    #+#             */
// /*   Updated: 2021/08/04 12:49:07 by mjammie          ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

#include "../includes/cub3D.h"

void	print_player(t_all *all, int color)
{
	int	i;
	int	x1;
	int	y1;

	i = 0;
	y1 = 0;
	while (y1 < 10)
	{
		x1 = 0;
		while (x1 < 10)
		{
			my_mlx_pixel_put(&all->img_map, 10 * all->player.posY + x1, 10 * all->player.posX + y1, color);
			x1++;
		}
		y1++;
	}
	mlx_put_image_to_window(all->mlx.mlx, all->mlx.win, all->img_map.img, 0, 0);
}

void	print_img(t_data *img, int x, int y, int color)
{
	int	x1;
	int	y1;

	y1 = 0;
	while (y1 < 10)
	{
		x1 = 0;
		while (x1 < 10)
		{
			my_mlx_pixel_put(img, 10 * x + x1, 10 * y + y1, color);
			x1++;
		}
		y1++;
	}
}

void	print_mini_map(t_all *all)
{
	int	x;
	int	y;

	all->mini.pa = 270 * PI / 180;
	y = 0;
	while (all->map_c[y])
	{
		x = 0;
		while (all->map_c[y][x])
		{
			if (all->map_c[y][x] == '1')
			{
				print_img(&all->img_map, x, y, 0xFFFFFFF);
			}
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(all->mlx.mlx, all->mlx.win, all->img_map.img, 0, 0);
}
