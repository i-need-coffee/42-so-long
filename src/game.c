/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjolliet <sjolliet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 12:33:45 by sjolliet          #+#    #+#             */
/*   Updated: 2026/02/19 16:16:02 by sjolliet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_player_up(t_game *game)
{
	int		x;
	int		y;

	x = game->pos_p_x;
	y = game->pos_p_y;
	if (game->map[y - 1][x] == '1')
		return ;
	game->map[y - 1][x] = 'P';
	game->map[y][x] = '0';
	game->pos_p_y--;
	draw_map(game);
}

void	move_player_down(t_game *game)
{
	int		x;
	int		y;

	x = game->pos_p_x;
	y = game->pos_p_y;
	if (game->map[y + 1][x] == '1')
		return ;
	game->map[y + 1][x] = 'P';
	game->map[y][x] = '0';
	game->pos_p_y++;
	draw_map(game);
}

void	move_player_left(t_game *game)
{
	int		x;
	int		y;

	x = game->pos_p_x;
	y = game->pos_p_y;
	if (game->map[y][x - 1] == '1')
		return ;
	game->map[y][x - 1] = 'P';
	game->map[y][x] = '0';
	game->pos_p_x--;
	draw_map(game);
}

void	move_player_right(t_game *game)
{
	int		x;
	int		y;

	x = game->pos_p_x;
	y = game->pos_p_y;
	if (game->map[y][x + 1] == '1')
		return ;
	game->map[y][x + 1] = 'P';
	game->map[y][x] = '0';
	game->pos_p_x++;
	draw_map(game);
}
