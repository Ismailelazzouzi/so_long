/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checks_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isel-azz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 02:59:32 by isel-azz          #+#    #+#             */
/*   Updated: 2024/04/07 02:59:34 by isel-azz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_width(t_game_needs *game)
{
	int	i;

	i = 0;
	while (game->map[0][i] != '\n')
		i++;
	return (i);
}

void	elements_count(t_game_needs *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->height)
	{
		j = 0;
		while (j < game->width)
		{
			if (game->map[i][j] == 'P')
				game->playercount++;
			else if (game->map[i][j] == 'E')
				game->exitcount++;
			j++;
		}
		i++;
	}
	if (game->playercount > 1 || game->exitcount > 1)
		borderprob(game);
}
