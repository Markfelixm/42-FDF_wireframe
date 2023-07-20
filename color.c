/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmulle <marmulle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 12:21:37 by marmulle          #+#    #+#             */
/*   Updated: 2023/07/19 21:49:37 by marmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_uint	get_color(char *word)
{
	t_uint	color;
	int		cursor;
	int		end;

	word = ft_strchr(word, 'x');
	if (word == NULL)
		return (WHITE);
	end = ft_strlen(++word) - 1;
	color = 0;
	cursor = -1;
	while (++cursor <= end)
		color += hex_to_int(word[end - cursor]) 
			* unsigned_pow((t_uint) 16, (t_uint) cursor);
	return (color);
}

t_uint	lerp_color(t_uint from, t_uint to, double at)
{
	const int	r = lerp((double)((from >> 16) & 0xFF), 
			(double)((to >> 16) & 0xFF), at);
	const int	g = lerp((double)((from >> 8) & 0xFF), 
			(double)((to >> 8) & 0xFF), at);
	const int	b = lerp((double)(from & 0xFF), 
			(double)(to & 0xFF), at);

	return (create_trgb(0, r, g, b));
}

t_uint	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}
