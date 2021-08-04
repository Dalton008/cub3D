/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjammie <mjammie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 14:00:18 by mjammie           #+#    #+#             */
/*   Updated: 2021/08/04 21:05:42 by mjammie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3D.h"

void	parse_map(t_all *all, t_lst *lst)
{
	t_lst *h;
	int	i;
	int	j;

	i = 0;
	j = 0;
	all->map = (int **)malloc(sizeof(int *) * (ft_lstsize(lst) - 7));
	while (i < 8)
	{
		lst = lst->next;
		i++;
	}
	i = 0;
	h = lst;
	while (lst)
	{
		j = 0;
		all->map[i] = malloc(sizeof(int) * ft_strlen(lst->str));
		while (lst->str[j])
		{
			all->map[i][j] = lst->str[j] - 48;
			if (all->map[i][j] == -16)
				all->map[i][j] = 1;
			if (all->map[i][j] == 30)
			{
				all->player.posX = (double)i;
				all->player.posY = (double)j;
				all->map[i][j] = 0;
			}
			j++;
		}
		lst = lst->next;
		i++;
	}
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
	raycaster(all);
}
