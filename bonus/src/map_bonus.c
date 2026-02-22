/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjolliet <sjolliet@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 17:20:25 by sjolliet          #+#    #+#             */
/*   Updated: 2026/02/22 11:38:10 by sjolliet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	choose_img_to_draw(t_game *game, char c, int x, int y);

void	draw_map(t_game *game)
{
	int		y;
	int		x;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			choose_img_to_draw(game, game->map[y][x], x, y);
			x++;
		}
		y++;
	}
	display_moves(game);
}

static void	choose_img_to_draw(t_game *game, char c, int x, int y)
{
	if (c == '1')
		put_img_to_window(game, game->wall_img, x, y);
	else if (c == 'C')
		put_img_to_window(game, game->collectible_img, x, y);
	else if (c == 'E')
		put_img_to_window(game, game->exit_img, x, y);
	else if (c == 'P')
	{
		if (game->total_c == game->num_c)
			put_img_to_window(game, game->player_img, x, y);
		else if (game->num_c == 0)
			put_img_to_window(game, game->player_img_3, x, y);
		else
			put_img_to_window(game, game->player_img_2, x, y);
	}
	else
		put_img_to_window(game, game->floor_img, x, y);
}
