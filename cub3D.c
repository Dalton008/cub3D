/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjammie <mjammie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 14:00:18 by mjammie           #+#    #+#             */
/*   Updated: 2021/08/05 19:19:01 by mjammie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3D.h"

void	parse_map(t_all *all, t_lst *lst)
{
	int	i;

	i = 0;
	all->map_c = (char **)malloc(sizeof(char *) * (ft_lstsize(lst) - 7));
	all->map_c[ft_lstsize(lst) - 7] = NULL;
	while (i < 8)
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
	}
	all->map_c[i] = NULL;
	// i = 0;
	// while (map->map[i] != NULL)
	// {
	// 	ft_putstr_fd(map->map[i], 1);
	// 	ft_putchar_fd('\n', 1);
	// 	i++;
	// }
}

void	change_map_int(t_all *all, t_lst *lst)
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
				all->player.posX = (double)i + 0.5;
				all->player.posY = (double)j + 0.5;
				all->map[i][j] = 0;
			}
			j++;
		}
		lst = lst->next;
		i++;
	}
}

void	check_lst(t_lst *lst, t_all *all)
{
	int		count;
	t_lst	*head;
	int		i;

	i = 0;
	head = lst;
	count = 0;
	while (lst)
	{
		if (check_key(lst->str) == 0)
		{
			printf("%s\n", lst->str);
			count++;
		}
		lst = lst->next;
	}
	count--;
	printf("%d\n", count);
	lst = head;
	if (count != 7)
		exit (0);
	else
	{
		parse_map(all, lst);
	}
}

int	main(int argc, char **argv)
{
	t_all	*all;
	t_lst	*lst;
	t_paths	path;
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
	check_lst(lst, all);
	main_check(lst, all);
	parse_info(lst, &path, all);
	change_map_int(all, lst);
	raycaster(all);
}
