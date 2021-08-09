/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_open_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjammie <mjammie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 18:07:17 by mjammie           #+#    #+#             */
/*   Updated: 2021/08/09 18:13:03 by mjammie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

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
			if (try_to_read == 0)
			{
				ft_putstr_fd("Error\nEmpty file\n", 1);
				exit (1);
			}
		}
		else
		{
			ft_putstr_fd("Error\nCouldn't open file\n", 1);
			exit (1);
		}
	}
	else
	{
		ft_putstr_fd("Error\nFile must be .cub extension\n", 1);
		exit (1);
	}
}
