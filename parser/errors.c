/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjammie <mjammie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 19:09:39 by lgarg             #+#    #+#             */
/*   Updated: 2021/08/14 19:39:27 by mjammie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	map_error(t_lst *lst)
{
	lst->error = BAD_MAP;
	check_map(lst);
}

void	colour_error(t_lst *lst)
{
	lst->error = BAD_COLOUR;
	check_map(lst);
}

void	texture_error(t_lst *lst)
{
	lst->error = BAD_TEXTURE;
	check_map(lst);
}
