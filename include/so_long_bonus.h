/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjolliet <sjolliet@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 11:40:57 by sjolliet          #+#    #+#             */
/*   Updated: 2026/03/02 15:27:17 by sjolliet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <libft.h>
# include <mlx.h>
# include <sys/time.h>

typedef struct s_enemy
{
	int		x;
	int		y;
	int		dir;
}			t_enemy;

typedef struct s_game
{
	char	**map;
	int		size_x;
	int		size_y;
	int		pos_p_x;
	int		pos_p_y;
	int		pos_e_x;
	int		pos_e_y;
	int		num_c;
	int		total_c;
	int		num_moves;
	void	*mlx;
	void	*mlx_win;
	void	*collectible_img;
	void	*exit_img;
	void	*floor_img;
	void	*player_img;
	void	*player_img_2;
	void	*player_img_3;
	void	*wall_img;
	void	*enemy_img;
	void	*game_over_img;
	t_enemy	*enemies;
	int		num_x;
	long	last_enemy_ms;
	int		enemy_delay_ms;
	
}			t_game;

# ifndef TILE_SIZE
#  define TILE_SIZE 64
# endif

# ifndef ENEMY_SPEED
#  define ENEMY_SPEED 250
# endif

void		error_and_exit(char *error_message);
void		parse_map(char *file, t_game *game);
void		free_map_data(char **map_data);
void		free_map_and_exit(char **map_data, char *error_message);
char		*get_joined_file(int fd);
void		check_map_path(t_game *game);
void		handle_window(t_game *game);
int			handle_input(int keysym, t_game *game);
int			close_game(t_game *game);
void		init_images(t_game *game);
void		destroy_images(t_game *game);
void		draw_map(t_game *game);
void		move_player_up(t_game *game);
void		move_player_down(t_game *game);
void		move_player_left(t_game *game);
void		move_player_right(t_game *game);
void		check_map_size(t_game *game);
void		display_moves(t_game *game);
void		init_enemies(t_game *game);
void		move_enemies(t_game *game);
int			loop_hook(t_game *game);
void		draw_enemies(t_game *game);
long		now_ms(void);
void		game_over(t_game *game);

#endif