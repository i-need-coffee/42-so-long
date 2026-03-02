/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemies_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjolliet <sjolliet@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 15:05:29 by sjolliet          #+#    #+#             */
/*   Updated: 2026/03/02 11:06:01 by sjolliet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	init_enemies(t_game *game)
{
	int	i;
	int	x;
	int	y;

	game->enemies = malloc(sizeof(t_enemy) * game->num_x);
	if (!game->enemies)
		free_map_and_exit(game->map, "Malloc allocation failed");
	i = 0;
	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'X')
			{
				game->enemies[i].x = x;
				game->enemies[i].y = y;
				game->enemies[i].dir = -1;
				game->map[y][x] = '0';
				i++;
			}
			x++;
		}
		y++;
	}
}

void	move_enemies(t_game *game)
{
	int	i;
	int	x;
	int	y;

	i = 0;
	while (i < game->num_x)
	{
		x = game->enemies[i].x + game->enemies[i].dir;
		y = game->enemies[i].y;
		if (x == game->pos_p_x && y == game->pos_p_y)
			close_game(game); //TODO: add a game over that frees everything and shows a game over screen
		if (game->map[y][x] == '0')
			game->enemies[i].x = x;
		else
			game->enemies[i].dir *= -1;
		i++;
	}
}

void	draw_enemies(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->num_x)
	{
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->enemy_img,
			game->enemies[i].x * TILE_SIZE, game->enemies[i].y * TILE_SIZE);
		i++;
	}
}
