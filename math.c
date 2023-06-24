/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmulle <marmulle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 12:20:49 by marmulle          #+#    #+#             */
/*   Updated: 2023/06/24 18:20:38 by marmulle         ###   ########.fr       */
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

double	distance_between_points(t_point from, t_point to)
{
	double	delta_sq_x;
	double	delta_sq_y;
	double	delta_sq_z;

	delta_sq_x = pow(to.x - from.x, 2);
	delta_sq_y = pow(to.y - from.y, 2);
	delta_sq_z = pow(to.z - from.z, 2);
	return (sqrt(delta_sq_x + delta_sq_y + delta_sq_z));
}

double	distance_from_origin(t_point *p)
{
	return (sqrt(pow(p->x, 2)
		+ pow(p->y, 2)
		+ pow(p->z, 2)));
}

double	vec4_product(t_vec4 *a, t_vec4 *b)
{
	return (a->x * b->x + a->y * b->y + a->z * b->z + a->w * b->w);
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

t_vec2	flatten_vec4(t_vec4 *vec)
{
	return ((t_vec2) {vec->x - vec->y,
		vec->x + vec->y - vec->z});
}

t_vec2	screen_space(t_vec4 *vec, double scalar)
{
	t_vec2	out;

	out = flatten_vec4(vec);
	out = scale_vec2(&out, scalar);
	return (out);
}