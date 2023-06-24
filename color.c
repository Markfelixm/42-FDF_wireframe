/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmulle <marmulle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 12:21:37 by marmulle          #+#    #+#             */
/*   Updated: 2023/06/18 18:42:36 by marmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_color(char *word)
{
	int	color;
	int	cursor;
	int	end;

	word = ft_strchr(word, 'x');
	if (word == NULL)
		return (WHITE);
	end = ft_strlen(++word) - 1;
	color = 0;
	cursor = -1;
	while (++cursor <= end)
		color += hex_to_int(word[end - cursor]) * pow(16, cursor);
	return (color);
}

// TODO: using?
int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}
