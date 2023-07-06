/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_utility.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmulle <marmulle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 19:55:11 by marmulle          #+#    #+#             */
/*   Updated: 2023/07/06 15:36:48 by marmulle         ###   ########.fr       */
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
	if (keycode == KEY_X || ctx->map.translate_step == 0.0)
		ctx->map.translate_step = 10;
}

void	scale_hooks(int keycode, t_context *ctx)
{
	if (keycode == KEY_V)
		ctx->map.scalar *= 1.2;
	else if (keycode == KEY_B)
		ctx->map.scalar = 270; // TODO: dynamically calc
	else if (keycode == KEY_N)
		ctx->map.scalar *= 0.8;
}

void	squash_hooks(int keycode, t_context *ctx)
{
	if (keycode == KEY_I)
		ctx->map.squash_y += 0.05;
	else if (keycode == KEY_K)
		ctx->map.squash_y -= 0.05;
	else if (keycode == KEY_J)
		ctx->map.squash_x += 0.05;
	else if (keycode == KEY_L)
		ctx->map.squash_x -= 0.05;
	else if (keycode == KEY_U)
		ctx->map.squash_z += 0.05;
	else if (keycode == KEY_O)
		ctx->map.squash_z -= 0.05;
}

void	rotate_hooks(int keycode, t_context *ctx)
{
	if (keycode == KEY_R)
		ctx->map.rotate_x += 0.1;
	else if (keycode == KEY_F)
		ctx->map.rotate_x -= 0.1;
}

void	parallel_projection_hook(int keycode, t_context *ctx)
{
	(void) keycode;
	(void) ctx;
}
