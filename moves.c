/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isel-azz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 03:01:47 by isel-azz          #+#    #+#             */
/*   Updated: 2024/04/07 03:01:49 by isel-azz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	my_keyhook(mlx_key_data_t keydata, void *param)
{
	t_game_needs	*game;
	int				i;

	game = (t_game_needs *)param;
	i = 0;
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		moveup(game);
	else if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		movedown(game);
	else if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		moveleft(game);
	else if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		moveright(game);
	else if (keydata.key == 256 && keydata.action == MLX_PRESS)
		done(game);
}

void	moveup(t_game_needs *game)
{
	if (game->map[game->player_y - 1][game->player_x] != '1')
	{
		if (game->map[game->player_y - 1][game->player_x] == 'E'
			&& game->map[game->player_y][game->player_x] != 'X')
		{
			if (zeroc(game) == 0)
				done(game);
			else
			{
				game->map[game->player_y][game->player_x] = '0';
				game->map[game->player_y - 1][game->player_x] = 'X';
			}
		}
		else if (game->map[game->player_y][game->player_x] == 'X')
		{
			game->map[game->player_y][game->player_x] = 'E';
			game->map[game->player_y - 1][game->player_x] = 'P';
		}
		else
		{
			game->map[game->player_y][game->player_x] = '0';
			game->map[game->player_y - 1][game->player_x] = 'P';
		}
		rendergame(game);
	}
}

void	movedown(t_game_needs *game)
{
	if (game->map[game->player_y + 1][game->player_x] != '1')
	{
		if (game->map[game->player_y + 1][game->player_x] == 'E'
			&& game->map[game->player_y][game->player_x] != 'X')
		{
			if (zeroc(game) == 0)
				done(game);
			else
			{
				game->map[game->player_y][game->player_x] = '0';
				game->map[game->player_y + 1][game->player_x] = 'X';
			}
		}
		else if (game->map[game->player_y][game->player_x] == 'X')
		{
			game->map[game->player_y][game->player_x] = 'E';
			game->map[game->player_y + 1][game->player_x] = 'P';
		}
		else
		{
			game->map[game->player_y][game->player_x] = '0';
			game->map[game->player_y + 1][game->player_x] = 'P';
		}
		rendergame(game);
	}
}

void	moveleft(t_game_needs *game)
{
	if (game->map[game->player_y][game->player_x - 1] != '1')
	{
		if (game->map[game->player_y][game->player_x - 1] == 'E'
			&& game->map[game->player_y][game->player_x] != 'X')
		{
			if (zeroc(game) == 0)
				done(game);
			else
			{
				game->map[game->player_y][game->player_x] = '0';
				game->map[game->player_y][game->player_x - 1] = 'X';
			}
		}
		else if (game->map[game->player_y][game->player_x] == 'X')
		{
			game->map[game->player_y][game->player_x] = 'E';
			game->map[game->player_y][game->player_x - 1] = 'P';
		}
		else
		{
			game->map[game->player_y][game->player_x] = '0';
			game->map[game->player_y][game->player_x - 1] = 'P';
		}
		rendergame(game);
	}
}

void	moveright(t_game_needs *game)
{
	if (game->map[game->player_y][game->player_x + 1] != '1')
	{
		if (game->map[game->player_y][game->player_x + 1] == 'E'
			&& game->map[game->player_y][game->player_x] != 'X')
		{
			if (zeroc(game) == 0)
				done(game);
			else
			{
				game->map[game->player_y][game->player_x] = '0';
				game->map[game->player_y][game->player_x + 1] = 'X';
			}
		}
		else if (game->map[game->player_y][game->player_x] == 'X')
		{
			game->map[game->player_y][game->player_x] = 'E';
			game->map[game->player_y][game->player_x + 1] = 'P';
		}
		else
		{
			game->map[game->player_y][game->player_x] = '0';
			game->map[game->player_y][game->player_x + 1] = 'P';
		}
		rendergame(game);
	}
}
