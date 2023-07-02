/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_utility.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfm <mfm@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 19:55:11 by marmulle          #+#    #+#             */
/*   Updated: 2023/07/02 23:11:25 by mfm              ###   ########.fr       */
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

void	rotate_hooks(int keycode, t_context *ctx)
{
	if (keycode == KEY_UP)
		ctx->map.rotate_y += 0.05;
	else if (keycode == KEY_DOWN)
		ctx->map.rotate_y -= 0.05;
	else if (keycode == KEY_LEFT)
		ctx->map.rotate_x += 0.05;
	else if (keycode == KEY_RIGHT)
		ctx->map.rotate_x -= 0.05;
}

// void	parallel_projection_hook(int keycode, t_context *ctx)
// {

// }
