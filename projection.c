/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmulle <marmulle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 20:19:02 by marmulle          #+#    #+#             */
/*   Updated: 2023/07/20 16:26:49 by marmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_vec2c	flatten_vec3(t_context *ctx, t_vec3 *vec)
{
	t_vec2c	flat;
	t_vec2c	rotated;

	flat.x = (vec->x - vec->y) * ctx->map.squash_x;
	flat.y = (vec->x + vec->y) * ctx->map.squash_y - vec->z * ctx->map.squash_z;
	rotated.x = flat.x * cos(ctx->map.rotate) - flat.y * sin(ctx->map.rotate);
	rotated.y = flat.y * cos(ctx->map.rotate) + flat.x * sin(ctx->map.rotate);
	return (rotated);
}

t_vec2c	screen_space(t_context *ctx, t_vec3 *vec, t_uint color)
{
	t_vec2c	out;

	out = flatten_vec3(ctx, vec);
	out = scale_vec2(&out, ctx->map.scalar);
	out.x += ctx->map.translate_x;
	out.y += ctx->map.translate_y;
	// theta = 2PI
	// x = xcos - ysin
	// y = xsin + ycos
	out.color = color;
	return (out);
}
