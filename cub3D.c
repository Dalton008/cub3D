/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjammie <mjammie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 14:00:18 by mjammie           #+#    #+#             */
/*   Updated: 2021/08/02 15:11:41 by mjammie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3D.h"

void	parse_map(t_map *map, t_lst *lst)
{
	int	i;

	i = 0;
	map->map = (char **)malloc(sizeof(char *) * (ft_lstsize(lst) - 8));
	map->map[ft_lstsize(lst) - 8] = NULL;
	while (i < 8)
	{
		lst = lst->next;
		i++;
	}
	i = 0;
	while (lst)
	{
		map->map[i] = lst->str;
		lst = lst->next;
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_lst	*lst;
	t_lst	*head;
	t_map	map;
	int		fd;
	char	*line;

	if (argc == 2)
		fd = open(argv[1], O_RDONLY);
	else
		return (0);
	line = NULL;
	while (get_next_line(fd, &line))
		ft_lstadd_back(&lst, ft_lstnew(line));
	head = lst;
	parse_map(&map, lst);
	work_with_map(&map, lst);
}
