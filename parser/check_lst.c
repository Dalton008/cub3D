/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_lst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgarg <lgarg@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 18:03:10 by mjammie           #+#    #+#             */
/*   Updated: 2021/08/14 13:16:19 by lgarg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	check_lst(t_lst *lst, t_all *all)
{
	t_lst	*head;
	int		i;

	i = 0;
	head = lst;
	while (lst)
	{
		if (check_key(lst->str) == 0)
		{
			all->count++;
		}
		lst = lst->next;
	}
	all->count--;
	lst = head;
	parse_map(all, lst);
	max_height_map(all);
}
