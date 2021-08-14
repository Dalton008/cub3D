/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_colour.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjammie <mjammie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 03:03:50 by lgarg             #+#    #+#             */
/*   Updated: 2021/08/14 19:07:46 by mjammie          ###   ########.fr       */
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

int	check_didgit(char **temp, t_lst *lst)
{	
	int		i;
	int		j;

	i = 0;
	while (temp[i])
	{
		j = 0;
		while (temp[i][j])
		{
			if (!ft_isdigit_fixed(temp[i][j]))
				colour_error(lst);
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
		colour_error(lst);
	check_didgit(temp, lst);
	get_rgb(all, temp);
	ft_free_everything(temp);
	if (all->path->red > 255 || all->path->red < 0 || all->path->green > 255 \
	|| all->path->green < 0 || all->path->blue > 255 || all->path->blue < 0)
		colour_error(lst);
	res = make_rgb_colour(all);
	return (res);
}
