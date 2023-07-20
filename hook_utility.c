/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_utility.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmulle <marmulle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 19:55:11 by marmulle          #+#    #+#             */
/*   Updated: 2023/07/20 16:55:08 by marmulle         ###   ########.fr       */
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
	else if (keycode == KEY_Z)
		ctx->map.translate_step *= 0.75;
	else if (keycode == KEY_C)
		ctx->map.translate_step *= 1.25;
	if (keycode == KEY_X || ctx->map.translate_step <= 0.0)
		ctx->map.translate_step = 10.0;
}

void	scale_hooks(int keycode, t_context *ctx)
{
	if (keycode == KEY_V || keycode == KEY_4)
		ctx->map.scalar *= 0.8;
	else if (keycode == KEY_F || keycode == KEY_5
		|| ctx->map.scalar <= 0.0)
		ctx->map.scalar = HEIGHT * 0.25;
	else if (keycode == KEY_R || keycode == KEY_6)
		ctx->map.scalar *= 1.2;
}

void	squash_hooks(int keycode, t_context *ctx)
{
	if (keycode == KEY_I)
		ctx->map.squash_y += ctx->map.squash_step;
	else if (keycode == KEY_K)
		ctx->map.squash_y -= ctx->map.squash_step;
	else if (keycode == KEY_J)
		ctx->map.squash_x -= ctx->map.squash_step;
	else if (keycode == KEY_L)
		ctx->map.squash_x += ctx->map.squash_step;
	else if (keycode == KEY_U)
		ctx->map.squash_z -= ctx->map.squash_step;
	else if (keycode == KEY_O)
		ctx->map.squash_z += ctx->map.squash_step;
	else if (keycode == KEY_7)
		ctx->map.squash_step *= 0.75;
	else if (keycode == KEY_9)
		ctx->map.squash_step *= 1.25;
	if (keycode == KEY_8 || ctx->map.squash_step <= 0.0)
		ctx->map.squash_step = 0.1;
}

void	rotate_hooks(int keycode, t_context *ctx)
{
	if (keycode == KEY_Q)
		ctx->map.rotate -= ctx->map.rotate_step;
	else if (keycode == KEY_E)
		ctx->map.rotate += ctx->map.rotate_step;
	else if (keycode == KEY_1)
		ctx->map.rotate_step *= 0.75;
	else if (keycode == KEY_3)
		ctx->map.rotate_step *= 1.25;
	if (keycode == KEY_2 || ctx->map.rotate_step <= 0.0)
		ctx->map.rotate_step = 0.1;
}

void	parallel_projection_hook(int keycode, t_context *ctx)
{
	(void) keycode;
	(void) ctx;
}
