/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjammie <mjammie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 03:02:10 by lgarg             #+#    #+#             */
/*   Updated: 2021/08/06 15:28:22 by mjammie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	get_path(char *line, t_lst *lst, t_all *all)
{
	if (ft_strncmp("NO ", line, 3) == 0)
	{
		all->path->north_path = ft_strtrim(line + 3, " ");
		if (all->path->north_path[0] == '\0')
		{
			lst->error = BAD_TEXTURE;
			main_check(lst, all);
		}
	}
	else if (ft_strncmp("SO ", line, 3) == 0)
	{
		all->path->south_path = ft_strtrim(line + 3, " ");
		if (all->path->south_path[0] == '\0')
		{
			lst->error = BAD_TEXTURE;
			main_check(lst, all);
		}
	}
	else if (ft_strncmp("WE ", line, 3) == 0)
	{
		all->path->west_path = ft_strtrim(line + 3, " ");
		if (all->path->west_path[0] == '\0')
		{
			lst->error = BAD_TEXTURE;
			main_check(lst, all);
		}
	}
	else if (ft_strncmp("EA ", line, 3) == 0)
	{
		all->path->east_path = ft_strtrim(line + 3, " ");
		if (all->path->east_path[0] == '\0')
		{
			lst->error = BAD_TEXTURE;
			main_check(lst, all);
		}
	}
	else if (ft_strncmp("F ", line, 2) == 0)
		all->path->floor_colour = get_colour(line + 2, lst, all);
	else if (ft_strncmp("C ", line, 2) == 0)
		all->path->celling_colour = get_colour(line + 2, lst, all);
}
