/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checks_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isel-azz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 02:58:52 by isel-azz          #+#    #+#             */
/*   Updated: 2024/04/07 02:59:15 by isel-azz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	borderprob(t_game_needs *game)
{
	freemap(game);
	write(2, "Error\ninvalid map\n", 18);
	exit(1);
}

void	borders(t_game_needs *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->height)
	{
		j = 0;
		if (game->map[i][j] != '1')
			borderprob(game);
		else if (game->map[i][game->width - 1] != '1')
			borderprob(game);
		while (j < game->width)
		{
			if (game->map[0][j] != '1')
				borderprob(game);
			else if (game->map[game->height - 1][j] != '1')
				borderprob(game);
			j++;
		}
		i++;
	}
}

int	*get_moves(char direction)
{
	int	*ret;

	ret = (int *)malloc(4 * sizeof(int));
	if (!ret)
		return (NULL);
	if (direction == 'x')
	{
		ret[0] = -1;
		ret[1] = 1;
		ret[2] = 0;
		ret[3] = 0;
	}
	else if (direction == 'y')
	{
		ret[0] = 0;
		ret[1] = 0;
		ret[2] = -1;
		ret[3] = 1;
	}
	return (ret);
}

void	flood_fill(t_game_needs *game, int x, int y)
{
	int	i;
	int	*move_x;
	int	*move_y;
	int	new_x;
	int	new_y;

	i = 0;
	move_x = get_moves('x');
	move_y = get_moves('y');
	game->map[x][y] = 'V';
	while (i < 4)
	{
		new_x = x + move_x[i];
		new_y = y + move_y[i];
		if (new_x >= 0 && new_x < game->height
			&& new_y >= 0 && new_y < game->width)
			if (game->map[new_x][new_y] != '1'
				&& game->map[new_x][new_y] != 'V')
				flood_fill(game, new_x, new_y);
		i++;
	}
	free(move_x);
	free(move_y);
}

void	freemap(t_game_needs *game)
{
	int	i;

	i = game->height;
	while (i >= 0)
		free(game->map[i--]);
	free(game->map);
}
