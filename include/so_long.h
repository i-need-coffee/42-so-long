/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjolliet <sjolliet@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 11:40:57 by sjolliet          #+#    #+#             */
/*   Updated: 2026/02/15 15:03:55 by sjolliet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <libft.h>
# include <mlx.h>

typedef struct s_map_data
{
	char	**data;
	int		size_x;
	int		size_y;
}			t_map_data;

typedef struct s_mlx_data
{
	void	*connect;
	void	*window;
}			t_mlx_data;

void		error_and_exit(char *error_message);
void		parse_map(char *file, t_map_data *map);
void		free_map_data(char **map_data);
void		free_map_and_exit(char **map_data, char *error_message);

#endif