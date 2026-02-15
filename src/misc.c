/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjolliet <sjolliet@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 15:05:54 by sjolliet          #+#    #+#             */
/*   Updated: 2026/02/15 15:02:15 by sjolliet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_and_exit(char *error_message)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(error_message, 2);
	ft_putchar_fd('\n', 2);
	exit(EXIT_FAILURE);
}

void	free_map_data(char **map_data)
{
	int	i;

	i = 0;
	while (map_data[i])
	{
		free(map_data[i]);
		i++;
	}
	free(map_data);
}

void	free_map_and_exit(char **map_data, char *error_message)
{
	free_map_data(map_data);
	error_and_exit(error_message);
}
