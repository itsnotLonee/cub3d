/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbalboa- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 13:41:09 by dbalboa-          #+#    #+#             */
/*   Updated: 2021/04/01 13:41:13 by dbalboa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft/libft.h"
# include <limits.h>
# include <math.h>
# include "mlx/mlx.h"
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>

# define ANSI_COLOR_YELLOW  "\x1b[33m"
# define ANSI_COLOR_BLUE    "\x1b[34m"
# define ANSI_COLOR_CYAN    "\x1b[36m"
# define ANSI_COLOR_GREEN   "\x1b[32m"
# define ANSI_COLOR_MAGENTA "\x1b[35m"
# define ANSI_COLOR_RESET   "\x1b[0m"

# define HEADER ANSI_COLOR_CYAN "\n############# 42-CUB3D by @dbalboa- ##############\n\n" ANSI_COLOR_RESET
# define FOOTER ANSI_COLOR_CYAN "\n\n##################################################\n" ANSI_COLOR_RESET
# define TITLE ANSI_COLOR_BLUE "There were some errors:\n" ANSI_COLOR_RESET

# define E_ARGS HEADER TITLE ANSI_COLOR_YELLOW "Wrong arguments, try -> ./cub3d [map] [--save]" FOOTER ANSI_COLOR_RESET
# define E_FLAG HEADER TITLE ANSI_COLOR_YELLOW "Wrong flag, try -> ./cub3d [map] [--save]" FOOTER ANSI_COLOR_RESET
# define E_FILE HEADER TITLE ANSI_COLOR_YELLOW "Bad Map file format" FOOTER ANSI_COLOR_RESET
# define E_FILE_404 HEADER TITLE ANSI_COLOR_YELLOW "File not found" FOOTER ANSI_COLOR_RESET
# define E_FILE_INFO HEADER TITLE ANSI_COLOR_YELLOW "Wrong information in description file" FOOTER ANSI_COLOR_RESET
# define E_FILE_MAP_404 HEADER TITLE ANSI_COLOR_YELLOW "Map description not found" FOOTER ANSI_COLOR_RESET
# define E_RES HEADER TITLE ANSI_COLOR_YELLOW "Invalid resolution param" FOOTER ANSI_COLOR_RESET
# define E_TEX HEADER TITLE ANSI_COLOR_YELLOW "Invalid texture params" FOOTER ANSI_COLOR_RESET
# define E_COLOR HEADER TITLE ANSI_COLOR_YELLOW "Invalid color params" FOOTER ANSI_COLOR_RESET
# define E_MAP_DESC HEADER TITLE ANSI_COLOR_YELLOW "Invalid map description" FOOTER ANSI_COLOR_RESET
# define E_PLAYER_POS HEADER TITLE ANSI_COLOR_YELLOW "Wrong player position" FOOTER ANSI_COLOR_RESET
# define E_ERR HEADER TITLE ANSI_COLOR_YELLOW "Something failed successfully" FOOTER ANSI_COLOR_RESET

# define CREATED_BITMAP HEADER ANSI_COLOR_MAGENTA "Bitmap file created with name -> " ANSI_COLOR_GREEN " 'screenshot.bpm'" FOOTER

# define ESC_KEY	53
# define W_KEY		13
# define A_KEY		0
# define S_KEY		1
# define D_KEY		2
# define LEFT_KEY	123
# define RIGHT_KEY	124

typedef struct s_mlx
{
	void			*ptr;
}					t_mlx;

typedef struct s_win
{
	int				width;
	int				height;
	void			*ptr;
}					t_win;

typedef struct s_img
{
	void			*ptr;
	char			*buffer;
	int				*buff;
	int				bits_per_pixel;
	int				size_line;
	int				endian;
}					t_img;

typedef struct s_color
{
	unsigned r;
	unsigned g;
	unsigned b;
}					t_color;

typedef struct s_tex
{
	char			*path;
	int				x;
	int				y;
	double			step;
	double			pos;
	t_img			*img;
	int				width;
	int				height;
}					t_tex;

typedef struct s_dvec
{
	double			x;
	double			y;
}					t_dvec;

typedef struct s_ivec
{
	int				x;
	int				y;
}					t_ivec;

typedef struct s_cam
{
	double			x;
}					t_cam;

typedef struct s_side
{
	t_dvec			dist;
}					t_side;

typedef struct s_wall
{
	double			dist;
	int				hit;
	int				side;
	double			x;
}					t_wall;

typedef struct s_ray
{
	int				x;
	t_dvec			dir;
	t_cam			cam;
	t_side			side;
	t_dvec			delta;
	t_wall			wall;
	t_ivec			step;
}					t_ray;

typedef struct s_sprite
{
	t_ivec			start;
	t_ivec			end;
	int				width;
	int				height;
	double			x;
	double			y;
	double			inver;
	t_dvec			transform;
	int				win;
}					t_sprite;

typedef struct s_draw
{
	int				height;
	int				start;
	int				end;
	int				f_rgb;
	int				c_rgb;
	double			*z_buffer;
	t_sprite		sprite;
}					t_draw;

typedef struct s_bmp
{
	int				width;
	int				height;
	int				padding;
	unsigned char	*fileheader;
	unsigned char	*infoheader;
}					t_bmp;

typedef struct s_pos
{
	double			x;
	double			y;
	double			mspeed;
	double			rspeed;
}					t_pos;

typedef struct s_all
{
	t_mlx			mlx;
	t_win			win;
	t_img			img;
	t_ivec			maze;
	t_pos			pos;
	t_dvec			dir;
	t_dvec			plane;
	t_tex			tex[5];
	t_draw			draw;
	t_ray			ray;
	t_dvec			*sprite;
	int				keyboard[125];
	int				sprite_count;
	int				*sprite_order;
	double			*sprite_dist;
	char			**map;
	int				is_map;
	int				control;
	int				map_rows;
	int				map_columns;
	int				f_c;
	int				rows;
	int				control_player;
	int				color;
}					t_all;

int					color_rgb_to_hex(unsigned int r,
						 unsigned int g, unsigned int b);
int					color_floor_parse(char **colors, t_all *all);
int					color_ceilling_parse(char **colors, t_all *all);
int					color_parse(char *params, t_all *all);
int					color_pre_parse(char *params, t_all *all);
void				my_mlx_pixel_put(t_img *img, int x, int y, int color);
void				vertical_draw(t_all *all, int x, int num);
void				sprite_draw(t_all *all);
void				player_move(t_all *all, double x, double y);
void				player_rotate(t_all *all, double speed);
int					key_core(t_all *all);
int					key_release(int kecode, t_all *all);
int					key_press(int keycode, t_all *all);
void				error_put(int errno);
int					program_exit(t_all *all);
int					is_surrounded(t_all *all, int x, int y);
void				is_valid_map(t_all *all);
int					map_create(char *line, t_all *all);
int					map_parse(char *line, t_all *all);
int					map_init(t_all *all, char *path);
int					textures_parse(char **params, t_all *all);
int					params_parse(char **params, t_all *all);
int					line_parse(char *line, t_all *all);
int					line_pre_parse(char *line, t_all *all);
int					config_parse(t_all *all, char *path);
int					is_map(char *line, t_all *all);
int					resolution_parse(char **params, t_all *all);
void				direction_control(t_all *all, double x, double y);
void				plane_control(t_all *all, double x, double y);
void				player_control(t_all *all, int row, int column);
void				sprite_control(t_all *all, int row, int column);
void				sprite_init(t_all *all, int count);
void				sprite_raycast(t_all *all);
void				texture_init(t_all *all);
void				texture_calculate(t_all *all, int i);
int					texture_sort(t_all *all);
int					north_texture_parse(char *param, t_all *all);
int					south_texture_parse(char *param, t_all *all);
int					east_texture_parse(char *param, t_all *all);
int					west_texture_parse(char *param, t_all *all);
int					sprite_texture_parse(char *param, t_all *all);
void				wall_raycast(t_all *all);
void				image_render(t_all *all);
int					display(t_all *all);
void				speed_init(t_all *all);
int					window_init(t_all *all);
double				dist(double x1, double x2);
int					valid_first_line(char *line);
size_t				ft_strlen_only_color(char *str);
char				*ft_strtrim_color(char *str);
int					bitmap_save(t_all *all);

#endif
