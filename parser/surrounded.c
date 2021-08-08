/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   surrounded.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjammie <mjammie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 02:38:27 by lgarg             #+#    #+#             */
/*   Updated: 2021/08/08 12:11:36 by mjammie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	check_line_for_wals(char *line, char *next, char *last) // все стены единички
{
	int	i;

	i = 0;
	while (line[i] == ' ')
		i++;
	while (line[i])
	{
		if (!ft_check(line[i], " 210NWSE") || ((line[i + 1] == ' ' \
							|| line[i - 1] == ' ') && line[i] != '1'))
			return (1);
		if ((line[i] == '0' && next[i] == ' ') \
							|| (line[i] == '0' && last[i] == ' '))
			return (1);
		i++;
	}
	return (0);
}

int	check_first_last_line(char *line) // чек верхней и нижней строки
{
	int	i;

	i = 0;
	while (line[i] == ' ')
		i++;
	while (line[i])
	{
		if (!ft_check(line[i], " 1") || ((line[i + 1] == ' ' || line[i - 1] == ' ') && line[i] != '1'))
			return (1);
		i++;
	}
	return (0);
}

int	if_surrounded_by_wals(t_lst *lst, t_all *all)
{
	int	i;
	int	len;

	len = ft_splitlen(all->map_c);
	i = 0;
	while (all->map_c[i])
	{
		if (i == 0 || i == len - 1)
		{
			if (check_first_last_line(all->map_c[i]))
			{
				lst->error = BAD_MAP;
				return (1); // плохо
			}
			else
				i++;
		}
		else 
		{
			if (check_line_for_wals(all->map_c[i], all->map_c[i + 1], all->map_c[i - 1]))
			{
				lst->error = BAD_MAP;
				return (1); // плохо
			}
		}
		i++;
	}
	return (0); // хорошо
}
