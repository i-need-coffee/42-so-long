/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjolliet <sjolliet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 15:41:07 by sjolliet          #+#    #+#             */
/*   Updated: 2026/02/13 17:51:43 by sjolliet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	parse_map(char *file)
{
	char	*ext;
	char	*line;
	char	*join;
	char	*tmp;
	int		fd;

	ext = ft_strrchr(file, '.');
	if (!ext || ft_strncmp(ext, ".ber", ft_strlen(ext)) != 0)
		error_and_exit("Parameter passed is not a .ber file");
	fd = open(file, O_RDONLY);
	if (fd == -1)
		error_and_exit("File could not be opened");
	line = get_next_line(fd);
	join = NULL;
	while (line != NULL)
	{
		tmp = ft_strjoin(join, line);
		free(join);
		join = tmp;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	free(join);
	close(fd);
}
