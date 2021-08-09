/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjammie <mjammie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 14:01:02 by mjammie           #+#    #+#             */
/*   Updated: 2021/08/09 20:24:47 by mjammie          ###   ########.fr       */
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
# define TEX_WIDTH 64
# define TEX_HEIGHT 64

# define BAD_MAP 1
# define DUBLICATE_TEX 2
# define DUBLICATE_COLOUR 3
# define BAD_TEXTURE 4
# define BAD_KEY 5
# define BAD_COLOUR 6
# define NOT_ENOUGHT_TEX 7
# define NOT_ENOUGHT_COLOUR 8
# define PI	3.1416

typedef struct s_paths
{
	char	*north_path;
	char	*south_path;
	char	*west_path;
	char	*east_path;
	int		floor_colour;
	int		celling_colour;
	int		no_count;
	int		so_count;
	int		we_count;
	int		ea_count;
	int		f_count;
	int		c_count;
	int		red;
	int		green;
	int		blue;
}				t_paths;

typedef struct s_lst
{
	char			*str;
	int				error;
	struct s_lst	*next;
}				t_lst;

typedef struct s_mini
{
	double		dir_x;
	double		dir_y;
	double		pa;
	double		start;
	double		end;
	double		x;
	double		y;
	int			on;
}				t_mini;

typedef struct s_player
{
	int			x;
	int			y;
	double		pa;
	double		posX;
	double		posY;
	double		dirX;
	double		dirY;
	double		planeX;
	double		planeY;
}				t_player;

typedef struct s_sprite
{
	double			x[10];
	double			y[10];
}				t_sprite;

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

typedef struct s_f_sprs
{
	double	sprite_x;
	double	sprite_y;
	double	inv_det;
	double	transform_x;
	double	transform_y;
	int		spr_scrn_x;
	int		v_move_screen;
	int		spr_h;
	int		draw_start_y;
	int		draw_end_y;
	int		spr_w;
	int		draw_start_x;
	int		draw_end_x;
	int		tex_x;
	int		tex_y;
	int		color;
}				t_f_sprs;

typedef struct s_for_raycast
{
	double	camera_x;
	double	ray_dir_x;
	double	ray_dir_y;
	double	side_dist_x;
	double	side_dist_y;
	double	dlt_dist_x;
	double	delta_dist_y;
	double	perp_wall_dist;
	int		map_x;
	int		map_y;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
	int		line_height;
	int		draw_start;
	int		draw_end;
	double	wall_x;
	int		color;
	double	step;
	double	tex_pos;
	int		tex_x;
	int		tex_y;
}				t_for_raycasting;

typedef struct s_all
{
	t_player			player;
	t_data				img;
	t_mlx				mlx;
	t_paths				*path;
	char				**map_c;
	int					**map;
	int					**colors_n;
	int					**colors_s;
	int					**colors_west;
	int					**colors_east;
	int					**colors_sprite;
	int					**colors_door;
	int					count;
	int					count_sprites;

	t_data				img_map;
	t_mini				mini;
	t_sprite			sprites;
	t_f_sprs			f_spr;
	t_for_raycasting	rc;
	int					map_max_width;
	int					map_max_height;
	double				buffer[SCREEN_WIDTH];
	int					*sprite_order;
	double				*sprite_distance;
}				t_all;

//utils
t_lst			*ft_lstlast(t_lst *lst);
int				ft_lstsize(t_lst *lst);
void			ft_lstadd_back(t_lst **lst, t_lst *new);
t_lst			*ft_lstnew(void *content);
void			ft_putstr_fd(char *s, int fd);
void			ft_putchar_fd(char c, int fd);
char			ft_check(char c, const char *set);
int				ft_splitlen(char **str);
int				ft_atoi(char *str);
char			*ft_strtrim(char const *s, const char *set);
char			**ft_split(char const *s, char c);
int				ft_isdigit(int c);
int				ft_strncmp(const char *str1, const char *str2, size_t num);
void			max_height_map(t_all *all);
void			*ft_free_everything(char **str);

//raycast
void			raycaster(t_all *all);
void			print(t_all *all);
void			init_struct_raycasting(t_for_raycasting *st);
void			new_init(t_all *all, int x);
void			my_mlx_pixel_put(t_data *data, int x, int y, int color);
void			print_map(t_all *all);
void			moves(t_all *all, int keycode);
void			turn_left(t_all *all, double rotSpeed);
void			turn_right(t_all *all, double rotSpeed);
void			print_sprite(t_all *all);
void			sort_sprites(double *sprite_distance, t_all *all);
unsigned int	texpixcolor(t_data *img, int x, int y);
void			optimization_color_img(t_all *all, int ***arr, char *path);
void			print_mini_map(t_all *all);
void			print_img(t_data *img, int x, int y, int color);
int				key_hook_mini(int keycode, t_all *all);
void			print_player(t_all *all, int color);
void			print_pixels(t_all *all, int x);
int				close_win(void);
int				key_hook(int keycode, t_all *all);
void			init_f_spr(t_f_sprs *st);
void			new_init_spr(t_all *all, int i);

// parser //check_map
void			main_check(t_lst *lst, t_all *all);
void			parse_info(t_lst *lst, t_all *all);
int				check_key(char *line);
int				right_key(t_lst *lst);
int				dublicate_colour(t_lst *lst, t_all *all);
int				dublicate_texture(t_lst *lst, t_all *all);
char			*ft_strnstr(const char *big, const char *little, size_t len);
int				check_last_corner(char *line, char *last);
int				check_first_corner(char *line, char *next);
int				check_corners(t_lst *lst, t_all *all);
int				if_surrounded_by_wals(t_lst *lst, t_all *all);
int				check_first_last_line(char *line);
int				check_line_for_wals(char *line, char *next, char *last);
void			get_path(char *line, t_lst *lst, t_all *all);
int				get_colour(char *line, t_lst *lst, t_all *all);
void			set_coordinates(t_all *all, int i, int j);
void			parse_map(t_all *all, t_lst *lst);
void			check_lst(t_lst *lst, t_all *all);
void			check_open_map(char **argv, int fd);
int				if_surrounded_by_wals_horisontal(t_lst *lst, t_all *all);

#endif