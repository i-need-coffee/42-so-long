/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjolliet <sjolliet@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 15:41:07 by sjolliet          #+#    #+#             */
/*   Updated: 2026/02/14 21:50:28 by sjolliet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	fill_map_data(t_map_data *map, char *file);
static char	*get_joined_file(int fd);
static int	check_chars(char *map);

void	parse_map(char *file, t_map_data *map)
{
	fill_map_data(map, file);
	map->size_x = ft_strlen(map->data[0]);
	map->size_y = 0;
	while (map->data[map->size_y])
	{
		if ((int)ft_strlen(map->data[map->size_y]) != map->size_x)
		{
			free_map_data(map->data);
			error_and_exit("The map is invalid");
		}
		map->size_y += 1;
	}
	if (map->size_x < 3 || map->size_y < 3)
	{
		free_map_data(map->data);
		error_and_exit("The map is invalid");
	}
}

static void	fill_map_data(t_map_data *map, char *file)
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
		error_and_exit("Problem while reading the file");
	if (!check_chars(joined_map))
	{
		free(joined_map);
		error_and_exit("There are invalid chars in the map");
	}
	map->data = ft_split(joined_map, '\n');
	free(joined_map);
	if (!map->data)
		error_and_exit("Problem while parsing the map");
}

static char	*get_joined_file(int fd)
{
	char	*line;
	char	*temp;
	char	*join;

	line = get_next_line(fd);
	join = NULL;
	while (line)
	{
		temp = ft_strjoin(join, line);
		if (!temp || line[0] == '\n')
			return (free(line), free(join), NULL);
		free(join);
		join = temp;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	return (join);
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
