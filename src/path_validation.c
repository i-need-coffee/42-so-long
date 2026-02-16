/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_path_validation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjolliet <sjolliet@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 19:58:28 by sjolliet          #+#    #+#             */
/*   Updated: 2026/02/16 14:23:23 by sjolliet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	find_player_pos(t_map_data *map);
static char	**get_map_data_copy(t_map_data *map);
static void	move_on_path(char **map, int x, int y);

void	check_map_path(t_map_data *map)
{
	char	**map_copy;
	int		y;
	int		x;

	find_player_pos(map);
	map_copy = get_map_data_copy(map);
	move_on_path(map_copy, map->pos_p_x, map->pos_p_y);
	y = 0;
	while (map_copy[y])
	{
		x = 0;
		while (map_copy[y][x])
		{
			if (map_copy[y][x] == 'C' || map_copy[y][x] == 'E')
			{
				free_map_data(map_copy);
				free_map_and_exit(map->data, "No valid path exists");
			}
			x++;
		}
		y++;
	}
	free_map_data(map_copy);
}

static void	find_player_pos(t_map_data *map)
{
	int	y;
	int	x;

	y = 0;
	while (map->data[y])
	{
		x = 0;
		while (map->data[y][x])
		{
			if (map->data[y][x] == 'P')
			{
				map->pos_p_x = x;
				map->pos_p_y = y;
				return ;
			}
			x++;
		}
		y++;
	}
}

static char	**get_map_data_copy(t_map_data *map)
{
	char	**map_copy;
	int		i;

	map_copy = malloc((map->size_y + 1) * sizeof(char *));
	if (!map_copy)
		free_map_and_exit(map->data, "Memory allocation fail");
	i = 0;
	while (map->data[i])
	{
		map_copy[i] = ft_strdup(map->data[i]);
		if (!map_copy[i])
		{
			map_copy[i] = NULL;
			free_map_data(map_copy);
			free_map_and_exit(map->data, "Memory allocation fail");
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
