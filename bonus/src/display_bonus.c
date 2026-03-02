/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjolliet <sjolliet@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 18:39:10 by sjolliet          #+#    #+#             */
/*   Updated: 2026/03/02 13:20:54 by sjolliet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	*load_xpm(t_game *game, char *path);

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
	game->collectible_img = load_xpm(game, "./textures/collectible.xpm");
	game->exit_img = load_xpm(game, "./textures/exit.xpm");
	game->floor_img = load_xpm(game, "./textures/floor.xpm");
	game->player_img = load_xpm(game, "./textures/player.xpm");
	game->player_img_2 = load_xpm(game, "./textures/player_2.xpm");
	game->player_img_3 = load_xpm(game, "./textures/player_3.xpm");
	game->wall_img = load_xpm(game, "./textures/wall.xpm");
	game->enemy_img = load_xpm(game, "./textures/enemy.xpm");
	game->game_over_img = load_xpm(game, "./textures/game_over.xpm");
	if (!game->collectible_img || !game->exit_img || !game->floor_img
		|| !game->player_img || !game->player_img_2 || !game->player_img_3
		|| !game->wall_img || !game->enemy_img || !game->game_over_img)
	{
		destroy_images(game);
		mlx_destroy_window(game->mlx, game->mlx_win);
		mlx_destroy_display(game->mlx);
		free(game->mlx);
		free_map_and_exit(game->map, "Images failed to be initialized");
	}
}

void	destroy_images(t_game *game)
{
	if (game->collectible_img)
		mlx_destroy_image(game->mlx, game->collectible_img);
	if (game->exit_img)
		mlx_destroy_image(game->mlx, game->exit_img);
	if (game->floor_img)
		mlx_destroy_image(game->mlx, game->floor_img);
	if (game->player_img)
		mlx_destroy_image(game->mlx, game->player_img);
	if (game->player_img_2)
		mlx_destroy_image(game->mlx, game->player_img_2);
	if (game->player_img_3)
		mlx_destroy_image(game->mlx, game->player_img_3);
	if (game->wall_img)
		mlx_destroy_image(game->mlx, game->wall_img);
	if (game->enemy_img)
		mlx_destroy_image(game->mlx, game->enemy_img);
	if (game->game_over_img)
		mlx_destroy_image(game->mlx, game->game_over_img);
}

static void	*load_xpm(t_game *game, char *path)
{
	int	w;
	int	h;

	w = TILE_SIZE;
	h = TILE_SIZE;
	return (mlx_xpm_file_to_image(game->mlx, path, &w, &h));
}
