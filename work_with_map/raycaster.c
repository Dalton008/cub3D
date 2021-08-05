/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjammie <mjammie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 13:55:42 by mjammie           #+#    #+#             */
/*   Updated: 2021/08/05 20:52:30 by mjammie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	close_win(void)
{
	ft_putstr_fd("Close window\n", 1);
	exit(0);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void print(t_all *all) 
{
	double	cameraX;
	double	rayDirX;
	double	rayDirY;
	double	sideDistX;
	double	sideDistY;
	double	deltaDistX;
	double	deltaDistY;
	double	perpWallDist;
	int		mapX;
	int		mapY;
	int		stepX;
	int		stepY;
	int		hit; 
	int		side;

	int		lineHeight;
	int		drawStart;
	int		drawEnd;

	int		x;
	int		i;

	x = 0;

	while (x < SCREEN_WIDTH)
	{
		cameraX = 2 * x / (double)SCREEN_WIDTH - 1;
		rayDirX = all->player.dirX + all->player.planeX * cameraX;
		rayDirY = all->player.dirY + all->player.planeY * cameraX;
		mapX = (int)(all->player.posX);
		mapY = (int)(all->player.posY);
		deltaDistX = fabs(1 / rayDirX);
		deltaDistY = fabs(1 / rayDirY);
		hit = 0; 
		if(rayDirX < 0)
		{
			stepX = -1;
			sideDistX = (all->player.posX - mapX) * deltaDistX;
		}
		else
		{
			stepX = 1;
			sideDistX = (mapX + 1.0 - all->player.posX) * deltaDistX;
		}
		if(rayDirY < 0)
		{
			stepY = -1;
			sideDistY = (all->player.posY - mapY) * deltaDistY;
		}
		else
		{
			stepY = 1;
			sideDistY = (mapY + 1.0 - all->player.posY) * deltaDistY;
		}
		while (hit == 0)
		{
			if(sideDistX < sideDistY)
			{
				sideDistX += deltaDistX;
				mapX += stepX;
				side = 0;
			}
			else
			{
				sideDistY += deltaDistY;
				mapY += stepY;
				side = 1;
			}
			if(all->map[mapX][mapY] > 0)
			{
				hit = 1;
			}
		}
		if(side == 0)
			perpWallDist = (mapX - all->player.posX + (1 - stepX) / 2) / rayDirX;
		else
			perpWallDist = (mapY - all->player.posY + (1 - stepY) / 2) / rayDirY;
		lineHeight = (int)(SCREEN_HEIGHT / perpWallDist);
		drawStart = -lineHeight / 2 + SCREEN_HEIGHT / 2;
		if (drawStart < 0)
			drawStart = 0;
		drawEnd = lineHeight / 2 + SCREEN_HEIGHT / 2;
		if(drawEnd >= SCREEN_HEIGHT)
			drawEnd = SCREEN_HEIGHT - 1;
		i = drawStart;
		while (i < drawEnd)
		{
			my_mlx_pixel_put(&all->img, x, i, 0x01423b);
			i++;
		}
		x++;
	}
	mlx_put_image_to_window(all->mlx.mlx, all->mlx.win, all->img.img, 0, 0);
}

int	key_hook(int keycode, t_all *all)
{
	double moveSpeed;
	double rotSpeed;
	double oldDirX;
	double oldPlaneX;

	moveSpeed = 0.1;
	rotSpeed = 0.1;
	oldDirX = all->player.dirX;
	oldPlaneX = all->player.planeX;
	if (keycode == 53)
	{
		ft_putstr_fd("Close window\n", 1);
		exit(1);
	}
	if (keycode == 13 || keycode == 126)
		{
			if (all->map[(int)(all->player.posX + all->player.dirX * moveSpeed)][(int)(all->player.posY)] == 0) 
				all->player.posX += all->player.dirX * moveSpeed;
			if (all->map[(int)(all->player.posX)][(int)(all->player.posY + all->player.dirY * moveSpeed)] == 0) 
				all->player.posY += all->player.dirY * moveSpeed;
		}
	if (keycode == 1 || keycode == 125)
		{
			if (all->map[(int)(all->player.posX - all->player.dirX * moveSpeed)][(int)(all->player.posY)] == 0) 
				all->player.posX -= all->player.dirX * moveSpeed;
			if (all->map[(int)(all->player.posX)][(int)(all->player.posY - all->player.dirY * moveSpeed)] == 0) 
				all->player.posY -= all->player.dirY * moveSpeed;
		}
		if (keycode == 2 || keycode == 124)
		{
			all->player.dirX = all->player.dirX * cos(-rotSpeed) - all->player.dirY * sin(-rotSpeed);
			all->player.dirY = oldDirX * sin(-rotSpeed) + all->player.dirY * cos(-rotSpeed);
			all->player.planeX = all->player.planeX * cos(-rotSpeed) - all->player.planeY * sin(-rotSpeed);
			all->player.planeY = oldPlaneX * sin(-rotSpeed) + all->player.planeY * cos(-rotSpeed);
			printf("%f %f\n", all->player.dirX, all->player.dirY);
		}
		if (keycode == 0 || keycode == 123)
		{
			all->player.dirX = all->player.dirX * cos(rotSpeed) - all->player.dirY * sin(rotSpeed);
			all->player.dirY = oldDirX * sin(rotSpeed) + all->player.dirY * cos(rotSpeed);
			all->player.planeX = all->player.planeX * cos(rotSpeed) - all->player.planeY * sin(rotSpeed);
			all->player.planeY = oldPlaneX * sin(rotSpeed) + all->player.planeY * cos(rotSpeed);
			printf("%f %f\n", all->player.dirX, all->player.dirY);
		}
	mlx_destroy_image(all->mlx.mlx, all->img.img);
	all->img.img = mlx_new_image(all->mlx.mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	all->img.addr = mlx_get_data_addr(all->img.img, &all->img.bits_per_pixel, &all->img.line_length, &all->img.endian);
	print(all);
	return (0);
}

void	raycaster(t_all *all)
{
	all->player.dirX = -1;
	all->player.dirY = 0;
	all->player.planeX = 0;
	all->player.planeY = 0.66;
	all->mlx.mlx = mlx_init();
	all->mlx.win = mlx_new_window(all->mlx.mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "cub3D");
	all->img.img = mlx_new_image(all->mlx.mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	all->img.addr = mlx_get_data_addr(all->img.img, &all->img.bits_per_pixel, &all->img.line_length, &all->img.endian);
	print(all);
	mlx_hook(all->mlx.win, 17, 1L << 0, close_win, &all->img);
	mlx_hook(all->mlx.win, 2, 1L << 0, key_hook, all);
	mlx_loop(all->mlx.mlx);
}
