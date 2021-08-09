/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_colour.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgarg <lgarg@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 03:03:50 by lgarg             #+#    #+#             */
/*   Updated: 2021/08/09 16:25:22 by lgarg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

static int	make_rgb_colour(t_all *all)
{
	return (all->path->red << 16 | all->path->green << 8 \
										| all->path->blue);
}

void	get_rgb(t_all *all, char **temp)
{
	all->path->red = ft_atoi(temp[0]);
	all->path->green = ft_atoi(temp[1]);
	all->path->blue = ft_atoi(temp[2]);
}

void	colour_error(t_lst *lst, t_all *all)
{
	lst->error = BAD_COLOUR;
	main_check(lst, all);
}

int	check_didgit(char **temp, t_lst *lst, t_all *all)
{	
	int		i;
	int		j;

	i = 0;
	while (temp[i])
	{
		j = 0;
		while (temp[i][j])
		{
			if (!ft_isdigit(temp[i][j]))
				colour_error(lst, all);
			j++;
		}
		i++;
	}
	return (0);
}

int	get_colour(char *line, t_lst *lst, t_all *all)
{
	char	**temp;
	int		res;

	if (!line)
		return (0);
	temp = ft_split(line, ',');
	if (ft_splitlen(temp) != 3)
	{
		lst->error = BAD_COLOUR;
		main_check(lst, all);
	}
	check_didgit(temp, lst, all);
	get_rgb(all, temp);
	free(temp);
	if (all->path->red > 255 || all->path->red < 0 || all->path->green > 255 \
	|| all->path->green < 0 || all->path->blue > 255 || all->path->blue < 0)
		colour_error(lst, all);
	res = make_rgb_colour(all);
	return (res);
}
