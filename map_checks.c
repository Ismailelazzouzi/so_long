/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isel-azz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 02:58:37 by isel-azz          #+#    #+#             */
/*   Updated: 2024/04/07 02:58:39 by isel-azz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_map(t_game_needs *game, char *argv1)
{
	int	fd;
	int	i;

	i = 0;
	game->height = get_height(argv1);
	game->map = NULL;
	if (game->height == 0)
		return ;
	fd = open(argv1, O_RDONLY);
	game->map = (char **) malloc((game->height + 1) * sizeof (char *));
	if (!game->map)
		borderprob(game);
	while (i < game->height)
	{
		game->map[i] = get_next_line(fd);
		i++;
	}
	game->map[i] = NULL;
	close(fd);
}

int	get_height(char *argv1)
{
	char	*line;
	int		fd;
	int		len;

	fd = open(argv1, O_RDONLY);
	len = 0;
	line = get_next_line(fd);
	if (!line)
		return (0);
	while (line != NULL)
	{
		free (line);
		line = get_next_line(fd);
		len++;
	}
	close(fd);
	return (free(line), line = NULL, len);
}

void	map_check(t_game_needs *game, char *argv1)
{
	int	i;
	int	j;

	i = 0;
	get_player_pos(game);
	check_width(game);
	flood_fill(game, game->player_x, game->player_y);
	while (i < game->height)
	{
		j = 0;
		while (j < game->width)
		{
			if ((game->map[i][j] == 'E' || game->map[i][j] == 'C')
				&& game->map[i][j] != 'V')
			{
				freemap(game);
				write(2, "Error\ninvalid map\n", 18);
				exit(1);
			}
			j++;
		}
		i++;
	}
	freemap(game);
	get_map(game, argv1);
}

void	get_player_pos(t_game_needs *game)
{
	int	i;
	int	j;

	i = 0;
	game->width = get_width(game);
	while (i < game->height)
	{
		j = 0;
		while (j < game->width)
		{
			if (game->map[i][j] == 'P')
			{
				game->player_x = i;
				game->player_y = j;
			}
			j++;
		}
		i++;
	}
}

void	check_width(t_game_needs *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->height)
	{
		j = 0;
		while (game->map[i][j] != '\0')
		{
			if (j > game->width)
			{
				freemap(game);
				write(2, "Error\ninvalid map\n", 18);
				exit(1);
			}
			j++;
		}
		i++;
	}
	borders(game);
	elements_count(game);
}
