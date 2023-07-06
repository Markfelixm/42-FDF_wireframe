/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawloop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmulle <marmulle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 16:47:52 by marmulle          #+#    #+#             */
/*   Updated: 2023/07/06 15:22:44 by marmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	blank_image(t_context *ctx)
{
	const int	addr_len = (HEIGHT - 1) * ctx->line_size
		+ (WIDTH - 1) * (ctx->bits_per_pixel / 8);

	ft_bzero(ctx->addr, addr_len);
}

int	render(t_context *ctx)
{
	blank_image(ctx);
	draw_map(ctx);
	mlx_put_image_to_window(ctx->mlx, ctx->window, ctx->img_ptr, 0, 0);
	return (0);
}
