/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimoes <asimoes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 18:44:48 by asimoes           #+#    #+#             */
/*   Updated: 2021/05/27 04:17:17 by asimoes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <math.h>
# include "libft/libft.h"
# include "get_next_line/get_next_line.h"

# ifdef LINUX
#  include "minilibx-linux/mlx.h"
# endif

# ifdef MAC
#  include "minilibx-mac/mlx.h"
# endif

# define PARAM_R		0
# define PARAM_NO		1
# define PARAM_SO		2
# define PARAM_WE		3
# define PARAM_EA		4
# define PARAM_S		5
# define PARAM_F		6
# define PARAM_C		7
# define KEY_W			0x0077
# define KEY_A			0x0071
# define KEY_S			0x0073
# define KEY_D			0x0064
# define KEY_ESCAPE		0xFF1B
# define KEY_LEFT		0xFF51
# define KEY_UP			0xFF52
# define KEY_RIGHT		0xFF53
# define KEY_DOWN		0xFF54
# define TILE_CHECKED	-2
# define FOV			0.66
# define MOVE_SPEED		0.003
# define ROT_SPEED		0.003

typedef struct s_sprite {
	double	x;
	double	y;
}				t_sprite;

typedef struct s_ray {
	double	camera_x;
	double	dirx;
	double	diry;
	int		mapx;
	int		mapy;
	double	side_distx;
	double	side_disty;
	double	delta_distx;
	double	delta_disty;
	double	perp_wall_dist;
	int		stepx;
	int		stepy;
	int		hit;
	int		side;
}				t_ray;

typedef struct s_texture {
	void	*img;
	int		*data;
	int		h;
	int		w;
	int		bpp;
	int		sl;
	int		endian;
}				t_texture;

typedef struct s_draw {
	int		y_start;
	int		y_end;
	int		color;
}				t_draw;

typedef struct s_wall {
	int			line_height;
	t_draw		draw;
	t_texture	*tex;
	double		wall_x;
	int			tex_x;
	double		step;
	double		tex_pos;
	int			tex_y;
	int			color;
}				t_wall;

typedef struct s_sprite_data {
	int			*order;
	int			*distance;
	double		sprite_x;
	double		sprite_y;
	double		inv_det;
	double		transform_x;
	double		transform_y;
	int			sprite_screen_x;
	int			sprite_height;
	int			draw_start_y;
	int			draw_end_y;
	int			sprite_width;
	int			draw_start_x;
	int			draw_end_x;
	int			tex_x;
	int			tex_y;
	int			d;
	int			color;
}				t_sprite_data;

typedef struct s_pos {
	int			x;
	int			y;
	void		*next;
}				t_pos;

typedef struct s_conf {
	int			fd;
	void		*mlx;
	void		*window;
	void		*img;
	int			*img_data;
	void		*img2;
	int			*img_data2;
	int			img_bpp;
	int			resx;
	int			resy;
	char		*no_path;
	char		*so_path;
	char		*we_path;
	char		*ea_path;
	char		*s_path;
	t_texture	no;
	t_texture	so;
	t_texture	we;
	t_texture	ea;
	t_texture	s;
	int			floor;
	int			ceil;
	int			**map;
	char		**text_map;
	int			map_alloc_lines;
	int			map_lines;
	int			map_height;
	int			map_width;
	short		start;
	double		posx;
	double		posy;
	double		dirx;
	double		diry;
	double		planex;
	double		planey;
	short		key_w;
	short		key_s;
	short		key_a;
	short		key_d;
	short		key_left;
	short		key_right;
	double		move_speed;
	double		rot_speed;
	short		save;
	int			sprites_count;
	t_sprite	*sprites;
	double		*z_buffer;
	int			**map_copy;
	t_pos		*maplist_start;
}				t_conf;

typedef struct s_res_data {
	char		*value;
	char		*sub;
	char		*trim;
	char		**split;
}				t_res_data;

typedef struct s_ceil {
	char		*value;
	char		*sub;
	char		*trim;
	char		**rgb;
}				t_ceil;

char			*trim_helper(char *str, char *charset, t_conf *conf);
void			free_gnl(t_conf *conf);
void			free_paths(t_conf *conf);
void			free_textures(t_conf *conf);
void			check_config(char *filename, t_conf *conf);
void			check_args(int argc, char *argv[], t_conf *conf);
void			load_textures(t_conf *conf);
void			get_textures_addr(t_conf *conf);
void			free_map(int **map, int lines);
void			free_maplist(t_pos *list);
void			add_last(t_pos *list, t_pos *item);
t_pos			*create_mapitem(int x, int y, t_conf *conf);
void			check_p(t_pos *cur, int **map, t_pos *start, t_conf *conf);
void			check_map(t_conf *conf);
void			sort_sprites(int *order, int *distance, int count);
void			set_cur_sprite(t_sprite_data *sd, t_conf *conf, int i);
void			draw_sprite(t_sprite_data *sd, t_conf *conf, int j);
void			set_wall_info(t_conf *conf, t_ray *ray, t_wall *wall);
t_texture		*get_texture(t_ray *ray, t_conf *conf);
int				count_sprites(t_conf *conf);
void			save_sprites(t_conf *conf);
void			load_textures(t_conf *conf);
void			get_textures_addr(t_conf *conf);
void			init_game(t_conf *conf);
void			map_check(char *trimmed, t_conf *conf);
void			error_double_param(int param, char *line, t_conf *conf);
void			check_param(int param, char *value, t_conf *conf);
int				is_param(char **params, char *line, int *check, t_conf *conf);
int				check_params(int fd, char **params, t_conf *conf);
void			set_params_headers(char **params);
void			*cube_realloc(void *ptr, size_t size, size_t ptrsize);
void			free_config(t_conf *conf);
void			ft_freetab(char **tab, short origin);
int				ft_atoi_pos(const char *str);
int				is_numeric(char	*str);
int				count_commas(char *value);
void			trim_values(char **data, t_conf *conf);
void			parse_r(char *value, t_conf *conf);
void			parse_ea(char *value, t_conf *conf);
void			parse_c(char *value, t_conf *conf);
void			parse_no(char *value, t_conf *conf);
void			parse_so(char *value, t_conf *conf);
void			parse_we(char *value, t_conf *conf);
void			parse_s(char *value, t_conf *conf);
void			parse_f(char *value, t_conf *conf);
void			parse_map(int fd, t_conf *conf);
void			exit_error(char *message, t_conf *conf);
int				exit_hook(t_conf *conf);
int				key_pressed_hook(int key, t_conf *conf);
int				key_released_hook(int key, t_conf *conf);
int				loop_hook(t_conf *conf);
void			create_image(t_conf *conf);
void			render(t_conf *conf);
int				move_forward(t_conf *conf);
int				move_backwards(t_conf *conf);
int				move_left(t_conf *conf);
int				move_right(t_conf *conf);
int				rotate_left(t_conf *conf);
int				rotate_right(t_conf *conf);
void			exit_screenshot(t_conf *conf);
void			check_line(t_conf *conf, char *line);
void			add_map_line(t_conf *conf, char *line);
void			transform_map(t_conf *conf);
void			draw_walls(t_conf *conf);
void			draw_sprites(t_conf *conf);
int				visibility_hook(t_conf *conf);
void			draw_background(t_conf *conf);

#endif
