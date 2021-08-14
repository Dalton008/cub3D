/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_open_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgarg <lgarg@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 18:07:17 by mjammie           #+#    #+#             */
/*   Updated: 2021/08/14 13:16:31 by lgarg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	open_map_error(char *str)
{
	ft_putstr_fd(str, 1);
	exit (1);
}

void	check_open_map(char **argv, int fd)
{
	char	buf[10];
	int		try_to_read;

	if (ft_strnstr(&argv[1][ft_strlen(argv[1]) - 4], ".cub", 4) != 0)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd != -1)
		{
			try_to_read = read(fd, buf, 10);
			if (try_to_read == 0 || try_to_read == -1)
				open_map_error("Error\nEmpty file\n");
		}
		else
			open_map_error("Error\nCouldn't open file\n");
	}
	else
		open_map_error("Error\nFile must be .cub extension\n");
}
