/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmulle <marmulle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 12:20:49 by marmulle          #+#    #+#             */
/*   Updated: 2023/07/20 22:48:15 by marmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_uint	unsigned_pow(t_uint base, t_uint exp)
{
	t_uint	out;

	out = 1;
	while (exp)
	{
		if (exp % 2)
			out *= base;
		exp /= 2;
		base *= base;
	}
	return (out);
}

double	lerp(double from, double to, double at)
{
	if (at > 1.0)
		at = 1.0;
	else if (at < 0.0)
		at = 0.0;
	return (from * (1.0 - at) + (to * at));
}

double	vec2c_distance(t_vec2c *from, t_vec2c *to)
{
	t_vec2c	delta_sq;

	delta_sq.x = (to->x - from->x) * (to->x - from->x);
	delta_sq.y = (to->y - from->y) * (to->y - from->y);
	return (sqrt(delta_sq.x + delta_sq.y));
}

t_vec2c	scale_vec2(t_vec2c *vec, double scalar)
{
	return ((t_vec2c){vec->x * scalar,
		vec->y * scalar, vec->color});
}
