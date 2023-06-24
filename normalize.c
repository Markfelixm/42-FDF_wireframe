/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmulle <marmulle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 16:02:52 by marmulle          #+#    #+#             */
/*   Updated: 2023/06/19 15:04:28 by marmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_normalizer(t_map *map)
{
	double	distance;
	double	greatest;
	int		x;
	int		y;

	greatest = 1;
	y = -1;
	while (++y < map->length)
	{
		x = -1;
		while (++x < map->width)
		{
			distance = distance_from_origin(&(map->points[at(map, x, y)]));
			if (distance > greatest)
				greatest = distance;
		}
	}
	map->normalizer = greatest;
}

void	normalize_map_point_vectors(t_map *map)
{
	t_point			*point;
	int				x;
	int				y;

	y = -1;
	while (++y < map->length)
	{
		x = -1;
		while (++x < map->width)
		{
			point = &(map->points[at(map, x, y)]);
			point->vec4.x = point->x / map->normalizer;
			point->vec4.y = point->y / map->normalizer;
			point->vec4.z = point->z / map->normalizer;
			point->vec4.w = 1;
		}
	}
}

// TODO: can probably apply vec math
void	translate_origin_to_center(t_map *map)
{
	int	i;

	i = -1;
	while (++i < map->width * map->length)
	{
		map->points[i].vec4.x = map->points[i].vec4.x * 2.0 - 1.0;
		map->points[i].vec4.y = map->points[i].vec4.y * 2.0 - 1.0;
		map->points[i].vec4.z = map->points[i].vec4.z * 2.0 - 1.0;
	}
}
