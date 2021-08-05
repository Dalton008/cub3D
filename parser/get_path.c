/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjammie <mjammie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 03:02:10 by lgarg             #+#    #+#             */
/*   Updated: 2021/08/05 18:31:21 by mjammie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	get_path(char *line, t_paths *path, t_lst *lst, t_all *all)
{
	if (ft_strncmp("NO ", line, 3) == 0)
	{
		path->north_path = ft_strtrim(line + 3, " ");
		if (path->north_path[0] == '\0')
		{
			lst->error = BAD_TEXTURE;
			main_check(lst, all);
		}
	}
	else if (ft_strncmp("SO ", line, 3) == 0)
	{
		path->south_path = ft_strtrim(line + 3, " ");
		if (path->south_path[0] == '\0')
		{
			lst->error = BAD_TEXTURE;
			main_check(lst, all);
		}
	}
	else if (ft_strncmp("WE ", line, 3) == 0)
	{
		path->west_path = ft_strtrim(line + 3, " ");
		if (path->west_path[0] == '\0')
		{
			lst->error = BAD_TEXTURE;
			main_check(lst, all);
		}
	}
	else if (ft_strncmp("EA ", line, 3) == 0)
	{
		path->east_path = ft_strtrim(line + 3, " ");
		if (path->east_path[0] == '\0')
		{
			lst->error = BAD_TEXTURE;
			main_check(lst, all);
		}
	}
	else if (ft_strncmp("F ", line, 2) == 0)
		path->floor_colour = get_colour(line + 2, lst, all);
	else if (ft_strncmp("C ", line, 2) == 0)
		path->celling_colour = get_colour(line + 2, lst, all);
}
