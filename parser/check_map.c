/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjammie <mjammie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 15:49:33 by lgarg             #+#    #+#             */
/*   Updated: 2021/08/14 19:39:23 by mjammie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	right_simbols_in_map(t_lst *lst, t_all *all)
{
	int	i;
	int	j;

	i = 0;
	while (all->map_c[i])
	{
		j = 0;
		while (all->map_c[i][j])
		{
			if (!ft_check(all->map_c[i][j], "210 NESWD"))
			{
				lst->error = BAD_MAP;
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	how_many_players(t_lst *lst, t_all *all)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (all->map_c[i])
	{
		j = 0;
		while (all->map_c[i][j])
		{
			if (ft_check(all->map_c[i][j], "NSEW"))
				count++;
			j++;
		}
		i++;
	}
	if (count != 1)
	{
		lst->error = BAD_MAP;
		return (1);
	}
	return (0);
}

void	check_map(t_lst *lst)
{
	if (lst->error == BAD_MAP)
		ft_putstr_fd("Error\nInvalid map\n", 1);
	else if (lst->error == DUBLICATE_TEX)
		ft_putstr_fd("Error\nDublicte texture\n", 1);
	else if (lst->error == NOT_ENOUGHT_TEX)
		ft_putstr_fd("Error\nNot enought textures\n", 1);
	else if (lst->error == DUBLICATE_COLOUR)
		ft_putstr_fd("Error\nDublicate colour\n", 1);
	else if (lst->error == NOT_ENOUGHT_COLOUR)
		ft_putstr_fd("Error\nNot enought colour\n", 1);
	else if (lst->error == BAD_TEXTURE)
		ft_putstr_fd("Error\nTexture error\n", 1);
	else if (lst->error == BAD_KEY)
		ft_putstr_fd("Error\nKey error\n", 1);
	else if (lst->error == BAD_COLOUR)
		ft_putstr_fd("Error\nColour error\n", 1);
	ft_putstr_fd("Quit cub3D\n", 1);
	exit (0);
}

void	valid_map(t_lst *lst, t_all *all)
{
	int	i;
	int	j;

	i = 0;
	while (all->map_c[i])
	{
		j = 0;
		while (all->map_c[i][j] != '\0')
		{
			if (ft_check(all->map_c[i][j], "02NSEW"))
			{
				if (i == 0 || j == 0 || i == all->map_max_height - 1 \
							|| j == all->map_max_width - 1)
					map_error(lst);
				else
				{
					check_validation(lst, all, j, i);
					check_validation_second(lst, all, j, i);
				}
			}
			j++;
		}
		i++;
	}
}

void	main_check(t_lst *lst, t_all *all)
{
	valid_map(lst, all);
	if (right_simbols_in_map(lst, all) == 1 || how_many_players(lst, all) == 1 \
		|| lst->error != 0 || right_key(lst, all) == 1 \
		|| dublicate_texture(lst, all) == 1 \
		|| dublicate_colour(lst, all) == 1)
	{
		check_map(lst);
	}
}
