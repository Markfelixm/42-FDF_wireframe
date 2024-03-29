/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmulle <marmulle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 14:50:55 by marmulle          #+#    #+#             */
/*   Updated: 2023/07/20 20:50:37 by marmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_context(t_context *ctx)
{
	ctx->mlx = mlx_init();
	if (ctx->mlx == NULL)
		close_window(ctx, ft_printf("Error initializing context.\n"));
	ctx->window = mlx_new_window(ctx->mlx, WIDTH, HEIGHT, "fdf_marmulle");
	if (ctx->window == NULL)
		close_window(ctx, ft_printf("Error creating window.\n"));
	ctx->img_ptr = mlx_new_image(ctx->mlx, WIDTH, HEIGHT);
	if (ctx->img_ptr == NULL)
		close_window(ctx, ft_printf("Error creating image.\n"));
	ctx->addr = mlx_get_data_addr(
			ctx->img_ptr,
			&ctx->bits_per_pixel,
			&ctx->line_size,
			&ctx->endian);
}

void	free_splits(char **splits)
{
	int	i;

	if (splits == NULL)
		return ;
	i = -1;
	while (splits[++i])
	{
		free(splits[i]);
		splits[i] = NULL;
	}
	free(splits);
	splits = NULL;
}

void	free_map(t_map *map)
{
	if (map == NULL)
		return ;
	if (map->points)
	{
		free(map->points);
		map->points = NULL;
	}
}

void	close_window(t_context *ctx, int exit_code)
{
	free_map(&(ctx->map));
	exit(exit_code);
}

void	set_map_defaults(t_map *map)
{
	map->projection = ISO;
	map->scalar = HEIGHT * 0.25;
	map->translate_step = 10.0;
	map->translate_x = WIDTH * 0.5;
	map->translate_y = HEIGHT * 0.5;
	map->rotate = 0.0;
	map->rotate_step = 0.1;
	map->squash_x = 1.0;
	map->squash_y = cos(M_PI / 6.0);
	map->squash_z = 1.0;
	map->squash_step = 0.1;
}
