/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmulle <marmulle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 12:24:48 by marmulle          #+#    #+#             */
/*   Updated: 2023/07/20 19:47:33 by marmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	key_hook(int keycode, t_context *ctx)
{
	// ft_printf("key hook: %d\n", keycode); // TODO: RM
	if (keycode == KEY_ESC)
		close_window(ctx, 0);
	else if (keycode == KEY_W || keycode == KEY_S
		|| keycode == KEY_A || keycode == KEY_D
		|| keycode == KEY_Z || keycode == KEY_X || keycode == KEY_C)
		translate_hooks(keycode, ctx);
	else if (keycode == KEY_R || keycode == KEY_F || keycode == KEY_V
		|| keycode == KEY_4 || keycode == KEY_5 || keycode == KEY_6)
		scale_hooks(keycode, ctx);
	else if (keycode == KEY_SPACE)
		set_map_defaults(&(ctx->map));
	else if (keycode == KEY_P)
		parallel_projection_hook(keycode, ctx);
	else if (keycode == KEY_U || keycode == KEY_J
		|| keycode == KEY_I || keycode == KEY_K
		|| keycode == KEY_O || keycode == KEY_L
		|| keycode == KEY_7 || keycode == KEY_8 || keycode == KEY_9)
		squash_hooks(keycode, ctx);
	else if (keycode == KEY_Q || keycode == KEY_E
		|| keycode == KEY_1 || keycode == KEY_2 || keycode == KEY_3
		|| keycode == KEY_T || keycode == KEY_G
		|| keycode == KEY_Y || keycode == KEY_H)
		rotate_hooks(keycode, ctx);
	return (keycode);
}

int	click_hook(int keycode, t_context *ctx)
{
	(void) ctx;
	// ft_printf("click hook: %d\n", keycode); // TODO: RM
	return (keycode);
}

int	destroy_hook(int keycode, t_context *ctx)
{
	(void) ctx;
	exit(0);
	return (keycode);
}
