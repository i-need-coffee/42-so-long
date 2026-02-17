/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjolliet <sjolliet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 15:41:07 by sjolliet          #+#    #+#             */
/*   Updated: 2026/02/17 13:20:21 by sjolliet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	fill_map_data(t_game *game, char *file);
static int	check_chars(char *map);
static int	check_components(char *map);
static void	check_surrounding_walls(t_game *game);

void	init_and_check_map(char *file, t_game *game)
{
	fill_map_data(game, file);
	game->size_x = ft_strlen(game->map[0]);
	game->size_y = 0;
	while (game->map[game->size_y])
	{
		if ((int)ft_strlen(game->map[game->size_y]) != game->size_x)
			free_map_and_exit(game->map, "The map is not rectangular");
		game->size_y += 1;
	}
	if (game->size_x < 3 || game->size_y < 3)
		free_map_and_exit(game->map, "The map is invalid");
	check_surrounding_walls(game);
}

static void	fill_map_data(t_game *game, char *file)
{
	char	*ext;
	char	*joined_map;
	int		fd;

	ext = ft_strrchr(file, '.');
	if (!ext || ft_strncmp(ext, ".ber", ft_strlen(ext)) != 0)
		error_and_exit("Parameter passed is not a .ber file");
	fd = open(file, O_RDONLY);
	if (fd == -1)
		error_and_exit("File could not be opened");
	joined_map = get_joined_file(fd);
	close(fd);
	if (!joined_map)
		error_and_exit("Memory allocation fail or/and empty lines in map file");
	if (!check_chars(joined_map) || !check_components(joined_map))
	{
		free(joined_map);
		error_and_exit("Invalid or duplicates characters in map file");
	}
	game->map = ft_split(joined_map, '\n');
	free(joined_map);
	if (!game->map)
		error_and_exit("Memory allocation fail");
}

static int	check_chars(char *map)
{
	char	*valid_chars;
	int		i;

	valid_chars = "01CEP\n";
	i = 0;
	while (map[i])
	{
		if (!ft_strrchr(valid_chars, map[i]))
			return (0);
		i++;
	}
	return (1);
}

static int	check_components(char *map)
{
	int	i;
	int	count_c;
	int	count_e;
	int	count_p;

	i = 0;
	count_c = 0;
	count_e = 0;
	count_p = 0;
	while (map[i])
	{
		if (map[i] == 'C')
			count_c++;
		if (map[i] == 'E')
			count_e++;
		if (map[i] == 'P')
			count_p++;
		i++;
	}
	if (count_c < 1 || count_e != 1 || count_p != 1)
		return (0);
	return (1);
}

static void	check_surrounding_walls(t_game *game)
{
	int	row;
	int	i;

	row = 0;
	while (row < game->size_y)
	{
		if (row == 0 || row == (game->size_y - 1))
		{
			i = 0;
			while (game->map[row][i])
			{
				if (game->map[row][i] != '1')
					free_map_and_exit(game->map, "Not enclosed by walls");
				i++;
			}
		}
		else
		{
			if (game->map[row][0] != '1' 
				|| game->map[row][game->size_x - 1] != '1')
				free_map_and_exit(game->map, "Not enclosed by walls");
		}
		row++;
	}
}
