/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmulle <marmulle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 10:51:39 by marmulle          #+#    #+#             */
/*   Updated: 2023/06/08 22:56:28 by marmulle         ###   ########.fr       */
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

# define SQRT6 2.44948974278 // TODO: need?

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
	KEY_J = 38
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

	double	scaler;
	bool	apply_rotate;
	double	rotate_step;
	double	rotate_x;
	double	rotate_y;
	double	rotate_z;
	int		translate_x;
	int		translate_y;
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

// drawloop.c
int		render(t_context *ctx);

// draw.c
void	pixel_to_image(t_context *ctx, int x, int y, int color);
void	draw_line(t_vec4 *from, t_vec4 *to, t_context *ctx);
void	draw_map(t_context *ctx);
void	draw_edges(t_context *ctx);
void	blank_image(t_context *ctx);

// color.c
int		create_trgb(int t, int r, int g, int b);
int		hsv_to_trgb(double h, double s, double v);

// hook.c
int		key_hook(int keycode, t_context *ctx);
int		click_hook(int keycode, t_context *ctx);
int		destroy_hook(int keycode, t_context *ctx);

// utility.c
int		hex_to_int(char hex);
void	close_window(t_context *ctx);
int		at(t_map *map, int column, int row);

// math.c
double	lerp(double from, double to, double at);
double	points_distance_2d(t_point from, t_point to);
double	distance_between_points(t_point from, t_point to);
double	vec4_product(t_vec4 *a, t_vec4 *b);
double	distance_from_origin(t_point *p);

// normalize.c
int		get_normalizer(t_map *map);
void	normalize_map_point_vectors(t_map *map);
t_vec4	scale_vector(t_vec4 *vec, double scaler);

// transform.c
t_vec4	apply_projection(t_vec4 *vec, t_context *ctx);
t_vec4	*get_rotator(t_rot_axis axis, double q);
bool	transform_vector(t_vec4 *vec, t_vec4 *transformer);
bool	transform_map(t_map *map, t_vec4 *transformer);

// parse.c
int		get_color(char *word);
int		get_word_count(char *line);
bool	set_dimensions(t_map *map, char *line);
void	parse_point(t_map *map, char *word);
bool	parse_points(t_map *map, char *line);
bool	parse_file(t_map *map, const char *filename, bool (*func)(t_map *, char *));
bool	get_map(t_map *map, const char *filename);

// memory.c
void	free_splits(char **splits);
void	free_map(t_map *map);

#endif
