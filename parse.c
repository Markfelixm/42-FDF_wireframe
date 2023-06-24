/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmulle <marmulle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 12:20:54 by marmulle          #+#    #+#             */
/*   Updated: 2023/06/24 20:19:41 by marmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

bool	set_dimensions(t_map *map, char *line)
{
	int	count;

	count = get_word_count(line);
	if (count == 0)
		return (false);
	if (map->width == 0 && map->length == 0)
		map->width = count;
	else if (map->width != count)
		return (false);
	map->length++;
	return (true);
}

void	parse_point(t_map *map, char *word)
{
	static int	x = 0;
	static int	y = 0;
	int			i;

	i = at(map, x, y);
	map->points[i].x = x;
	map->points[i].y = y;
	map->points[i].z = ft_atoi(word);
	map->points[i].color = get_color(word);
	x++;
	if (x == map->width)
	{
		x = 0;
		y++;
	}
}

bool	parse_points(t_map *map, char *line)
{
	char	**splits;
	int		i;

	splits = ft_split(line, ' ');
	if (splits == NULL)
		return (false);
	i = -1;
	while (splits[++i])
		parse_point(map, splits[i]);
	free_splits(splits);
	return (true);
}

bool	parse_file(t_map *map, const char *filename,
	bool (*func)(t_map *, char *))
{
	int		fd;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		(perror("Error opening file: "), exit(errno));
	while (42)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		if (!func(map, line))
			return (free(line), false);
		free(line);
	}
	if (close(fd))
		(perror("Error closing file: "), exit(errno));
	return (true);
}

bool	get_map(t_map *map, const char *filename)
{
	ft_bzero(map, sizeof(t_map));
	set_map_defaults(map);
	if (!parse_file(map, filename, set_dimensions))
		return (false);
	map->points = ft_calloc(map->width * map->length, sizeof(t_point));
	if (map->points == NULL)
		exit(ft_printf("Error allocating points.\n"));
	if (!parse_file(map, filename, parse_points))
		return (false);
	return (true);
}
