/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_utility.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmulle <marmulle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 19:55:11 by marmulle          #+#    #+#             */
/*   Updated: 2023/06/24 20:25:23 by marmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	translate_hooks(int keycode, t_context *ctx)
{
	if (keycode == KEY_W)
		ctx->map.translate_y -= ctx->map.translate_step;
	else if (keycode == KEY_S)
		ctx->map.translate_y += ctx->map.translate_step;
	else if (keycode == KEY_A)
		ctx->map.translate_x -= ctx->map.translate_step;
	else if (keycode == KEY_D)
		ctx->map.translate_x += ctx->map.translate_step;
	else if (keycode == KEY_Q)
		ctx->map.translate_step *= 0.8;
	else if (keycode == KEY_E)
		ctx->map.translate_step *= 1.2;
	if (ctx->map.translate_step == 0.0)
		set_map_defaults(&(ctx->map));
}

void	scale_hooks(int keycode, t_context *ctx)
{
	if (keycode == KEY_R)
		ctx->map.scalar *= 1.2;
	else if (keycode == KEY_F)
		ctx->map.scalar *= 0.8;
}
