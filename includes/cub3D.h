/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjammie <mjammie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 14:01:02 by mjammie           #+#    #+#             */
/*   Updated: 2021/08/02 15:12:41 by mjammie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "get_next_line.h"
# include "../minilibx_mms_20200219/mlx.h"

typedef struct s_lst
{
	char			*str;
	struct s_lst	*next;
}				t_lst;

typedef struct s_map
{
	char	**map;
}				t_map;

//utils
t_lst	*ft_lstlast(t_lst *lst);
int		ft_lstsize(t_lst *lst);
void	ft_lstadd_back(t_lst **lst, t_lst *new);
t_lst	*ft_lstnew(void *content);

//work with map
void	work_with_map(t_map *map, t_lst *lst);

#endif