/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjammie <mjammie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 15:49:33 by lgarg             #+#    #+#             */
/*   Updated: 2021/08/05 18:35:48 by mjammie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

// char static	ft_check(char c, const char *set)
// {
// 	int	i;

// 	i = 0;
// 	while (set[i])
// 	{
// 		if (set[i] == c)
// 			return (1);
// 		i++;
// 	}
// 	return (0);
// }

int	right_simbols_in_map(t_lst *lst, t_all *all) // валидные символы
{
	int	i;
	int	j;

	i = 0;
	while (all->map_c[i])
	{
		j = 0;
		while (all->map_c[i][j])
		{
			if (!ft_check(all->map_c[i][j], "10 NESW"))
			{
				lst->error = BAD_MAP;
				return (1); // плохо
			}
			j++;
		}
		i++;
	}
	return(0); // хорошо
}

int	how_many_players(t_lst *lst, t_all *all) // больше одного игрока
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (all->map_c[i])
	{
		j = 0;
		while (all->map_c[i][j])
		{
			if (ft_check(all->map_c[i][j], "NSEW"))
				count++;
			j++;
		}
		i++;
	}
	if (count != 1)
	{
		lst->error = BAD_MAP;
		return (1); // плохо
	}
	return (0); // хорошо
}

// int	check_line_for_wals(char *line, char *next, char *last) // все стены единички
// {
// 	int	i;

// 	i = 0;
// 	while (line[i] == ' ')
// 		i++;
// 	while (line[i])
// 	{
// 		if (!ft_check(line[i], " 10NWSE") || ((line[i + 1] == ' ' \
// 							|| line[i - 1] == ' ') && line[i] != '1'))
// 			return (1);
// 		if ((line[i] == '0' && next[i] == ' ') \
// 							|| (line[i] == '0' && last[i] == ' '))
// 			return (1);
// 		i++;
// 	}
// 	return (0);
// }

// int	ft_splitlen(char **str)
// {
// 	int	i;

// 	i = 0;
// 	while (str[i])
// 		i++;
// 	return (i);
// }

// int	check_first_last_line(char *line) // чек верхней и нижней строкиfffcheello
// {
// 	int	i;

// 	i = 0;
// 	while (line[i] == ' ')
// 		i++;
// 	while (line[i])
// 	{
// 		if (!ft_check(line[i], " 1") || ((line[i + 1] == ' ' || line[i - 1] == ' ') && line[i] != '1'))
// 			return (1);
// 		i++;
// 	}
// 	return (0);
// }

// int	if_surrounded_by_wals(t_lst *lst, t_map map)
// {
// 	int	i;
// 	int	len;

// 	len = ft_splitlen(map.map);
// 	i = 0;
// 	while (map.map[i])
// 	{
// 		if (i == 0 || i == len - 1)
// 		{
// 			if (check_first_last_line(map.map[i]))
// 			{
// 				lst->error = BAD_MAP;
// 				return (1); // плохо
// 			}
// 			else
// 				i++;
// 		}
// 		else 
// 		{
// 			if (check_line_for_wals(map.map[i], map.map[i + 1], map.map[i - 1]))
// 			{
// 				lst->error = BAD_MAP;
// 				return (1); // плохо
// 			}
// 		}
// 		i++;
// 	}
// 	return (0); // хорошо
// }

// int	check_first_corner(char *line, char *next)
// {
// 	int	i;

// 	i = 0;
// 	while (line[i])
// 	{
// 		while (line[i] == ' ')
// 			i++;
// 		if (((!line[i - 1] || line[i - 1] == ' ') || (!line[i + 1] || line[i + 1] == ' ')) && (next[i] != '1' || next[i] != '1'))
// 			return (1);
// 		i++;
// 	}
// 	return (0);
// }

// int	check_last_corner(char *line, char *last)
// {
// 	int	i;

// 	i = 0;
// 	while (line[i])
// 	{
// 		while (line[i] == ' ')
// 			i++;
// 		if (((!line[i - 1] || line[i - 1] == ' ') || (!line[i + 1] || line[i + 1] == ' ')) && (last[i] != '1' || last[i] != '1'))
// 			return (1);
// 		i++;
// 	}
// 	return (0);
// }

// int	check_corners(t_lst *lst, t_map map)
// {
// 	int	i;
// 	int	len;

// 	i = 0;
// 	len = ft_splitlen(map.map);
// 	while (map.map[i])
// 	{
// 		if (i == 0)
// 		{
// 			if (check_first_corner(map.map[i], map.map[i + 1]))
// 			{
// 				lst->error = BAD_MAP;
// 				return (1); // плохо
// 			}
// 			else
// 				i++;
// 		}
// 		else if (i == len - 1)
// 		{
// 			if (check_last_corner(map.map[i], map.map[i - 1]))
// 			{
// 				lst->error = BAD_MAP;
// 				return (1); // плохо
// 			}
// 			else
// 				i++;
// 		}
// 		else
// 		{
// 			if (check_first_corner(map.map[i], map.map[i + 1]))
// 			{
// 				lst->error = BAD_MAP;
// 				return (1); // плохо
// 			}
// 			else
// 				i++;
// 		}
// 		i++;
// 	}
// 	return (0);
// }

// char	*ft_strnstr(const char *big, const char *little, size_t len)
// {
// 	size_t	lenght_l;

// 	lenght_l = ft_strlen(little);
// 	if (lenght_l == 0)
// 		return ((char *)big);
// 	while (len >= lenght_l)
// 	{
// 		if (*big == *little && (ft_strncmp(big, little, lenght_l) == 0))
// 			return ((char *)big);
// 		big++;
// 		len--;
// 	}
// 	return (0);
// }

// int	dublicate_texture(t_lst *lst)
// {
// 	int	no_count;
// 	int	so_count;
// 	int we_count;
// 	int	ea_count;
// 	t_lst	*head;

// 	no_count = 0;
// 	so_count = 0;
// 	we_count = 0;
// 	ea_count = 0;
// 	head = lst;
// 	while (lst)
// 	{
// 		if (ft_strnstr(lst->str, "NO ", 3) != 0)
// 			no_count++;
// 		else if (ft_strnstr(lst->str, "SO ", 3) != 0)
// 			so_count++;
// 		else if (ft_strnstr(lst->str, "WE ", 3) != 0)
// 			we_count++;
// 		else if (ft_strnstr(lst->str, "EA ", 3) != 0)
// 			ea_count++;
// 		lst = lst->next;
// 	}
// 	if (no_count > 1 || so_count > 1 || we_count > 1 || ea_count > 1)
// 	{
// 		lst = head;
// 		lst->error = DUBLICATE_TEX;
// 		return (1);
// 	}
// 	else if (no_count == 0 || so_count == 0 || we_count == 0 || ea_count == 0)
// 	{
// 		lst = head;
// 		lst->error = NOT_ENOUGHT_TEX;
// 		return (1);	
// 	}
// 	else
// 		return (0);
// }

// int	dublicate_colour(t_lst *lst)
// {
// 	int	f_count;
// 	int	c_count;
// 	t_lst	*head;

// 	f_count = 0;
// 	c_count = 0;
// 	head = lst;
// 	while (lst)
// 	{
// 		if (ft_strnstr(lst->str, "F ", 2) != 0)
// 			f_count++;
// 		if (ft_strnstr(lst->str, "C ", 2) != 0)
// 			c_count++;
// 		lst = lst->next;
// 	}
// 	if (f_count > 1 || c_count > 1)
// 	{
// 		lst = head;
// 		lst->error = DUBLICATE_COLOUR;
// 		return (1);
// 	}
// 	else if (f_count == 0 || c_count == 0)
// 	{
// 		lst = head;
// 		lst->error = NOT_ENOUGHT_COLOUR;
// 		return (1);
// 	}
// 	return (0);
// }

// int	check_key(char *line)
// {
// 	if (ft_strncmp("NO ", line, 3) == 0) // нашел NO
// 		return (0);
// 	else if (ft_strncmp("SO ", line, 3) == 0)
// 		return (0);
// 	else if (ft_strncmp("WE ", line, 3) == 0)
// 		return (0);
// 	else if (ft_strncmp("EA ", line, 3) == 0)
// 		return (0);
// 	else if (ft_strncmp("F ", line, 2) == 0)
// 		return (0);
// 	else if (ft_strncmp("C ", line, 2) == 0)
// 		return (0);
// 	else if (line[0] == '\0')
// 		return (0);
// 	return (1);
// }

// int	right_key(t_lst *lst)
// {
// 	int		i;
// 	t_lst	*head;

// 	i = 0;
// 	head = lst;
// 	while (i < 7)
// 	{
// 		if (check_key(lst->str) == 1)
// 		{
// 			lst = head;
// 			lst->error = BAD_KEY;
// 			return (1);
// 		}
// 		lst = lst->next;
// 		i++;
// 	}
// 	return (0);
// }

void	check_map(t_lst *lst)
{
	if (lst->error == BAD_MAP)
		ft_putstr_fd("Error: Invalid map\n", 1);
	else if (lst->error == DUBLICATE_TEX)
		ft_putstr_fd("Error: Dublicte texture\n", 1);
	else if (lst->error == NOT_ENOUGHT_TEX)
		ft_putstr_fd("Error: Not enought textures\n", 1);
	else if (lst->error == DUBLICATE_COLOUR)
		ft_putstr_fd("Error: Dublicate colour\n", 1);
	else if (lst->error == NOT_ENOUGHT_COLOUR)
		ft_putstr_fd("Error: Not enought colour\n", 1);
	else if (lst->error == BAD_TEXTURE)
		ft_putstr_fd("Error: Texture error\n", 1);
	else if (lst->error == BAD_KEY)
		ft_putstr_fd("Error: Key error\n", 1);
	else if (lst->error == BAD_COLOUR)
		ft_putstr_fd("Error: Colour error\n", 1);
	ft_putstr_fd("Quit cub3D\n", 1);
	exit (0);
}

void	main_check(t_lst *lst, t_all *all)
{
	if (right_simbols_in_map(lst, all) == 1 || how_many_players(lst, all) == 1 || if_surrounded_by_wals(lst, all) == 1 \
	|| check_corners(lst, all) == 1 || lst->error != 0 || right_key(lst) == 1 || dublicate_texture(lst) == 1 \
	|| dublicate_colour(lst) == 1)
	{
		check_map(lst);
	}
}
