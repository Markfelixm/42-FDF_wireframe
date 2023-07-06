/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmulle <marmulle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 12:20:49 by marmulle          #+#    #+#             */
/*   Updated: 2023/07/06 15:42:42 by marmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

//TODO: check what is being used

double	lerp(double from, double to, double at)
{
	return (from * (1.0 - at) + (to * at));
}

double	points_distance_2d(t_point from, t_point to)
{
	double	delta_sq_x;
	double	delta_sq_y;

	delta_sq_x = pow(to.x - from.x, 2);
	delta_sq_y = pow(to.y - from.y, 2);
	return (sqrt(delta_sq_x + delta_sq_y));
}

double	vec3_distance(t_vec3 *from, t_vec3 *to)
{
	t_vec3	delta_sq;

	delta_sq.x = pow(to->x - from->x, 2);
	delta_sq.y = pow(to->y - from->y, 2);
	delta_sq.z = pow(to->z - from->z, 2);
	return (sqrt(delta_sq.x + delta_sq.y + delta_sq.z));
}

double	distance_from_origin(t_point *p)
{
	return (sqrt(pow(p->x, 2)
			+ pow(p->y, 2)
			+ pow(p->z, 2)));
}

double	vec3_product(t_vec3 *a, t_vec3 *b)
{
	return (a->x * b->x + a->y * b->y + a->z * b->z);
}

// t_vec4	vec4_mulitply(t_vec4 *a, t_vec4 *b)
// {
// 	t_vec4	result;
// 	// make matrix typedef
// 	result.
// }

t_vec2	scale_vec2(t_vec2 *vec, double scalar)
{
	return ((t_vec2) {vec->x * scalar,
		vec->y * scalar});
}

t_vec2	flatten_vec3(t_context *ctx, const t_vec3 *vec)
{
	t_vec2	out;

	out.x = (vec->x - vec->y) * cos(ctx->map.squash_x) + sin(ctx->map.rotate_x);
	out.y = (vec->x + vec->y) * sin(ctx->map.squash_y) - vec->z * cos(ctx->map.squash_z) + cos(ctx->map.rotate_x);
	return (out);
	// EQUATION OF CIRCLE. apply to both x and y.
	// possibly rotate about y axis as well? where only y value transformed
	// return ((t_vec2) {vec->x - vec->y, // TODO: remove
	// 	vec->x + vec->y - vec->z});
}

t_vec2	screen_space(t_context *ctx, const t_vec3 *vec)
{
	t_vec2	out;

	out = flatten_vec3(ctx, vec);
	out = scale_vec2(&out, ctx->map.scalar);
	out.x += ctx->map.translate_x;
	out.y += ctx->map.translate_y;
	return (out);
}
