/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_validation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjolliet <sjolliet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 19:58:28 by sjolliet          #+#    #+#             */
/*   Updated: 2026/02/17 13:23:19 by sjolliet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	find_player_pos(t_game *game);
static char	**get_map_data_copy(t_game *game);
static void	move_on_path(char **map, int x, int y);

void	check_map_path(t_game *game)
{
	char	**map_copy;
	int		y;
	int		x;

	find_player_pos(game);
	map_copy = get_map_data_copy(game);
	move_on_path(map_copy, game->pos_p_x, game->pos_p_y);
	y = 0;
	while (map_copy[y])
	{
		x = 0;
		while (map_copy[y][x])
		{
			if (map_copy[y][x] == 'C' || map_copy[y][x] == 'E')
			{
				free_map_data(map_copy);
				free_map_and_exit(game->map, "No valid path exists");
			}
			x++;
		}
		y++;
	}
	free_map_data(map_copy);
}

static void	find_player_pos(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'P')
			{
				game->pos_p_x = x;
				game->pos_p_y = y;
				return ;
			}
			x++;
		}
		y++;
	}
}

static char	**get_map_data_copy(t_game *game)
{
	char	**map_copy;
	int		i;

	map_copy = malloc((game->size_y + 1) * sizeof(char *));
	if (!map_copy)
		free_map_and_exit(game->map, "Memory allocation fail");
	i = 0;
	while (game->map[i])
	{
		map_copy[i] = ft_strdup(game->map[i]);
		if (!map_copy[i])
		{
			map_copy[i] = NULL;
			free_map_data(map_copy);
			free_map_and_exit(game->map, "Memory allocation fail");
		}
		i++;
	}
	map_copy[i] = NULL;
	return (map_copy);
}

static void	move_on_path(char **map, int x, int y)
{
	if (map[y][x] == '1')
		return ;
	map[y][x] = '1';
	move_on_path(map, x + 1, y);
	move_on_path(map, x - 1, y);
	move_on_path(map, x, y + 1);
	move_on_path(map, x, y - 1);
}
