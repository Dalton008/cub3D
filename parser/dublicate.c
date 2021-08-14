/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dublicate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgarg <lgarg@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 02:32:45 by lgarg             #+#    #+#             */
/*   Updated: 2021/08/14 13:16:39 by lgarg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

static int	error_textures(t_lst *lst, t_all *all, t_lst *head)
{
	if (all->path->no_count > 1 || all->path->so_count > 1 \
			|| all->path->we_count > 1 || all->path->ea_count > 1)
	{
		lst = head;
		lst->error = DUBLICATE_TEX;
		return (1);
	}
	else if (all->path->no_count == 0 || all->path->so_count == 0 \
			|| all->path->we_count == 0 || all->path->ea_count == 0)
	{
		lst = head;
		lst->error = NOT_ENOUGHT_TEX;
		return (1);
	}
	return (0);
}

int	dublicate_texture(t_lst *lst, t_all *all)
{
	t_lst	*head;

	head = lst;
	while (lst)
	{
		if (ft_strnstr(lst->str, "NO ", 3) != 0)
			all->path->no_count++;
		else if (ft_strnstr(lst->str, "SO ", 3) != 0)
			all->path->so_count++;
		else if (ft_strnstr(lst->str, "WE ", 3) != 0)
			all->path->we_count++;
		else if (ft_strnstr(lst->str, "EA ", 3) != 0)
			all->path->ea_count++;
		lst = lst->next;
	}
	if (error_textures(lst, all, head) == 1)
		return (1);
	else
		return (0);
}

static int	error_colour(t_lst *lst, t_all *all, t_lst *head)
{
	if (all->path->f_count > 1 || all->path->c_count > 1)
	{
		lst = head;
		lst->error = DUBLICATE_COLOUR;
		return (1);
	}
	else if (all->path->f_count == 0 || all->path->c_count == 0)
	{
		lst = head;
		lst->error = NOT_ENOUGHT_COLOUR;
		return (1);
	}
	return (0);
}

int	dublicate_colour(t_lst *lst, t_all *all)
{
	t_lst	*head;

	head = lst;
	while (lst)
	{
		if (ft_strnstr(lst->str, "F ", 2) != 0)
			all->path->f_count++;
		if (ft_strnstr(lst->str, "C ", 2) != 0)
			all->path->c_count++;
		lst = lst->next;
	}
	if (error_colour(lst, all, head) == 1)
		return (1);
	else
		return (0);
}
