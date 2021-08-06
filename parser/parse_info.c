/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjammie <mjammie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 01:39:35 by lgarg             #+#    #+#             */
/*   Updated: 2021/08/06 21:05:17 by mjammie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	parse_info(t_lst *lst, t_all *all)
{
	int	i;

	i = 0;
	while (i < all->count)
	{
		get_path(lst->str, lst, all);
		lst = lst->next;
		i++;
	}
	// printf("%s\n", path->north_path);
	// printf("%s\n", path->south_path);
	// printf("%s\n", path->west_path);
	// printf("%s\n", path->east_path);
	// printf("%d\n", path->floor_colour);
	// printf("%d\n", path->celling_colour);
}