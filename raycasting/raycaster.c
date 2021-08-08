/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjammie <mjammie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 13:55:42 by mjammie           #+#    #+#             */
/*   Updated: 2021/08/08 18:55:51 by mjammie          ###   ########.fr       */
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
	double step = 0;
	double texPos = 0;
	int texY = 0;

	double	ZBuffer[SCREEN_WIDTH];
	
	int spriteOrder[all->count_sprites];
	double spriteDistance[all->count_sprites];

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
			if (all->map[mapX][mapY] > 0 && all->map[mapX][mapY] != 2)
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
			color = all->colors_sprite[texX][texY];
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
			if (side == 1)
				color = (color >> 1) & 8355711;
			my_mlx_pixel_put(&all->img, x, i, color);
			i++;
		}
		while (i < SCREEN_HEIGHT)
		{
			my_mlx_pixel_put(&all->img, x, i, all->path->floor_colour);
			i++;
		}
		ZBuffer[x] = perpWallDist;
		x++;
	}

	for (int i = 0; i < all->count_sprites; i++)
    {
		spriteOrder[i] = i;
		spriteDistance[i] = ((all->player.posX - all->sprites.x[i]) * (all->player.posX - all->sprites.x[i]) + (all->player.posY - all->sprites.y[i]) * (all->player.posY -  all->sprites.y[i]));
    }

    sortSprites(spriteOrder, spriteDistance, all);

    for (int i = 0; i < all->count_sprites; i++)
    {
		double spriteX = all->sprites.x[i] - all->player.posX;
		double spriteY = all->sprites.y[i] - all->player.posY;
		double invDet = 1.0 / (all->player.planeX * all->player.dirY - all->player.dirX * all->player.planeY);
		double transformX = invDet * (all->player.dirY * spriteX - all->player.dirX * spriteY);
		double transformY = invDet * (-all->player.planeY * spriteX + all->player.planeX * spriteY);
		int spriteScreenX = (int)((SCREEN_WIDTH / 2) * (1 + transformX / transformY));

		#define uDiv 1
		#define vDiv 1
		#define vMove 0.0

		int vMoveScreen = (int)(vMove / transformY);		
		int spriteHeight = abs((int)(SCREEN_HEIGHT / (transformY))) / vDiv; 
		int drawStartY = -spriteHeight / 2 + SCREEN_HEIGHT / 2 + vMoveScreen;
		if (drawStartY < 0)
			drawStartY = 0;
		int drawEndY = spriteHeight / 2 + SCREEN_HEIGHT / 2 + vMoveScreen;
		if (drawEndY >= SCREEN_HEIGHT) 
			drawEndY = SCREEN_HEIGHT - 1;		
		int spriteWidth = abs( (int) (SCREEN_HEIGHT / (transformY))) / uDiv;
		int drawStartX = -spriteWidth / 2 + spriteScreenX;
		if (drawStartX < 0)
			drawStartX = 0;
		int drawEndX = spriteWidth / 2 + spriteScreenX;
		if (drawEndX >= SCREEN_WIDTH)
			drawEndX = SCREEN_WIDTH - 1;
		for (int stripe = drawStartX; stripe < drawEndX; stripe++)
		{
			int texX = (int)(256 * (stripe - (-spriteWidth / 2 + spriteScreenX)) * texWidth / spriteWidth) / 256;
			if (transformY > 0 && stripe > 0 && stripe < SCREEN_WIDTH && transformY < ZBuffer[stripe])
			for (int y = drawStartY; y < drawEndY; y++)
			{
					int d = (y - vMoveScreen) * 256 - SCREEN_HEIGHT * 128 + spriteHeight * 128;
					int texY = ((d * texHeight) / spriteHeight) / 256;
					int color = all->colors_sprite[0][texWidth * texX + texY];
					if ((color & 0x00FFFFFF) != 0)
				  		my_mlx_pixel_put(&all->img, stripe, y, color);
			}
		}
    }
	mlx_put_image_to_window(all->mlx.mlx, all->mlx.win, all->img.img, 0, 0);
}

void	sortSprites(int *spriteOrder, double *spriteDistance, t_all *all)
{
	int			i;
	double		temp;

	i = 0;
	temp = 0;
	while (i < all->count_sprites)
	{
		if (spriteDistance[i] < spriteDistance[i + 1])
		{
			temp = spriteDistance[i];
			spriteDistance[i] = spriteDistance[i + 1];
			spriteDistance[i + 1] = temp;
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

int	key_hook(int keycode, t_all *all)
{
	int		x;
	int		y;

	if (all->mini.on % 2 == 0)
		mlx_destroy_image(all->mlx.mlx, all->img_map.img);
	if (keycode == 53)
	{
		ft_putstr_fd("Close window\n", 1);
		exit(1);
	}
	moves(all, keycode);
	mlx_destroy_image(all->mlx.mlx, all->img.img);
	all->img.img = mlx_new_image(all->mlx.mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	all->img.addr = mlx_get_data_addr(all->img.img, &all->img.bits_per_pixel, &all->img.line_length, &all->img.endian);
	print(all);
	if (keycode == 48)
		all->mini.on++;
	if (all->mini.on % 2 == 0)
	{
		all->img_map.img = mlx_new_image(all->mlx.mlx, all->map_max_width * 10, all->map_max_height * 10);
		all->img_map.addr = mlx_get_data_addr(all->img_map.img, &all->img_map.bits_per_pixel, &all->img_map.line_length, &all->img_map.endian);
		print_mini_map(all);
		print_player(all, 0xfa0000);
		mlx_put_image_to_window(all->mlx.mlx, all->mlx.win, all->img_map.img, 10, 10);
	}
	return (0);
}

int	mouse_hook(int keycode, t_all *all)
{
	printf("%d\n", keycode);
	return (0);
}

void	raycaster(t_all *all)
{
	int	x;
	int	y;
	// int	x1;
	// int	y1;

	y = 0;
	all->mini.on = 1;
	all->mlx.mlx = mlx_init();
	all->mlx.win = mlx_new_window(all->mlx.mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "cub3D");
	all->img.img = mlx_new_image(all->mlx.mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	all->img.addr = mlx_get_data_addr(all->img.img, &all->img.bits_per_pixel, &all->img.line_length, &all->img.endian);
	all->img_map.img = mlx_new_image(all->mlx.mlx, all->map_max_width * 10, all->map_max_height * 10);
	all->img_map.addr = mlx_get_data_addr(all->img_map.img, &all->img_map.bits_per_pixel, &all->img_map.line_length, &all->img_map.endian);
	optimization_color_img(all, &all->colors_north, all->path->north_path);
	optimization_color_img(all, &all->colors_south, all->path->south_path);
	optimization_color_img(all, &all->colors_west, all->path->west_path);
	optimization_color_img(all, &all->colors_east, all->path->east_path);
	optimization_color_img(all, &all->colors_sprite, "textures/barrel.xpm");
	print(all);
	mlx_hook(all->mlx.win, 17, 1L << 0, close_win, &all->img);
	mlx_hook(all->mlx.win, 2, 1L << 0, key_hook, all);
	// mlx_mouse_hook(all->mlx.win, mouse_hook, all);
	mlx_loop(all->mlx.mlx);
}
