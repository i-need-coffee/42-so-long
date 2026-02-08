/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjolliet <sjolliet@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 11:40:57 by sjolliet          #+#    #+#             */
/*   Updated: 2026/02/08 20:56:04 by sjolliet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include "mlx.h"
# include <X11/keysym.h>
# include <X11/X.h>

# define WIN_WIDTH 500
# define WIN_HEIGHT 500

typedef struct s_mlx_data
{
	void	*connect;
	void	*window;
}			t_mlx_data;

#endif