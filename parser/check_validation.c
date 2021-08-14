/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgarg <lgarg@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 19:44:18 by lgarg             #+#    #+#             */
/*   Updated: 2021/08/14 13:16:33 by lgarg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	check_validation_second(t_lst *lst, t_all *all, int j, int i)
{
	while (i > 0 && all->map_c[i][j] != '1')
	{
		if (all->map_c[i][j] == ' ' || all->map_c[i][j] == '\0')
			map_error(lst);
		i--;
	}
	while (j > 0 && all->map_c[i][j] != '1')
	{
		if (all->map_c[i][j] == ' ' || all->map_c[i][j] == '\0')
			map_error(lst);
		j--;
	}
}

void	check_validation(t_lst *lst, t_all *all, int j, int i)
{
	if (all->map_c[i][j] == '0' &&
		(all->map_c[i + 1][j] == ' ' || all->map_c[i + 1][j - 1] == ' ' \
	|| all->map_c[i + 1][j + 1] == ' ' || all->map_c[i][j - 1] == ' ' \
	|| all->map_c[i][j - 1] == ' ' || all->map_c[i - 1][j] == ' ' \
	|| all->map_c[i - 1][j - 1] == ' ' || all->map_c[i - 1][j + 1] == ' '))
		map_error(lst);
	while (i < all->map_max_height && all->map_c[i][j] != '1')
	{
		if (all->map_c[i][j] == ' ' || all->map_c[i][j] == '\0')
			map_error(lst);
		i++;
	}
	while (j < all->map_max_width && all->map_c[i][j] != '1')
	{
		if (all->map_c[i][j] == ' ' || all->map_c[i][j] == '\0')
			map_error(lst);
		j++;
	}
}
