/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfm <mfm@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 10:51:39 by marmulle          #+#    #+#             */
/*   Updated: 2023/07/02 23:13:43 by mfm              ###   ########.fr       */
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

typedef enum e_key
{
	KEY_W = 13,
	KEY_A = 0,
	KEY_S = 1,
	KEY_D = 2,
	KEY_Q = 12,
	KEY_E = 14,
	KEY_1 = 18,
	KEY_2 = 19,
	KEY_3 = 20,
	KEY_4 = 21,
	KEY_5 = 22,
	KEY_R = 15,
	KEY_F = 3,
	KEY_T = 17,
	KEY_G = 5,
	KEY_Y = 16,
	KEY_H = 4,
	KEY_U = 32,
	KEY_J = 38,
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

typedef enum e_rot_axis
{
	RZ,
	RX,
	RY
}	t_rot_axis;

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

typedef struct s_vec2
{
	double	x;
	double	y;
}			t_vec2;

typedef struct s_vec4
{
	double	x;
	double	y;
	double	z;
	double	w;
}			t_vec4;

typedef struct s_point
{
	int		x;
	int		y;
	int		z;
	int		color;
	t_vec4	vec4;
}			t_point;

typedef struct s_map
{
	t_point	*points;

	int		width;
	int		length;

	double	normalizer;
	double	scalar;
	bool	apply_rotate;
	double	rotate_step;
	double	rotate_x;
	double	rotate_y;
	double	rotate_z;
	double	translate_x;
	double	translate_y;
	double	translate_step;
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
int		get_color(char *word);
int		create_trgb(int t, int r, int g, int b);

// drawloop.c
void	blank_image(t_context *ctx);
int		render(t_context *ctx);

// draw.c
void	pixel_to_image(t_context *ctx, int x, int y, int color);
t_bres	init_bres(t_vec2 *from, t_vec2 *to);
void	draw_line(t_context *ctx, t_vec2 *from, t_vec2 *to);
void	draw_segment(t_context *ctx, int x, int y);
void	draw_map(t_context *ctx);

// normalize.c
void	set_normalizer(t_map *map);
void	normalize_map_point_vectors(t_map *map);
void	translate_origin_to_center(t_map *map);

// transform.c


// math.c
double	lerp(double from, double to, double at);
double	points_distance_2d(t_point from, t_point to);
double	distance_between_points(t_point from, t_point to);
double	vec4_product(t_vec4 *a, t_vec4 *b);
double	distance_from_origin(t_point *p);
t_vec2	scale_vec2(t_vec2 *vec, double scalar);
// t_vec2	flatten_vec4(const t_vec4 *vec); // TODO: remove
t_vec2	flatten_vec4(const t_vec4 *vec, double rotate_x, double rotate_y);
t_vec2	screen_space(t_context *ctx, const t_vec4 *vec);

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
void	rotate_hooks(int keycode, t_context *ctx);

// utility.c
int		at(const t_map *map, int column, int row);
int		hex_to_int(char hex);
int		get_word_count(char *line);

#endif
