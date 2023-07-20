/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmulle <marmulle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 20:19:02 by marmulle          #+#    #+#             */
/*   Updated: 2023/07/20 21:15:43 by marmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_vec2c	flatten_vec3(t_context *ctx, t_vec3 *vec)
{
	t_vec2c	flat;
	t_vec2c	rotated;
	t_vec3	hold;

	if (ctx->map.projection == CONIC)
	{
		hold.x = 1 - vec->x * ctx->map.squash_x;
		hold.y = 1 - vec->y * ctx->map.squash_y;
		hold.z = 1 - vec->z * ctx->map.squash_z;
		flat.x = atan2(hold.y, hold.x);
		flat.x = fabs(flat.x) - 1.0;
		flat.y = atan2(hold.z, sqrt(hold.x * hold.x + hold.y * hold.y)) + M_PI * 0.125;
		flat.y = fabs(flat.y) - 1.0;
	}
	// else if (ctx->map.projection == STEREO)
	// {
	// 	flat.x = vec->x * ctx->map.squash_x / (1.0 + vec->z * ctx->map.squash_z);
	// 	flat.y = vec->y * ctx->map.squash_y / (1.0 + vec->z * ctx->map.squash_z);
	// }
	else if (ctx->map.projection == ORTHO)
	{
		flat.x	= vec->x * ctx->map.squash_x;
		flat.y	= vec->y * ctx->map.squash_y;
	}
	else
	{
		flat.x = (vec->x - vec->y) * ctx->map.squash_x;
		flat.y = (vec->x + vec->y) * ctx->map.squash_y - vec->z * ctx->map.squash_z;
	}
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
	out.color = color;
	return (out);
}
