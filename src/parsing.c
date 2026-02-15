/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjolliet <sjolliet@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 15:41:07 by sjolliet          #+#    #+#             */
/*   Updated: 2026/02/15 16:13:21 by sjolliet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	fill_map_data(t_map_data *map, char *file);
static char	*get_joined_file(int fd);
static int	check_chars(char *map);
static int	check_components(char *map);
static void	check_surrounding_walls(t_map_data *map);

void	parse_map(char *file, t_map_data *map)
{
	fill_map_data(map, file);
	map->size_x = ft_strlen(map->data[0]);
	map->size_y = 0;
	while (map->data[map->size_y])
	{
		if ((int)ft_strlen(map->data[map->size_y]) != map->size_x)
			free_map_and_exit(map->data, "The map is not rectangular");
		map->size_y += 1;
	}
	if (map->size_x < 3 || map->size_y < 3)
		free_map_and_exit(map->data, "The map is invalid");
	check_surrounding_walls(map);
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
		error_and_exit("Memory allocation fail or/and empty lines in map file");
	if (!check_chars(joined_map) || !check_components(joined_map))
	{
		free(joined_map);
		error_and_exit("Invalid or duplicates characters in map file");
	}
	map->data = ft_split(joined_map, '\n');
	free(joined_map);
	if (!map->data)
		error_and_exit("Memory allocation fail");
}

static char	*get_joined_file(int fd)
{
	char	*line;
	char	*temp;
	char	*join;

	join = NULL;
	line = get_next_line(fd);
	while (line)
	{
		if (line[0] == '\n')
			return (free(line), free(join), get_next_line(-1), NULL);
		temp = ft_strjoin(join, line);
		free(line);
		free(join);
		if (!temp)
			return (get_next_line(-1), NULL);
		join = temp;
		line = get_next_line(fd);
	}
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

static int	check_components(char *map)
{
	int		i;
	int		count_c;
	int		count_e;
	int		count_p;

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

static void	check_surrounding_walls(t_map_data *map)
{
	int	row;
	int	i;

	row = 0;
	while (row < map->size_y)
	{
		if (row == 0 || row == (map->size_y - 1))
		{
			i = 0;
			while (map->data[row][i])
			{
				if (map->data[row][i] != '1')
					free_map_and_exit(map->data, "The map is not enclosed by walls");
				i++;
			}
		}
		else
		{
			if (map->data[row][0] != '1' || map->data[row][map->size_x - 1] != '1')
				free_map_and_exit(map->data, "The map is not enclosed by walls");
		}
		row++;
	}
}
