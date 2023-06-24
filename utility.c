/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmulle <marmulle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 12:20:59 by marmulle          #+#    #+#             */
/*   Updated: 2023/06/24 18:39:44 by marmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	at(const t_map *map, int column, int row)
{
	return (row * map->width + column);
}

int	hex_to_int(char hex)
{
	if (hex <= '9')
		return (hex - '0');
	if (hex <= 'F')
		return (hex - 'A' + 10);
	return (hex - 'a' + 10);
}

int	get_word_count(char *line)
{
	char	**splits;
	int		count;

	splits = ft_split(line, ' ');
	if (splits == NULL)
		return (0);
	count = 0;
	while (splits[count])
		count++;
	free_splits(splits);
	return (count);
}
