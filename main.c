/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmulle <marmulle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 15:35:34 by marmulle          #+#    #+#             */
/*   Updated: 2023/06/24 20:20:35 by marmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int ac, char **av)
{
	t_context	ctx;
	t_map		*map;

	if (ac != 2)
		return (ft_printf("Invalid number of arguments.\n"));
	map = &(ctx.map);
	if (!get_map(map, av[1]))
		return (ft_printf("Error parsing file.\n"));
	init_context(&ctx);
	set_normalizer(map);
	normalize_map_point_vectors(map);
	translate_origin_to_center(map);
	mlx_key_hook(ctx.window, key_hook, &ctx);
	mlx_mouse_hook(ctx.window, click_hook, &ctx);
	mlx_hook(ctx.window, ON_DESTROY, 0, destroy_hook, &ctx);
	mlx_loop_hook(ctx.mlx, render, &ctx);
	mlx_loop(ctx.mlx);
}
