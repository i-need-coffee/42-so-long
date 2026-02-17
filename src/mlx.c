/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjolliet <sjolliet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 18:39:10 by sjolliet          #+#    #+#             */
/*   Updated: 2026/02/17 17:34:43 by sjolliet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	handle_window(t_game *game)
{
	game->mlx_win = mlx_new_window(game->mlx, game->size_x * TILE_SIZE,
			game->size_y * TILE_SIZE, "so_long");
	if (!game->mlx_win)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
		free_map_and_exit(game->map, "Window failed to be initialized");
	}
}

void	init_images(t_game *game)
{
	int	tile_size;

	tile_size = TILE_SIZE;
	game->collectible_img = mlx_xpm_file_to_image(game->mlx,
			"./textures/collectible.xpm", &tile_size, &tile_size);
	game->exit_img = mlx_xpm_file_to_image(game->mlx, "./textures/exit.xpm",
			&tile_size, &tile_size);
	game->floor_img = mlx_xpm_file_to_image(game->mlx, "./textures/floor.xpm",
			&tile_size, &tile_size);
	game->player_img = mlx_xpm_file_to_image(game->mlx, "./textures/player.xpm",
			&tile_size, &tile_size);
	game->wall_img = mlx_xpm_file_to_image(game->mlx, "./textures/wall.xpm",
			&tile_size, &tile_size);
	if (!game->collectible_img || !game->exit_img || !game->floor_img
		|| !game->player_img || !game->wall_img)
	{
		mlx_destroy_window(game->mlx, game->mlx_win);
		mlx_destroy_display(game->mlx);
		free(game->mlx);
		free_map_and_exit(game->map, "Images failed to be initialized");
	}
}

void	destroy_images(t_game *game)
{
	mlx_destroy_image(game->mlx, game->collectible_img);
	mlx_destroy_image(game->mlx, game->exit_img);
	mlx_destroy_image(game->mlx, game->floor_img);
	mlx_destroy_image(game->mlx, game->player_img);
	mlx_destroy_image(game->mlx, game->wall_img);
}

int	close_game(t_game *game)
{
	free_map_data(game->map);
	mlx_destroy_window(game->mlx, game->mlx_win);
	destroy_images(game);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	exit(1);
	return (0);
}
