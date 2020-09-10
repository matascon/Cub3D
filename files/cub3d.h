/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matascon <matascon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 17:25:39 by matascon          #+#    #+#             */
/*   Updated: 2020/09/09 16:57:52 by matascon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include "../minilibx_linux/mlx.h"
# include <math.h>

# define ERROR_0 "Error\nThere are not enough arguments to execute the program"
# define ERROR_1 "Error\nThere are too many arguments"
# define ERROR_2 "Error\nWTF BRO!, this is not a file with extension .cub"
# define ERROR_3 "Error\nAre you sure this file exists?"
# define ERROR_4 "Error\nThere is a problem in the file"
# define ERROR_5 "Error\nA parameter is repeated"
# define ERROR_6 "Error\nFile is not full"
# define ERROR_7 "Error\nMissing arguments in resolution"
# define ERROR_8 "Error\nAny value in resolution can not be negative"
# define ERROR_9 "Error\nMissing arguments in some texture direction"
# define ERROR_10 "Error\nInvalid arguments in floor color"
# define ERROR_11 "Error\nInvalid arguments in ceiling color"
# define ERROR_12 "Error\nAny color value can't be negative or greater than 255"
# define ERROR_13 "Error\nIt could not allocate memory, try later"
# define ERROR_14 "Error\n¡MAP ERROR!, what the fu** did you do wrong(?)"
# define ERROR_15 "Error\nSome problem has happened while execution"
# define ERROR_16 "Error\nThird argument gotta be '--save'"

# define NO 0
# define SO 1
# define WE 2
# define EA 3
# define S 4
# define F 5
# define C 6

/*
** MAC KEYS
*/

/*
**# define W_KEY 13
**# define A_KEY 0
**# define S_KEY 1
**# define D_KEY 2
**# define LEFT 123
**# define RIGHT 124
**# define ESC 53
*/

/*
** LINUX KEYS
*/

# define W_KEY 119
# define A_KEY 97
# define S_KEY 115
# define D_KEY 100
# define LEFT 65361
# define RIGHT 65363
# define ESC 65307

typedef struct		s_bmp
{
	int				bmp;
	int				fd;
	int				padding;
	int				size_file;
	unsigned char	file_header[14];
	unsigned char	info_header[40];	
}					t_bmp;

typedef struct		s_colors
{
	int				roof;
	int				floor;
	int				north;
	int				south;
	int				east;
	int				west;
	int				wall;
}					t_colors;

typedef struct		s_movement
{
	int				up;
	int				down;
	int				right;
	int				left;
	int				rot_right;
	int				rot_left;
	double			old_dir_x;
	double			old_plan_x;
	double			speed_rot;
}					t_movement;

typedef struct		s_sprite
{
	int				order;
	double			distance;
	double			coord_x;
	double			coord_y;
	void			*img_ptr;
	int				*get_data;
	int				bits_per_pixel;
	int				size_line;
	int				endian;
	int				width;
	int				height;
	int				color;
}					t_sprite;

typedef struct		s_render_spt
{
	double			x;
	double			y;
	double			inv_det;
	double			transform_x;
	double			transform_y;
	int				screen_x;
	int				start_x;
	int				start_y;
	int				end_x;
	int				end_y;
	int				tex_x;
	int				tex_y;
	int				height;
	int				width;
	double			*dist_wall;
}					t_render_spt;

typedef struct		s_player
{
	double			position_x;
	double			position_y;
	double			dir_x;
	double			dir_y;
	char			orientation_chr;
}					t_player;

typedef struct		s_texture
{
	void			*img_ptr;
	int				bits_per_pixel;
	int				size_line;
	int				endian;
	int				*get_data;
	int				width;
	int				height;
}					t_texture;

typedef struct		s_raycasting
{
	t_texture		north;
	t_texture		south;
	t_texture		east;
	t_texture		west;
	t_colors		color;
	t_sprite		*sprite;
	t_player		player;
	t_render_spt	render;
	int				map_x;
	int				map_y;
	double			plan_x;
	double			plan_y;
	double			camera_in_x;
	double			ray_x;
	double			ray_y;
	double			delta_x;
	double			delta_y;
	double			side_dist_x;
	double			side_dist_y;
	double			perp_wall_dist;
	int				step_x;
	int				step_y;
	int				side;
	int				line_height;
	int				draw_start;
	int				draw_end;
	int				nbr_sprites;
}					t_raycasting;

typedef struct		s_map
{
	char			**map;
	int				w_map;
	int				h_map;
}					t_map;

typedef struct		s_file
{
	char			*file;
	int				r;
	int				no;
	int				so;
	int				we;
	int				ea;
	int				f;
	int				c;
	int				s;
}					t_file;

typedef struct		s_env
{
	void			*mlx_ptr;
	void			*win_ptr;
	void			*new_image;
	int				bits_per_pixel;
	int				size_line;
	int				endian;
	int				width;
	int				height;
	int				*get_data;
	int				width_screen;
	int				height_screen;
	char			*dir_tex_north;
	char			*dir_tex_south;
	char			*dir_tex_west;
	char			*dir_tex_east;
	char			*dir_tex_sprite;
	t_file			file;
	t_map			map;
	t_raycasting	rc;
	t_movement		mv;
	t_bmp			bmp;
}					t_env;

void				ft_exit(t_env *env, char *message);
void				ft_read_file(t_env *env, char *name_file);
void				ft_parse_file(t_env *env);
char				*ft_get_resolution(t_env *env, char *ptr_file);
char				*ft_get_texture_north(t_env *env, char *ptr_file);
char				*ft_get_texture_south(t_env *env, char *ptr_file);
char				*ft_get_texture_west(t_env *env, char *ptr_file);
char				*ft_get_texture_east(t_env *env, char *ptr_file);
char				*ft_get_texture_sprite(t_env *env, char *ptr_file);
char				*ft_aux_textures(t_env *env, char *ptr, int type);
char				*ft_get_color_floor(t_env *env, char *ptr_file);
char				*ft_get_color_roof(t_env *env, char *ptr_file);
char				*ft_aux_colors(t_env *env, char *ptr, int type);
void				ft_parse_map(t_env *env, char *ptr_file);
void				ft_find_dimensions(char *ptr, int *longer_line, int *col);
void				ft_book_and_save_dimensions(t_env *env, int x, int y);
void				ft_fill_map(t_env *env, int x, int y);
void				ft_overwrite_map(t_env *env, char *ptr, int y);
void				ft_check_errors_map(t_env *env);
void				ft_init_missing_values(t_env *env);
void				ft_app(t_env *env);
void				ft_init_textures(t_env *env);
void				ft_render_frame(t_env *env);
void				ft_raycast_wall(t_env *env);
void				ft_raycast_columns(t_env *env, int x, int y);
void				ft_raycast_sprite(t_env *env);
void				ft_render_sprite(t_env *env);
int					ft_key_exit(t_env *env);
int					ft_key_release(int keycode, t_env *env);
int					ft_key_press(int keycode, t_env *env);
int					ft_movement(t_env *env);
void				ft_move_left(t_env *env);
void				ft_move_right(t_env *env);
void				ft_bmp(t_env *env);

#endif
