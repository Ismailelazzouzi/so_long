/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isel-azz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 03:02:02 by isel-azz          #+#    #+#             */
/*   Updated: 2024/04/07 03:02:05 by isel-azz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	zeroc(t_game_needs *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->height)
	{
		j = 0;
		while (j < game->width)
		{
			if (game->map[i][j] == 'C')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	done(t_game_needs *game)
{
	int	i;

	i = game->height;
	freemap(game);
	mlx_terminate(game->win);
	exit(0);
}

void	rendergame(t_game_needs *game)
{
	clearimg(game);
	game->wall = mlx_texture_to_image(game->win, game->wl);
	game->walk = mlx_texture_to_image(game->win, game->wk);
	game->player = mlx_texture_to_image(game->win, game->pl);
	game->gun = mlx_texture_to_image(game->win, game->g);
	game->exit = mlx_texture_to_image(game->win, game->ex);
	print_walls(game);
	print_walks(game);
	print_player(game);
	print_gun(game);
	if (playeronexit(game) == 1)
		print_pe(game);
	else
		print_exit(game);
	write(1, "moves : ", 8);
	print_number(++game->counter);
	write(1, "\n", 1);
}

int	playeronexit(t_game_needs *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->height)
	{
		j = 0;
		while (j < game->width)
		{
			if (game->map[i][j] == 'X')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	clearimg(t_game_needs *game)
{
	mlx_delete_image(game->win, game->wall);
	mlx_delete_image(game->win, game->player);
	mlx_delete_image(game->win, game->walk);
	mlx_delete_image(game->win, game->gun);
	mlx_delete_image(game->win, game->exit);
}
