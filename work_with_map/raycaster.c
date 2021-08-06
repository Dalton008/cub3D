/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjammie <mjammie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 13:55:42 by mjammie           #+#    #+#             */
/*   Updated: 2021/08/06 21:24:34 by mjammie          ###   ########.fr       */
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

unsigned int	texpixcolor(t_data *img, int x, int y)
{
	char			*addr;
	unsigned int	color;

	addr = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	color = *(unsigned int*)addr;
	return (color);
}

void	optimization_color_img(t_all *all, int ***arr, char *path)
{
	int	n;
	int	m;
	int	x;
	int	y;
	t_data	newImg;

	x = -1;
	n = 0;
	m = 0;
	if (!(newImg.img = mlx_xpm_file_to_image(all->mlx.mlx, path, &n, &m))) 
	{
		printf("Error\nWrong path to texture!!!\n");
		exit(0);
	}
	newImg.addr = mlx_get_data_addr(newImg.img, &newImg.bits_per_pixel, &newImg.line_length, &newImg.endian);
	(*arr) = (int **)malloc(sizeof(int*) * n);
	while (++x < texWidth) 
	{
		y = -1;
		(*arr)[x] = (int *)malloc(sizeof(int) * m);
  		while (++y < texHeight)
			  (*arr)[x][y] = texpixcolor(&newImg, x, y);
	}
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
	double 	wallX;

	int		color;

	int		x;
	int		i;

	x = 0;
	color = 0;
	optimization_color_img(all, &all->colors_north, all->path->north_path);
	optimization_color_img(all, &all->colors_south, all->path->south_path);
	optimization_color_img(all, &all->colors_west, all->path->west_path);
	optimization_color_img(all, &all->colors_east, all->path->east_path);
	double step = 0;
	double texPos = 0;
	int texY = 0;
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
			if (sideDistX < sideDistY)
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
			if (all->map[mapX][mapY] > 0)
			{
				hit = 1;
			}
		}
		if (side == 0)
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
		
		if (side == 0)
			wallX = all->player.posY + perpWallDist * rayDirY;
		else
			wallX = all->player.posX + perpWallDist * rayDirX;
		wallX -= floor((wallX));

		int texX = (int)(wallX * (double)texWidth);
		if (side == 0 && rayDirX > 0)
			texX = texWidth - texX - 1;
		if (side == 1 && rayDirY < 0)
			texX = texWidth - texX - 1;
		
		step = 1.0 * 64 / lineHeight;
		texPos = (drawStart - SCREEN_HEIGHT / 2 + lineHeight / 2) * step;
		texY = 0;
		i = 0;
		if (i < drawStart)
		{
			while (i < drawStart)
			{
				my_mlx_pixel_put(&all->img, x, i, all->path->celling_colour);
				i++;
			}
		}
		while (i < drawEnd)
		{
			texY = (int)texPos & (64 - 1);
			texPos += step;
			if (side == 0) 
			{
				if (stepX > 0)
					color = all->colors_south[texX][texY]; //S
				else
					color = all->colors_north[texX][texY]; //N
			} 
			else 
			{
				if (stepY < 0)
					color = all->colors_west[texX][texY]; //W
				else
					color = all->colors_east[texX][texY]; //E
			}
			my_mlx_pixel_put(&all->img, x, i, color);
			i++;
		}
		while (i < SCREEN_HEIGHT)
		{
			my_mlx_pixel_put(&all->img, x, i, all->path->floor_colour);
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

	rotSpeed = 0.1;
	oldDirX = all->player.dirX;
	oldPlaneX = all->player.planeX;
	moveSpeed = 0.1;
	if (keycode == 53)
	{
		ft_putstr_fd("Close window\n", 1);
		exit(1);
	}
	printf("%d\n", keycode);
	if (keycode == 13 || keycode == 126) //w 
	{
		if (all->map[(int)(all->player.posX + all->player.dirX * moveSpeed)][(int)(all->player.posY)] == 0) 
			all->player.posX += all->player.dirX * moveSpeed;
		if (all->map[(int)(all->player.posX)][(int)(all->player.posY + all->player.dirY * moveSpeed)] == 0) 
			all->player.posY += all->player.dirY * moveSpeed;
	}
	if (keycode == 1 || keycode == 125) //s
	{
		if (all->map[(int)(all->player.posX - all->player.dirX * moveSpeed)][(int)(all->player.posY)] == 0) 
			all->player.posX -= all->player.dirX * moveSpeed;
		if (all->map[(int)(all->player.posX)][(int)(all->player.posY - all->player.dirY * moveSpeed)] == 0) 
			all->player.posY -= all->player.dirY * moveSpeed;
	}
	if (keycode == 124 || keycode == 2) //d = 2
	{
		all->player.dirX = all->player.dirX * cos(rotSpeed) - all->player.dirY * sin(rotSpeed);
		all->player.dirY = oldDirX * sin(rotSpeed) + all->player.dirY * cos(rotSpeed);
		all->player.planeX = all->player.planeX * cos(rotSpeed) - all->player.planeY * sin(rotSpeed);
		all->player.planeY = oldPlaneX * sin(rotSpeed) + all->player.planeY * cos(rotSpeed);
	}
	if (keycode == 123 || keycode == 0) //a = 0
	{
		all->player.dirX = all->player.dirX * cos(-rotSpeed) - all->player.dirY * sin(-rotSpeed);
		all->player.dirY = oldDirX * sin(-rotSpeed) + all->player.dirY * cos(-rotSpeed);
		all->player.planeX = all->player.planeX * cos(-rotSpeed) - all->player.planeY * sin(-rotSpeed);
		all->player.planeY = oldPlaneX * sin(-rotSpeed) + all->player.planeY * cos(-rotSpeed);
	}
	// if (keycode == 2)
	// {
	// 	if (all->map[(int)(all->player.posY + all->player.dirX * moveSpeed)][(int)(all->player.posX)] == 0) 
	// 		all->player.posY += all->player.dirX * moveSpeed;
	// 	if (all->map[(int)(all->player.posY)][(int)(all->player.posX - all->player.dirY * moveSpeed)] == 0) 
	// 		all->player.posX -= all->player.dirY * moveSpeed;
	// }
	// if (keycode == 0)
	// {
	// 	if (all->map[(int)(all->player.posY - all->player.dirX * moveSpeed)][(int)(all->player.posX)] == 0) 
	// 		all->player.posY -= all->player.dirX * moveSpeed;
	// 	if (all->map[(int)(all->player.posY)][(int)(all->player.posX + all->player.dirY * moveSpeed)] == 0) 
	// 		all->player.posX += all->player.dirY * moveSpeed;
	// }
	mlx_destroy_image(all->mlx.mlx, all->img.img);
	all->img.img = mlx_new_image(all->mlx.mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	all->img.addr = mlx_get_data_addr(all->img.img, &all->img.bits_per_pixel, &all->img.line_length, &all->img.endian);
	print(all);
	return (0);
}

// int moving(t_all *all) {
// 	double moveSpeed;
// 	double rotSpeed;
// 	double oldDirX;
// 	double oldPlaneX;

// 	rotSpeed = 0.1;
// 	oldDirX = all->player.dirX;
// 	oldPlaneX = all->player.planeX;
// 	moveSpeed = 0.1;
// 	if (all->hok.UP == 1) {
// 		if (all->map[(int)(all->player.posX + all->player.dirX * moveSpeed)][(int)(all->player.posY)] == 0) 
// 				all->player.posX += all->player.dirX * moveSpeed;
// 		if (all->map[(int)(all->player.posX)][(int)(all->player.posY + all->player.dirY * moveSpeed)] == 0) 
// 			all->player.posY += all->player.dirY * moveSpeed;
// 		// all->hok.UP = 0;
// 	}
// 	if (all->hok.DOWN == 1) {
// 		if (all->map[(int)(all->player.posX - all->player.dirX * moveSpeed)][(int)(all->player.posY)] == 0) 
// 				all->player.posX -= all->player.dirX * moveSpeed;
// 		if (all->map[(int)(all->player.posX)][(int)(all->player.posY - all->player.dirY * moveSpeed)] == 0) 
// 			all->player.posY -= all->player.dirY * moveSpeed;
// 		// all->hok.DOWN = 0;
// 	}
// 	if (all->hok.LEFT == 1) {
// 		all->player.dirX = all->player.dirX * cos(rotSpeed) - all->player.dirY * sin(rotSpeed);
// 		all->player.dirY = oldDirX * sin(rotSpeed) + all->player.dirY * cos(rotSpeed);
// 		all->player.planeX = all->player.planeX * cos(rotSpeed) - all->player.planeY * sin(rotSpeed);
// 		all->player.planeY = oldPlaneX * sin(rotSpeed) + all->player.planeY * cos(rotSpeed);
// 		// all->hok.LEFT = 0;
// 	}
// 	if (all->hok.RIGHT == 1) {
// 		all->player.dirX = all->player.dirX * cos(-rotSpeed) - all->player.dirY * sin(-rotSpeed);
// 		all->player.dirY = oldDirX * sin(-rotSpeed) + all->player.dirY * cos(-rotSpeed);
// 		all->player.planeX = all->player.planeX * cos(-rotSpeed) - all->player.planeY * sin(-rotSpeed);
// 		all->player.planeY = oldPlaneX * sin(-rotSpeed) + all->player.planeY * cos(-rotSpeed);
// 		// all->hok.RIGHT = 0;
// 	}
// 	all->hok.UP = 0;
// 	all->hok.DOWN = 0;
// 	all->hok.LEFT = 0;
// 	all->hok.RIGHT = 0;
// 	mlx_destroy_image(all->mlx.mlx, all->img.img);
// 	all->img.img = mlx_new_image(all->mlx.mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
// 	all->img.addr = mlx_get_data_addr(all->img.img, &all->img.bits_per_pixel, &all->img.line_length, &all->img.endian);
// 	print(all);
// 	return 0;
// }

void	raycaster(t_all *all)
{
	// all->hok.UP = 0;
	// all->hok.DOWN = 0;
	// all->hok.LEFT = 0;
	// all->hok.RIGHT = 0;
	all->mlx.mlx = mlx_init();
	all->mlx.win = mlx_new_window(all->mlx.mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "cub3D");
	all->img.img = mlx_new_image(all->mlx.mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	all->img.addr = mlx_get_data_addr(all->img.img, &all->img.bits_per_pixel, &all->img.line_length, &all->img.endian);
	print(all);
	mlx_hook(all->mlx.win, 17, 1L << 0, close_win, &all->img);
	mlx_hook(all->mlx.win, 2, 1L << 0, key_hook, all);
	// mlx_loop_hook(all->mlx.mlx, moving, all);
	mlx_loop(all->mlx.mlx);
}
