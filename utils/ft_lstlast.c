/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjammie <mjammie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 14:16:30 by mjammie           #+#    #+#             */
/*   Updated: 2021/08/02 14:28:34 by mjammie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

t_lst	*ft_lstlast(t_lst *lst)
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
	return (lst);
}
