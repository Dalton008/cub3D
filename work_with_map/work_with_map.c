/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   work_with_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjammie <mjammie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 15:11:34 by mjammie           #+#    #+#             */
/*   Updated: 2021/08/02 15:26:46 by mjammie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	my_mlx_pixel_put()
{
	
}

void	work_with_map(t_map *map, t_lst *lst)
{
	void	*mlx;
	void	*win;
	int		x;
	int		y;

	x = 0;
	y = 0;
	mlx = mlx_init();
	win = mlx_new_window(mlx, 1024, 820, "cub3D");
	while (map->map[y])
	{
		x = 0;
		while (map->map[y][x])
		{
			if (map->map[y][x] == '1')
				mlx_pixel_put(mlx, win, x, y, 0xFFFFFFFF);
			x++;
		}
		y++;
	}
	mlx_loop(mlx);
}
