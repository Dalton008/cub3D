/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjammie <mjammie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 14:49:25 by mjammie           #+#    #+#             */
/*   Updated: 2021/08/09 15:21:03 by mjammie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	close_win(void)
{
	ft_putstr_fd("Close window\n", 1);
	exit(0);
}

void	check_mini_map(t_all *all)
{
	if (all->mini.on % 2 == 0)
	{
		all->img_map.img = mlx_new_image(all->mlx.mlx, all->map_max_width * \
			10, all->map_max_height * 10);
		all->img_map.addr = mlx_get_data_addr(all->img_map.img, \
			&all->img_map.bits_per_pixel, &all->img_map.line_length, \
			&all->img_map.endian);
		print_mini_map(all);
		print_player(all, 0xfa0000);
		mlx_put_image_to_window(all->mlx.mlx, all->mlx.win, \
			all->img_map.img, 10, 10);
	}
}

int	key_hook(int keycode, t_all *all)
{
	if (all->mini.on % 2 == 0)
		mlx_destroy_image(all->mlx.mlx, all->img_map.img);
	if (keycode == 53)
	{
		ft_putstr_fd("Close window\n", 1);
		exit(1);
	}
	mlx_destroy_image(all->mlx.mlx, all->img.img);
	all->img.img = mlx_new_image(all->mlx.mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	all->img.addr = mlx_get_data_addr(all->img.img, &all->img.bits_per_pixel, \
		&all->img.line_length, &all->img.endian);
	print(all);
	if (keycode == 48)
		all->mini.on++;
	moves(all, keycode);
	check_mini_map(all);
	return (0);
}
