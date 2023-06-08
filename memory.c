/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmulle <marmulle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 14:50:55 by marmulle          #+#    #+#             */
/*   Updated: 2023/06/08 22:56:08 by marmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_splits(char **splits)
{
	int	i;

	if (splits == NULL)
		return ;
	i = -1;
	while (splits[++i])
	{
		free(splits[i]);
		splits[i] = NULL;
	}
	free(splits);
	splits = NULL;
}

void	free_map(t_map *map)
{
	if (map == NULL)
		return ;
	free(map->points);
	map->points = NULL;
}
