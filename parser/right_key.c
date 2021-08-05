/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   right_key.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjammie <mjammie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 02:31:17 by lgarg             #+#    #+#             */
/*   Updated: 2021/08/05 18:31:25 by mjammie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	check_key(char *line)
{
	if (ft_strncmp("NO ", line, 3) == 0) // нашел NO
		return (0);
	else if (ft_strncmp("SO ", line, 3) == 0)
		return (0);
	else if (ft_strncmp("WE ", line, 3) == 0)
		return (0);
	else if (ft_strncmp("EA ", line, 3) == 0)
		return (0);
	else if (ft_strncmp("F ", line, 2) == 0)
		return (0);
	else if (ft_strncmp("C ", line, 2) == 0)
		return (0);
	else if (line[0] == '\0')
		return (0);
	return (1);
}

int	right_key(t_lst *lst)
{
	int		i;
	t_lst	*head;

	i = 0;
	head = lst;
	while (i < 7)
	{
		if (check_key(lst->str) == 1)
		{
			lst = head;
			lst->error = BAD_KEY;
			return (1);
		}
		lst = lst->next;
		i++;
	}
	return (0);
}
