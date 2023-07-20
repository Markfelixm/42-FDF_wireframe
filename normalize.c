/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmulle <marmulle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 16:02:52 by marmulle          #+#    #+#             */
/*   Updated: 2023/07/20 22:46:58 by marmulle         ###   ########.fr       */
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
			point->vec3.x = point->x / map->normalizer;
			point->vec3.y = point->y / map->normalizer;
			point->vec3.z = point->z / map->normalizer;
		}
	}
}

void	translate_center_to_origin(t_map *map)
{
	int	i;

	i = -1;
	while (++i < map->width * map->length)
	{
		map->points[i].vec3.x = map->points[i].vec3.x * 2.0 - 1.0;
		map->points[i].vec3.y = map->points[i].vec3.y * 2.0 - 1.0;
		map->points[i].vec3.z = map->points[i].vec3.z * 2.0 - 1.0;
	}
}

double	distance_from_origin(t_point *p)
{
	return (sqrt(p->x * p->x
			+ p->y * p->y
			+ p->z * p->z));
}
