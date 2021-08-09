/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_for_raycasting.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjammie <mjammie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 14:09:59 by mjammie           #+#    #+#             */
/*   Updated: 2021/08/09 15:44:38 by mjammie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

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
	color = *(unsigned int *)addr;
	return (color);
}

void	optimization_color_img(t_all *all, int ***arr, char *path)
{
	int		n;
	int		m;
	int		x;
	int		y;
	t_data	new_img;

	x = -1;
	n = 0;
	m = 0;
	new_img.img = mlx_xpm_file_to_image(all->mlx.mlx, path, &n, &m);
	if (!new_img.img)
	{
		printf("Error\nWrong path to texture!!!\n");
		exit(0);
	}
	new_img.addr = mlx_get_data_addr(new_img.img, &new_img.bits_per_pixel, \
		&new_img.line_length, &new_img.endian);
	(*arr) = (int **)malloc(sizeof(int *) * n);
	while (++x < TEX_WIDTH)
	{
		y = -1;
		(*arr)[x] = (int *)malloc(sizeof(int) * m);
		while (++y < TEX_HEIGHT)
			(*arr)[x][y] = texpixcolor(&new_img, x, y);
	}
}

void	init_struct_raycasting(t_for_raycasting *st)
{
	st->camera_x = 0;
	st->ray_dir_x = 0;
	st->ray_dir_y = 0;
	st->side_dist_x = 0;
	st->side_dist_y = 0;
	st->dlt_dist_x = 0;
	st->delta_dist_y = 0;
	st->perp_wall_dist = 0;
	st->map_x = 0;
	st->map_y = 0;
	st->step_x = 0;
	st->step_y = 0;
	st->hit = 0;
	st->side = 0;
	st->line_height = 0;
	st->draw_start = 0;
	st->draw_end = 0;
	st->wall_x = 0;
	st->color = 0;
	st->step = 0;
	st->tex_pos = 0;
	st->tex_x = 0;
	st->tex_y = 0;
}

void	new_init(t_all *all, int x)
{
	all->rc.camera_x = 2 * x / (double)SCREEN_WIDTH - 1;
	all->rc.ray_dir_x = all->player.dirX + all->player.planeX * \
		all->rc.camera_x;
	all->rc.ray_dir_y = all->player.dirY + all->player.planeY * \
		all->rc.camera_x;
	all->rc.map_x = (int)(all->player.posX);
	all->rc.map_y = (int)(all->player.posY);
	all->rc.dlt_dist_x = fabs(1 / all->rc.ray_dir_x);
	all->rc.delta_dist_y = fabs(1 / all->rc.ray_dir_y);
	all->rc.hit = 0;
}
