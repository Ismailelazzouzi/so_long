/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isel-azz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 03:00:34 by isel-azz          #+#    #+#             */
/*   Updated: 2024/04/07 03:00:59 by isel-azz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	show_map(t_game_needs *game)
{
	game->width = get_width(game);
	game->win = mlx_init(game->width * 32, game->height * 32, "test", true);
	textures(game);
	print_walls(game);
	print_walks(game);
	print_gun(game);
	print_exit(game);
	print_player(game);
}

void	textures(t_game_needs *game)
{
	game->wl = mlx_load_png("./textures/wall.png");
	game->wall = mlx_texture_to_image(game->win, game->wl);
	game->wk = mlx_load_png("./textures/walk.png");
	game->walk = mlx_texture_to_image(game->win, game->wk);
	game->pl = mlx_load_png("./textures/player.png");
	game->player = mlx_texture_to_image(game->win, game->pl);
	game->g = mlx_load_png("./textures/portal.png");
	game->gun = mlx_texture_to_image(game->win, game->g);
	game->ex = mlx_load_png("./textures/exit.png");
	game->exit = mlx_texture_to_image(game->win, game->ex);
}

void	print_walls(t_game_needs *game)
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
			if (game->map[i][j++] == '1')
				mlx_image_to_window(game->win, game->wall, game->x, game->y);
			game->x += 32;
		}
		game->y += 32;
		i++;
	}
}

void	print_walks(t_game_needs *game)
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
			if (game->map[i][j++] != '1')
				mlx_image_to_window(game->win, game->walk, game->x, game->y);
			game->x += 32;
		}
		game->y += 32;
		i++;
	}
}

void	print_player(t_game_needs *game)
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
			if (game->map[i][j] == 'P')
			{
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
