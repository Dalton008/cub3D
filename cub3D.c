/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjammie <mjammie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 14:00:18 by mjammie           #+#    #+#             */
/*   Updated: 2021/08/03 16:47:36 by mjammie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3D.h"

void	parse_map(t_all *all, t_lst *lst)
{
	int	i;

	i = 0;
	all->map = (char **)malloc(sizeof(char *) * (ft_lstsize(lst) - 7));
	while (i < 8)
	{
		lst = lst->next;
		i++;
	}
	i = 0;
	while (lst)
	{
		all->map[i] = lst->str;
		lst = lst->next;
		i++;
	}
	all->map[i] = NULL;
}

int	main(int argc, char **argv)
{
	t_all	*all;
	t_lst	*lst;
	t_lst	*head;
	int		fd;
	char	*line;

	all = malloc(sizeof(t_all));
	if (argc == 2)
		fd = open(argv[1], O_RDONLY);
	else
		return (0);
	line = NULL;
	while (get_next_line(fd, &line))
		ft_lstadd_back(&lst, ft_lstnew(line));
	head = lst;
	parse_map(all, lst);
	work_with_map(all);
}
