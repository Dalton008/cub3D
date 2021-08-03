/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjammie <mjammie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 14:17:01 by mjammie           #+#    #+#             */
/*   Updated: 2021/08/02 14:28:44 by mjammie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	ft_lstsize(t_lst *lst)
{
	int	i;

	i = 0;
	if (!lst)
		return (0);
	while (lst->next != 0)
	{
		i++;
		lst = lst->next;
	}
	return (i + 1);
}
