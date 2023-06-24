/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmulle <marmulle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 12:24:48 by marmulle          #+#    #+#             */
/*   Updated: 2023/06/24 20:21:54 by marmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	key_hook(int keycode, t_context *ctx)
{
	ft_printf("key hook: %d\n", keycode);
	if (keycode == KEY_ESC)
		close_window(ctx, 0);
	else if (keycode == KEY_W || keycode == KEY_S
		|| keycode == KEY_A || keycode == KEY_D
		|| keycode == KEY_Q || keycode == KEY_E)
		translate_hooks(keycode, ctx);
	else if (keycode == KEY_R || keycode == KEY_F)
		scale_hooks(keycode, ctx);
	else if (keycode == KEY_SPACE)
		set_map_defaults(&(ctx->map));
	return (keycode);
}

int	click_hook(int keycode, t_context *ctx)
{
	(void) ctx;
	ft_printf("click hook: %d\n", keycode);
	return (keycode);
}

int	destroy_hook(int keycode, t_context *ctx)
{
	(void) ctx;
	exit(0);
	return (keycode);
}
