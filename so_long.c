/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isel-azz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 02:57:11 by isel-azz          #+#    #+#             */
/*   Updated: 2024/04/07 02:57:15 by isel-azz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game_needs	game;

	if (argc == 2)
	{
		get_map(&game, argv[1]);
		if (game.map)
		{
			map_check(&game, argv[1]);
			show_map(&game);
			mlx_key_hook(game.win, &my_keyhook, &game);
			mlx_close_hook(game.win, &closefunc, &game);
			mlx_loop(game.win);
		}
	}
	write(2, "please give a valid map file\n", 29);
	exit(1);
}
