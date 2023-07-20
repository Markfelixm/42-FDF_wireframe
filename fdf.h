/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmulle <marmulle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 10:51:39 by marmulle          #+#    #+#             */
/*   Updated: 2023/07/20 22:50:33 by marmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "Libft/ft_printf.h"
# include "Libft/get_next_line_bonus.h"
# include "Libft/libft.h"

# include <stdbool.h>
# include <string.h>
# include <stdio.h>
# include <sys/errno.h>
# include <math.h>
# include <fcntl.h>
# include <mlx.h>

# define WIDTH 1600
# define HEIGHT 900

# define WHITE 0x00FFFFFF

typedef unsigned int	t_uint;

typedef enum e_key
{
	KEY_1 = 18,
	KEY_2 = 19,
	KEY_3 = 20,
	KEY_4 = 21,
	KEY_5 = 23,
	KEY_6 = 22,
	KEY_7 = 26,
	KEY_8 = 28,
	KEY_9 = 25,
	KEY_0 = 29,
	KEY_Q = 12,
	KEY_A = 0,
	KEY_Z = 6,
	KEY_W = 13,
	KEY_S = 1,
	KEY_X = 7,
	KEY_E = 14,
	KEY_D = 2,
	KEY_C = 8,
	KEY_R = 15,
	KEY_F = 3,
	KEY_V = 9,
	KEY_T = 17,
	KEY_G = 5,
	KEY_B = 11,
	KEY_Y = 16,
	KEY_H = 4,
	KEY_N = 45,
	KEY_U = 32,
	KEY_J = 38,
	KEY_M= 46,
	KEY_I = 34,
	KEY_K = 40,
	KEY_O = 31,
	KEY_L = 37,
	KEY_P = 35,
	KEY_SPACE = 49,
	KEY_ESC = 53,
	KEY_UP = 126,
	KEY_DOWN = 125,
	KEY_LEFT = 123,
	KEY_RIGHT = 124,
}	t_key;

typedef enum e_pan
{
	UP,
	DOWN,
	LEFT,
	RIGHT
}	t_pan;

typedef enum e_proj
{
	ISO,
	CONIC,
	ORTHO,
	PROJ_COUNT
}	t_proj;

enum e_events
{
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

typedef struct s_bres
{
	int	dx;
	int	sx;
	int	dy;
	int	sy;
	int	err;
	int	e2;
	int	x;
	int	y;
}		t_bres;

typedef struct s_vec2c
{
	double	x;
	double	y;
	t_uint	color;
}			t_vec2c;

typedef struct s_vec3
{
	double	x;
	double	y;
	double	z;
}			t_vec3;

typedef struct s_point
{
	int		x;
	int		y;
	int		z;
	t_uint	color;
	t_vec3	vec3;
}			t_point;

typedef struct s_map
{
	t_point	*points;

	int		width;
	int		length;

	t_proj	projection;
	double	normalizer;
	double	scalar;
	double	translate_x;
	double	translate_y;
	double	translate_step;
	double	rotate;
	double	rotate_step;
	double	squash_x;
	double	squash_y;
	double	squash_z;
	double	squash_step;
}			t_map;

typedef struct s_context
{
	t_map	map;

	void	*mlx;
	void	*window;

	void	*img_ptr;
	char	*addr;
	int		bits_per_pixel;
	int		line_size;
	int		endian;
}			t_context;

// parse.c
bool	set_dimensions(t_map *map, char *line);
void	parse_point(t_map *map, char *word);
bool	parse_points(t_map *map, char *line);
bool	parse_file(t_map *map, const char *filename,
			bool (*func)(t_map *, char *));
bool	get_map(t_map *map, const char *filename);

// color.c
t_uint	get_color(char *word);
t_uint	lerp_color(t_uint from, t_uint to, double at);
t_uint	create_trgb(int t, int r, int g, int b);

// drawloop.c
void	blank_image(t_context *ctx);
int		render(t_context *ctx);

// draw.c
void	pixel_to_image(t_context *ctx, int x, int y, int color);
t_bres	init_bres(t_vec2c *from, t_vec2c *to);
void	draw_line(t_context *ctx, t_vec2c *from, t_vec2c *to);
void	draw_segment(t_context *ctx, int x, int y);
void	draw_map(t_context *ctx);

// normalize.c
void	set_normalizer(t_map *map);
void	normalize_map_point_vectors(t_map *map);
void	translate_center_to_origin(t_map *map);
double	distance_from_origin(t_point *p);

// projection.c
t_vec2c	project_conical(t_context *ctx, t_vec3 *vec);
t_vec2c	flatten_vec3(t_context *ctx, t_vec3 *vec);
t_vec3	squash_vec3(t_context *ctx, t_vec3 *vec);
t_vec2c	screen_space(t_context *ctx, t_vec3 *vec, t_uint color);

// math.c
t_uint	unsigned_pow(t_uint base, t_uint exp);
double	lerp(double from, double to, double at);
double	vec2c_distance(t_vec2c *from, t_vec2c *to);
t_vec2c	scale_vec2(t_vec2c *vec, double scalar);

// memory.c
void	init_context(t_context *ctx);
void	free_splits(char **splits);
void	free_map(t_map *map);
void	close_window(t_context *ctx, int exit_code);
void	set_map_defaults(t_map *map);

// hook.c
int		key_hook(int keycode, t_context *ctx);
int		click_hook(int keycode, t_context *ctx);
int		destroy_hook(int keycode, t_context *ctx);

// hook_utility.c
void	translate_hooks(int keycode, t_context *ctx);
void	scale_hooks(int keycode, t_context *ctx);
void	squash_hooks(int keycode, t_context *ctx);
void	rotate_hooks(int keycode, t_context *ctx);
void	projection_hook(int keycode, t_context *ctx);

// utility.c
int		at(const t_map *map, int column, int row);
int		hex_to_int(char hex);
int		get_word_count(char *line);

#endif
