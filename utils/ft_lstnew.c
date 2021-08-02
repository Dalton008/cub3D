/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjammie <mjammie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 14:16:43 by mjammie           #+#    #+#             */
/*   Updated: 2021/08/02 14:28:50 by mjammie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

t_lst	*ft_lstnew(void *content)
{
	t_lst	*list;

	list = (struct s_lst *)malloc(sizeof(t_lst));
	if (list == 0)
		return (0);
	list->str = content;
	list->next = NULL;
	return (list);
}
