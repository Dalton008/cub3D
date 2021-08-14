/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgarg <lgarg@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 18:02:10 by mjammie           #+#    #+#             */
/*   Updated: 2021/08/14 13:16:50 by lgarg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	parse_map(t_all *all, t_lst *lst)
{
	int	i;

	i = 0;
	all->map_c = (char **)malloc(sizeof(char *) * (ft_lstsize(lst) - \
		all->count));
	all->map_c[ft_lstsize(lst) - all->count] = NULL;
	while (i < (all->count + 1))
	{
		lst = lst->next;
		i++;
	}
	i = 0;
	while (lst)
	{
		all->map_c[i] = lst->str;
		lst = lst->next;
		i++;
		all->map_max_height++;
	}
	all->map_c[i] = NULL;
}
