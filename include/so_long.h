/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjolliet <sjolliet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 11:40:57 by sjolliet          #+#    #+#             */
/*   Updated: 2026/02/17 15:33:04 by sjolliet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <libft.h>
# include <mlx.h>

typedef struct s_game
{
	char	**map;
	int		size_x;
	int		size_y;
	int		pos_p_x;
	int		pos_p_y;
	int		num_c;
	void	*mlx;
	void	*mlx_win;
}			t_game;

# ifndef TILE_SIZE
#  define TILE_SIZE 64
# endif

void		error_and_exit(char *error_message);
void		init_and_check_map(char *file, t_game *game);
void		free_map_data(char **map_data);
void		free_map_and_exit(char **map_data, char *error_message);
char		*get_joined_file(int fd);
void		check_map_path(t_game *game);
void		handle_window(t_game *game);
int			handle_input(int keysym, t_game *game);
int			close_game(t_game *game);

#endif