/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjammie <mjammie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 14:01:02 by mjammie           #+#    #+#             */
/*   Updated: 2021/08/05 18:33:29 by mjammie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "get_next_line.h"
# include "../minilibx_mms_20200219/mlx.h"
# include <math.h>
# include <unistd.h>
# define SCREEN_WIDTH 1920
# define SCREEN_HEIGHT 1080

# define BAD_MAP 1
# define DUBLICATE_TEX 2
# define DUBLICATE_COLOUR 3
# define BAD_TEXTURE 4
# define BAD_KEY 5
# define BAD_COLOUR 6
# define NOT_ENOUGHT_TEX 7
# define NOT_ENOUGHT_COLOUR 8

typedef struct s_paths
{
	char	*north_path;
	char	*south_path;
	char	*west_path;
	char	*east_path;
	int		floor_colour;
	int		celling_colour;
}	t_paths;

typedef struct s_lst
{
	char			*str;
	int				error;
	struct s_lst	*next;
}				t_lst;

typedef struct s_player
{
	double		posX;
	double		posY;
	double		dirX;
	double		dirY;
	double		planeX;
	double		planeY;
}				t_player;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
}				t_mlx;

typedef struct s_data
{
	void	*img;
	void	*img_player;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_all
{
	t_player	player;
	t_data		img;
	t_mlx		mlx;
	char		**map_c;
	int			**map;
}				t_all;

//utils
t_lst	*ft_lstlast(t_lst *lst);
int		ft_lstsize(t_lst *lst);
void	ft_lstadd_back(t_lst **lst, t_lst *new);
t_lst	*ft_lstnew(void *content);
void	ft_putstr_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);

//raycast
void	raycaster(t_all *all);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	print_map(t_all *all);

// parser //check_map
void	main_check(t_lst *lst, t_all *all);
void	parse_info(t_lst *lst, t_paths *path, t_all *all);
int		check_key(char *line);
int		right_key(t_lst *lst);
int		dublicate_colour(t_lst *lst);
int		dublicate_texture(t_lst *lst);
char	*ft_strnstr(const char *big, const char *little, size_t len);
int		check_last_corner(char *line, char *last);
int		check_first_corner(char *line, char *next);
int		check_corners(t_lst *lst, t_all *all);
int		if_surrounded_by_wals(t_lst *lst, t_all *all);
int		check_first_last_line(char *line);
int		check_line_for_wals(char *line, char *next, char *last);
char 	ft_check(char c, const char *set);
int		ft_splitlen(char **str);

// parse_info
int		ft_atoi(char *str);
void	get_path(char *line, t_paths *path, t_lst *lst, t_all *all);
int		get_colour(char *line, t_lst *lst, t_all *all);
char	*ft_strtrim(char const *s, const char *set);
char	**ft_split(char const *s, char c);
int		ft_isdigit(int c);
int		ft_strncmp(const char *str1, const char *str2, size_t num);

#endif