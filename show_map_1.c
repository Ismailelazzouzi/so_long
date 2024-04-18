/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_map_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isel-azz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 03:01:17 by isel-azz          #+#    #+#             */
/*   Updated: 2024/04/07 03:01:19 by isel-azz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_gun(t_game_needs *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	game->x = 0;
	game->y = 0;
	while (i < game->height)
	{
		j = 0;
		game->x = 0;
		while (j < game->width)
		{
			if (game->map[i][j++] == 'C')
				mlx_image_to_window(game->win, game->gun, game->x, game->y);
			game->x += 32;
		}
		game->y += 32;
		i++;
	}
}

void	print_exit(t_game_needs *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	game->x = 0;
	game->y = 0;
	while (i < game->height)
	{
		j = 0;
		game->x = 0;
		while (j < game->width)
		{
			if (game->map[i][j++] == 'E')
				mlx_image_to_window(game->win, game->exit, game->x, game->y);
			game->x += 32;
		}
		game->y += 32;
		i++;
	}
}

void	print_pe(t_game_needs *game)
{
	int	i;
	int	j;

	i = 0;
	game->x = 0;
	game->y = 0;
	while (i < game->height)
	{
		j = 0;
		game->x = 0;
		while (j < game->width)
		{
			if (game->map[i][j] == 'X')
			{
				mlx_image_to_window(game->win, game->exit, game->x, game->y);
				mlx_image_to_window(game->win, game->player, game->x, game->y);
				game->player_x = j;
				game->player_y = i;
			}
			j++;
			game->x += 32;
		}
		game->y += 32;
		i++;
	}
}
