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

// #include "../includes/cub3D.h"

// void	print_player(t_all *all)
// {
// 	int	i;

// 	i = 0;
// 	print_map(all);
// 	all->player.dir_x = all->player.x;
// 	all->player.dir_y = all->player.y;
// 	all->player.start = all->player.pa - M_PI_4;
// 	all->player.end = all->player.pa + M_PI_4;
// 	while (all->player.start < all->player.end)
// 	{
// 		all->player.dir_x = all->player.x;
// 		all->player.dir_y = all->player.y;
// 		while (all->map[(int)(all->player.dir_y / 20)][(int)(all->player.dir_x / 20)] != '1')
// 		{
// 			all->player.dir_x += cos(all->player.start);
// 			all->player.dir_y += sin(all->player.start);
// 			my_mlx_pixel_put(&all->img, all->player.dir_x, all->player.dir_y, 0xff0051);
// 		}
// 		all->player.start += M_PI_2 / 640;
// 	}
// 	mlx_put_image_to_window(all->mlx.mlx, all->mlx.win, all->img.img, 0, 0);
// }

// int	close_win(void)
// {
// 	ft_putstr_fd("Close window\n", 1);
// 	exit(1);
// }

// void	print_map(t_all *all)
// {
// 	int	x;
// 	int	y;

// 	y = 0;
// 	while (all->map[y])
// 	{
// 		x = 0;
// 		while (all->map[y][x])
// 		{
// 			if (all->map[y][x] == '0' || all->map[y][x] == 'N')
// 			{
// 				print_img(&all->img, x, y, 0);
// 			}
// 			if (all->map[y][x] == '1' )
// 			{
// 				print_img(&all->img, x, y, 0xFFFFFFF);
// 			}
// 			x++;
// 		}
// 		y++;
// 	}
// 	mlx_put_image_to_window(all->mlx.mlx, all->mlx.win, all->img.img, 0, 0);
// }

// int	key_hook(int keycode, t_all *all)
// {
// 	int	x;
// 	int	y;

// 	if (keycode == 53)
// 	{
// 		ft_putstr_fd("Close window\n", 1);
// 		exit(1);
// 	}
// 	if (keycode == 13 || keycode == 126)//w
// 	{
// 		x = all->player.x + cos(all->player.pa) * 4;
// 		y = all->player.y + sin(all->player.pa) * 4;
// 		if (all->map[y / 20][x / 20] == '1')
// 			return (0);
// 		all->player.x += cos(all->player.pa) * 4;
// 		all->player.y += sin(all->player.pa) * 4;
// 	}
// 	else if (keycode == 0 || keycode == 123)//a
// 	{
// 		all->player.pa -= 0.05;
// 	}
// 	else if (keycode == 1 || keycode == 125)//s
// 	{
// 		x = all->player.x - cos(all->player.pa) * 4;
// 		y = all->player.y - sin(all->player.pa) * 4;
// 		if (all->map[y / 20][x / 20] == '1')
// 			return (0);
// 		all->player.y -= sin(all->player.pa) * 4;
// 		all->player.x -= cos(all->player.pa) * 4;
// 	}
// 	else if (keycode == 2 || keycode == 124)//d
// 	{
// 		all->player.pa += 0.05;
// 	}
// 	print_player(all);
// 	return (0);
// }

// void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
// {
// 	char	*dst;

// 	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
// 	*(unsigned int *)dst = color;
// }

// void	print_img(t_data *img, int x, int y, int color)
// {
// 	int	x1;
// 	int	y1;

// 	y1 = 0;
// 	while (y1 < 20)
// 	{
// 		x1 = 0;
// 		while (x1 < 20)
// 		{
// 			my_mlx_pixel_put(img, 20 * x + x1, 20 * y + y1, color);
// 			x1++;
// 		}
// 		y1++;
// 	}
// }

// void	work_with_map(t_all *all)
// {
// 	int	x;
// 	int	y;

// 	all->player.dir_x = 0;
// 	all->player.dir_y = 0;
// 	all->player.pa = 270 * PI / 180;
// 	y = 0;
// 	all->mlx.mlx = mlx_init();
// 	all->mlx.win = mlx_new_window(all->mlx.mlx, 840, 720, "cub3D");
// 	all->img.img = mlx_new_image(all->mlx.mlx, 840, 720);
// 	all->img.addr = mlx_get_data_addr(all->img.img, &all->img.bits_per_pixel, &all->img.line_length, &all->img.endian);
// 	while (all->map[y])
// 	{
// 		x = 0;
// 		while (all->map[y][x])
// 		{
// 			if (all->map[y][x] == '1')
// 			{
// 				print_img(&all->img, x, y, 0xFFFFFFF);
// 			}
// 			else if (all->map[y][x] == 'N')
// 			{
// 				all->player.x = x * 20;
// 				all->player.y = y * 20;
// 				print_player(all);
// 			}
// 			x++;
// 		}
// 		y++;
// 	}
// 	mlx_put_image_to_window(all->mlx.mlx, all->mlx.win, all->img.img, 0, 0);
// 	mlx_hook(all->mlx.win, 17, 1L << 0, close_win, &all->img);
// 	mlx_hook(all->mlx.win, 2, 1L << 0, key_hook, all);
// 	mlx_loop(all->mlx.mlx);
// }
