/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_colour.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjammie <mjammie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 03:03:50 by lgarg             #+#    #+#             */
/*   Updated: 2021/08/06 15:38:07 by mjammie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"


int	make_rgb_colour(int red, int green, int blue)
{
	return (red << 16 | green << 8 | blue);
}

int	get_colour(char *line, t_lst *lst, t_all *all)
{
	char **temp;
	int	red;
	int	green;
	int	blue;
	int	res;

	if (!line)
		return (0);
	temp = ft_split(line, ',');
	if (ft_splitlen(temp) != 3)
	{
		lst->error = BAD_COLOUR;
		main_check(lst, all);
	}
	int	i;
	int	j;

	i = 0;
	while (temp[i])
	{
		j = 0;
		while (temp[i][j])
		{
			if (!ft_isdigit(temp[i][j]))
			{
				lst->error = BAD_COLOUR;
				main_check(lst, all);	
			}
			j++;
		}
		i++;
	}
	red = ft_atoi(temp[0]);
	green = ft_atoi(temp[1]);
	blue = ft_atoi(temp[2]);
	free(temp);
	printf("red: %d, green: %d, blue: %d\n", red, green, blue);
	if (red > 255 || red < 0 || green > 255 || green < 0 || blue > 255 || blue < 0)
	{
		lst->error = BAD_COLOUR;
		main_check(lst, all);
	}
	res = make_rgb_colour(red, green, blue);
	printf("%x\n", res);
// то, что ниже, это кодирование отдельных компонентов RGB в целочисленное значение с помощью битового сдвига
	return (res);
}