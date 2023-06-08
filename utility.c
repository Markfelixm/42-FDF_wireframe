/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmulle <marmulle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 12:20:59 by marmulle          #+#    #+#             */
/*   Updated: 2023/06/08 23:03:07 by marmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	hex_to_int(char hex)
{
	if (hex <= '9')
		return (hex - '0');
	if (hex <= 'F')
		return (hex - 'A' + 10);
	return (hex - 'a' + 10);
}

void	close_window(t_context *ctx)
{
	free_map(&(ctx->map));
	exit(0);
}

int	at(t_map *map, int column, int row)
{
	return (row * map->width + column);
}
