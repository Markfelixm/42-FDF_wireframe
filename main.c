/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmulle <marmulle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 15:35:34 by marmulle          #+#    #+#             */
/*   Updated: 2023/06/08 23:02:26 by marmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int ac, char **av)
{
	t_context	ctx;

	if (ac != 2)
		return (ft_printf("Invalid number of arguments.\n"));
	if (!get_map(&(ctx.map), av[1]))
		return (ft_printf("Error parsing file.\n"));
	// after this point the only allocated memory left to manage is map and mlx stuff
	// can free map anywhere context is passed, so exit!
	free_map(&(ctx.map));
	// ctx.mlx = mlx_init();
	// if (ctx.mlx == NULL)
	// 	return (ft_printf("Error initializing context.\n"));
	// ctx.window = mlx_new_window(ctx.mlx, WIDTH, HEIGHT, "fdf_marmulle");
	// if (ctx.window == NULL)
	// {
	// 	free(ctx.mlx);
	// 	return (ft_printf("Error creating window.\n"));
	// }
	// ctx.img_ptr = mlx_new_image(ctx.mlx, WIDTH, HEIGHT);
	// ctx.addr = mlx_get_data_addr(
	// 		ctx.img_ptr,
	// 		&ctx.bits_per_pixel,
	// 		&ctx.line_size,
	// 		&ctx.endian);
	// ctx.map.scaler = (double) HEIGHT;
	// ctx.map.rotate_step = 0.01;
	// normalize_map_point_vectors(&(ctx.map));
	// mlx_key_hook(ctx.window, key_hook, &ctx);
	// mlx_mouse_hook(ctx.window, click_hook, &ctx);
	// mlx_hook(ctx.window, ON_DESTROY, 0, destroy_hook, &ctx);
	// render(&ctx);
	// free_with_inner((void **) ctx.map.points);
	// mlx_loop_hook(ctx.mlx, render, &ctx);
	// mlx_loop(ctx.mlx);
}
