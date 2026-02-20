/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjolliet <sjolliet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 12:33:45 by sjolliet          #+#    #+#             */
/*   Updated: 2026/02/20 15:35:16 by sjolliet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	move_player(t_game *game, int x, int y);

void	move_player_up(t_game *game)
{
	int	x;
	int	y;

	x = game->pos_p_x;
	y = game->pos_p_y - 1;
	if (!move_player(game, x, y))
		return ;
	game->pos_p_y--;
}

void	move_player_down(t_game *game)
{
	int	x;
	int	y;

	x = game->pos_p_x;
	y = game->pos_p_y + 1;
	if (!move_player(game, x, y))
		return ;
	game->pos_p_y++;
}

void	move_player_left(t_game *game)
{
	int	x;
	int	y;

	x = game->pos_p_x - 1;
	y = game->pos_p_y;
	if (!move_player(game, x, y))
		return ;
	game->pos_p_x--;
}

void	move_player_right(t_game *game)
{
	int	x;
	int	y;

	x = game->pos_p_x + 1;
	y = game->pos_p_y;
	if (!move_player(game, x, y))
		return ;
	game->pos_p_x++;
}

static int	move_player(t_game *game, int x, int y)
{
	if (game->map[y][x] == '1')
		return (0);
	if (game->map[y][x] == 'C')
	{
		game->num_c--;
		if (game->num_c == 0)
			game->map[game->pos_e_y][game->pos_e_x] = 'E';
	}
	if (game->map[y][x] == 'E' && game->num_c == 0)
	{
		game->num_moves++;
		ft_printf("End of game! Total movements: %d\n", game->num_moves);
		close_game(game);
	}
	game->map[y][x] = 'P';
	if (game->map[game->pos_p_y][game->pos_p_x] != 'E')
		game->map[game->pos_p_y][game->pos_p_x] = '0';
	draw_map(game);
	game->num_moves++;
	ft_printf("Number of movements: %d\n", game->num_moves);
	return (1);
}
