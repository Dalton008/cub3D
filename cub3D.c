/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjammie <mjammie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 14:00:18 by mjammie           #+#    #+#             */
/*   Updated: 2021/08/09 20:15:50 by mjammie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3D.h"

void	change(t_lst *lst, int i, int *j, t_all *all)
{
	while (lst->str[(*j)])
	{
		all->map[i][(*j)] = lst->str[(*j)] - 48;
		if (all->map[i][(*j)] == -16)
			all->map[i][(*j)] = 1;
		if (all->map[i][(*j)] > 1 && all->map[i][(*j)] != 2 && \
			all->map[i][(*j)] != 20)
			set_coordinates(all, i, (*j));
		if (all->map[i][(*j)] == 2)
		{
			all->sprites.x[all->count_sprites] = i + 0.5;
			all->sprites.y[all->count_sprites] = (*j) + 0.5;
			all->count_sprites++;
		}
		(*j)++;
	}
}

void	change_map_to_int(t_all *all, t_lst *lst)
{
	t_lst	*h;
	int		i;
	int		j;
	int		c;

	i = 0;
	j = 0;
	c = 0;
	all->map = (int **)malloc(sizeof(int *) * (ft_lstsize(lst) - all->count));
	while (i < (all->count + 1))
	{
		lst = lst->next;
		i++;
	}
	i = 0;
	h = lst;
	while (lst)
	{
		j = 0;
		all->map[i] = malloc(sizeof(int) * ft_strlen(lst->str));
		change(lst, i, &j, all);
		lst = lst->next;
		i++;
	}
}

void	init_path(t_all *all)
{
	all->path->north_path = NULL;
	all->path->south_path = NULL;
	all->path->west_path = NULL;
	all->path->east_path = NULL;
	all->path->floor_colour = -1;
	all->path->celling_colour = -1;
	all->path->no_count = 0;
	all->path->so_count = 0;
	all->path->we_count = 0;
	all->path->ea_count = 0;
	all->path->f_count = 0;
	all->path->c_count = 0;
}

void	parse_and_check(t_all *all, t_lst *lst)
{
	check_lst(lst, all);
	main_check(lst, all);
	parse_info(lst, all);
	change_map_to_int(all, lst);
	max_height_map(all);
}

int	main(int argc, char **argv)
{
	t_all	*all;
	t_lst	*lst;
	char	*line;
	int		fd;

	fd = 0;
	all = malloc(sizeof(t_all));
	all->path = malloc(sizeof(t_paths));
	all->count = 0;
	all->count_sprites = 0;
	init_path(all);
	if (argc == 2)
		check_open_map(argv, fd);
	else
	{
		ft_putstr_fd("Error\nNot enought arguments\n", 1);
		exit(1);
	}
	fd = open(argv[1], O_RDONLY);
	line = NULL;
	while (get_next_line(fd, &line))
		ft_lstadd_back(&lst, ft_lstnew(line));
	parse_and_check(all, lst);
	raycaster(all);
}
