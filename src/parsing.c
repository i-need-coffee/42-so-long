/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjolliet <sjolliet@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 15:41:07 by sjolliet          #+#    #+#             */
/*   Updated: 2026/02/14 03:18:46 by sjolliet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	*get_joined_file(int fd);
static int	check_chars(char *map);

void	parse_map(char *file)
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
	free(joined_map);
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
		if (!temp)
		{
			free(line);
			free(join);
			return (NULL);
		}
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
