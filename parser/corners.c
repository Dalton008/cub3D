/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corners.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjammie <mjammie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 02:34:52 by lgarg             #+#    #+#             */
/*   Updated: 2021/08/05 18:30:53 by mjammie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	check_last_corner(char *line, char *last)
{
	int	i;

	i = 0;
	while (line[i])
	{
		while (line[i] == ' ')
			i++;
		if (((!line[i - 1] || line[i - 1] == ' ') || (!line[i + 1] || line[i + 1] == ' ')) && (last[i] != '1' || last[i] != '1'))
			return (1);
		i++;
	}
	return (0);
}

int	check_first_corner(char *line, char *next)
{
	int	i;

	i = 0;
	while (line[i])
	{
		while (line[i] == ' ')
			i++;
		if (((!line[i - 1] || line[i - 1] == ' ') || (!line[i + 1] || line[i + 1] == ' ')) && (next[i] != '1' || next[i] != '1'))
			return (1);
		i++;
	}
	return (0);
}

int	check_corners(t_lst *lst, t_all *all)
{
	int	i;
	int	len;

	i = 0;
	len = ft_splitlen(all->map_c);
	while (all->map_c[i])
	{
		if (i == 0)
		{
			if (check_first_corner(all->map_c[i], all->map_c[i + 1]))
			{
				lst->error = BAD_MAP;
				return (1); // плохо
			}
			else
				i++;
		}
		else if (i == len - 1)
		{
			if (check_last_corner(all->map_c[i], all->map_c[i - 1]))
			{
				lst->error = BAD_MAP;
				return (1); // плохо
			}
			else
				i++;
		}
		else
		{
			if (check_first_corner(all->map_c[i], all->map_c[i + 1]))
			{
				lst->error = BAD_MAP;
				return (1); // плохо
			}
			else
				i++;
		}
		i++;
	}
	return (0);
}
