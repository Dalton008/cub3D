/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dublicate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjammie <mjammie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 02:32:45 by lgarg             #+#    #+#             */
/*   Updated: 2021/08/05 18:30:58 by mjammie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	dublicate_texture(t_lst *lst)
{
	int	no_count;
	int	so_count;
	int we_count;
	int	ea_count;
	t_lst	*head;

	no_count = 0;
	so_count = 0;
	we_count = 0;
	ea_count = 0;
	head = lst;
	while (lst)
	{
		if (ft_strnstr(lst->str, "NO ", 3) != 0)
			no_count++;
		else if (ft_strnstr(lst->str, "SO ", 3) != 0)
			so_count++;
		else if (ft_strnstr(lst->str, "WE ", 3) != 0)
			we_count++;
		else if (ft_strnstr(lst->str, "EA ", 3) != 0)
			ea_count++;
		lst = lst->next;
	}
	if (no_count > 1 || so_count > 1 || we_count > 1 || ea_count > 1)
	{
		lst = head;
		lst->error = DUBLICATE_TEX;
		return (1);
	}
	else if (no_count == 0 || so_count == 0 || we_count == 0 || ea_count == 0)
	{
		lst = head;
		lst->error = NOT_ENOUGHT_TEX;
		return (1);	
	}
	else
		return (0);
}

int	dublicate_colour(t_lst *lst)
{
	int	f_count;
	int	c_count;
	t_lst	*head;

	f_count = 0;
	c_count = 0;
	head = lst;
	while (lst)
	{
		if (ft_strnstr(lst->str, "F ", 2) != 0)
			f_count++;
		if (ft_strnstr(lst->str, "C ", 2) != 0)
			c_count++;
		lst = lst->next;
	}
	if (f_count > 1 || c_count > 1)
	{
		lst = head;
		lst->error = DUBLICATE_COLOUR;
		return (1);
	}
	else if (f_count == 0 || c_count == 0)
	{
		lst = head;
		lst->error = NOT_ENOUGHT_COLOUR;
		return (1);
	}
	return (0);
}
