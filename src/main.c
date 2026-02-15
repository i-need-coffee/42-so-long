/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjolliet <sjolliet@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 11:40:06 by sjolliet          #+#    #+#             */
/*   Updated: 2026/02/15 18:45:18 by sjolliet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_map_data	map;

	if (argc != 2)
		error_and_exit("The program should have one parameter (.ber file)");
	check_map(argv[1], &map);
	free_map_data(map.data);
	return (0);
}
