/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmulle <marmulle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 12:21:16 by marmulle          #+#    #+#             */
/*   Updated: 2023/07/06 14:52:44 by marmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	pixel_to_image(t_context *ctx, int x, int y, int color)
{
	char	*pixel_addr;
	int		line_offset;

	if (x >= 0 && y >= 0 && x < WIDTH && y < HEIGHT)
	{
		line_offset = y * ctx->line_size + x * (ctx->bits_per_pixel / 8);
		pixel_addr = ctx->addr + line_offset;
		*(unsigned int *) pixel_addr = color;
	}
}

t_bres	init_bres(t_vec2 *from, t_vec2 *to)
{
	t_bres	b;

	b.dx = abs((int) to->x - (int) from->x);
	b.sx = -1;
	if (from->x < to->x)
		b.sx = 1;
	b.dy = -1 * abs((int) to->y - (int) from->y);
	b.sy = -1;
	if (from->y < to->y)
		b.sy = 1;
	b.err = b.dx + b.dy;
	b.x = (int) from->x;
	b.y = (int) from->y;
	return (b);
}

void	draw_line(t_context *ctx, t_vec2 *from, t_vec2 *to)
{
	t_bres	b;

	b = init_bres(from, to);
	while (42)
	{
		pixel_to_image(ctx, b.x, b.y, WHITE);
		if (b.x == (int) to->x && b.y == (int) to->y)
			break ;
		b.e2 = 2 * b.err;
		if (b.e2 >= b.dy)
		{
			b.err += b.dy;
			b.x += b.sx;
		}
		if (b.e2 <= b.dx)
		{
			b.err += b.dx;
			b.y += b.sy;
		}
	}
}

void	draw_segment(t_context *ctx, int x, int y)
{
	const t_map		*map = &(ctx->map);
	const t_point	*points = map->points;
	t_vec2			from;
	t_vec2			to;

	from = screen_space(ctx, &(points[at(map, x, y)].vec3));
	if (x < map->width - 1)
	{
		to = screen_space(ctx, &(points[at(map, x + 1, y)].vec3));
		draw_line(ctx, &from, &to);
	}
	if (y < map->length - 1)
	{
		to = screen_space(ctx, &(points[at(map, x, y + 1)].vec3));
		draw_line(ctx, &from, &to);
	}
}

void	draw_map(t_context *ctx)
{
	const t_map	*map = &(ctx->map);
	int			x;
	int			y;

	y = -1;
	while (++y < map->length)
	{
		x = -1;
		while (++x < map->width)
			draw_segment(ctx, x, y);
	}
}
