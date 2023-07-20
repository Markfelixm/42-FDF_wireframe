/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmulle <marmulle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 20:19:02 by marmulle          #+#    #+#             */
/*   Updated: 2023/07/20 22:34:23 by marmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_vec2c	project_conical(t_context *ctx, t_vec3 *vec)
{
	t_vec3	hold;
	t_vec2c	flat;

	hold.x = 1 - vec->x * ctx->map.squash_x;
	hold.y = 1 - vec->y * ctx->map.squash_y;
	hold.z = 1 - vec->z * ctx->map.squash_z;
	flat.x = atan2(hold.y, hold.x);
	flat.x = fabs(flat.x) - 1.0;
	flat.y = atan2(hold.z, sqrt(hold.x * hold.x + hold.y * hold.y));
	flat.y = fabs(flat.y) - 1.0 + M_PI * 0.125;
	return (flat);
}

t_vec2c	flatten_vec3(t_context *ctx, t_vec3 *vec)
{
	t_vec2c	flat;
	t_vec2c	rotated;
	t_vec3	squashed;

	squashed = squash_vec3(ctx, vec);
	if (ctx->map.projection == CONIC)
		flat = project_conical(ctx, vec);
	else if (ctx->map.projection == ORTHO)
	{
		flat.x = squashed.x;
		flat.y = squashed.y;
	}
	else
	{
		flat.x = squashed.x - squashed.y;
		flat.y = squashed.x + squashed.y - squashed.z;
	}
	rotated.x = flat.x * cos(ctx->map.rotate) - flat.y * sin(ctx->map.rotate);
	rotated.y = flat.y * cos(ctx->map.rotate) + flat.x * sin(ctx->map.rotate);
	return (rotated);
}

t_vec3	squash_vec3(t_context *ctx, t_vec3 *vec)
{
	return ((t_vec3){vec->x * ctx->map.squash_x, 
		vec->y * ctx->map.squash_y, 
		vec->z * ctx->map.squash_z});
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
