/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjammie <mjammie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 15:49:33 by lgarg             #+#    #+#             */
/*   Updated: 2021/08/06 21:24:34 by mjammie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	right_simbols_in_map(t_lst *lst, t_all *all) // валидные символы
{
	int	i;
	int	j;

	i = 0;
	while (all->map_c[i])
	{
		j = 0;
		while (all->map_c[i][j])
		{
			if (!ft_check(all->map_c[i][j], "10 NESW"))
			{
				lst->error = BAD_MAP;
				return (1); // плохо
			}
			j++;
		}
		i++;
	}
	return(0); // хорошо
}

int	how_many_players(t_lst *lst, t_all *all) // больше одного игрока
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
		return (1); // плохо
	}
	return (0); // хорошо
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

void	main_check(t_lst *lst, t_all *all)
{
	if (right_simbols_in_map(lst, all) == 1 || how_many_players(lst, all) == 1 || if_surrounded_by_wals(lst, all) == 1 \
	|| check_corners(lst, all) == 1 || lst->error != 0 || right_key(lst) == 1 || dublicate_texture(lst) == 1 \
	|| dublicate_colour(lst) == 1)
	{
		check_map(lst);
	}
}
