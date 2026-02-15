/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_path_validation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjolliet <sjolliet@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 19:58:28 by sjolliet          #+#    #+#             */
/*   Updated: 2026/02/15 23:59:31 by sjolliet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	find_player_pos(t_map_data *map);
static char	**get_map_data_copy(t_map_data *map);
static void	map_surroundings(char **map, int x, int y);

void	check_map_path(t_map_data *map)
{
	char	**map_copy;
	int		x;
	int		y;
	int		i;

	find_player_pos(map);
	map_copy = get_map_data_copy(map);
	i = 0;
	while (i < (map->size_y - 2) * (map->size_x - 2))
	{
		y = 0;
		while (map_copy[y])
		{
			x = 0;
			while (map_copy[y][x])
			{
				if (map_copy[y][x] == 'P')
					map_surroundings(map_copy, x, y);
				x++;
			}
			y++;
		}
		i++;
	}
	i = 0;
	while (map_copy[i])
	{
		ft_printf("%s[%d]\n", map_copy[i], i);
		i++;
	}
	free_map_data(map_copy);
}

static void	find_player_pos(t_map_data *map)
{
	int	curr_x;
	int	curr_y;

	curr_y = 0;
	while (curr_y < map->size_y)
	{
		curr_x = 0;
		while (curr_x < map->size_x)
		{
			if (map->data[curr_y][curr_x] == 'P')
			{
				map->pos_p_x = curr_x;
				map->pos_p_y = curr_y;
				break ;
			}
			curr_x++;
		}
		curr_y++;
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
	while (i < map->size_y)
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

static void	map_surroundings(char **map, int x, int y)
{
	int	top;
	int	bottom;
	int	left;
	int	right;

	top = map[y - 1][x];
	bottom = map[y + 1][x];
	left = map[y][x - 1];
	right = map[y][x + 1];
	if (top != '1')
		map[y - 1][x] = 'P';
	if (bottom != '1')
		map[y + 1][x] = 'P';
	if (left != '1')
		map[y][x - 1] = 'P';
	if (right != '1')
		map[y][x + 1] = 'P';
}
