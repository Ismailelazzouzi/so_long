/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isel-azz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 03:03:45 by isel-azz          #+#    #+#             */
/*   Updated: 2024/04/07 03:03:47 by isel-azz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <limits.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include "MLX/include/MLX42/MLX42.h"

typedef struct t_game
{
	mlx_t			*win;
	mlx_texture_t	*wl;
	mlx_texture_t	*wk;
	mlx_texture_t	*pl;
	mlx_texture_t	*g;
	mlx_texture_t	*ex;
	mlx_image_t		*wall;
	mlx_image_t		*walk;
	mlx_image_t		*player;
	mlx_image_t		*gun;
	mlx_image_t		*exit;
	char			**map;
	int				height;
	int				width;
	int				x;
	int				y;
	int				player_x;
	int				player_y;
	int				playercount;
	int				exitcount;
	int				counter;
}	t_game_needs;

char	*get_next_line(int fd);
char	*nextcall_prep(char *retholder, char *holder);
char	*extract_line(char *holder);
char	*generate_line(char **holder_ptr, int fd);
char	*join_strs(char *s1, char *s2);
int		found_newline(char *holder);
void	borderprob(t_game_needs *game);
void	borders(t_game_needs *game);
int		*get_moves(char direction);
void	flood_fill(t_game_needs *game, int x, int y);
void	freemap(t_game_needs *game);
void	get_map(t_game_needs *game, char *argv1);
int		get_height(char *argv1);
void	map_check(t_game_needs *game, char *argv1);
void	get_player_pos(t_game_needs *game);
void	check_width(t_game_needs *game);
int		get_width(t_game_needs *game);
void	elements_count(t_game_needs *game);
void	show_map(t_game_needs *game);
void	textures(t_game_needs *game);
void	print_walls(t_game_needs *game);
void	print_walks(t_game_needs *game);
void	print_player(t_game_needs *game);
void	print_gun(t_game_needs *game);
void	print_exit(t_game_needs *game);
void	print_pe(t_game_needs *game);
void	my_keyhook(mlx_key_data_t keydata, void *param);
void	moveup(t_game_needs *game);
void	movedown(t_game_needs *game);
void	moveleft(t_game_needs *game);
void	moveright(t_game_needs *game);
int		zeroc(t_game_needs *game);
void	done(t_game_needs *game);
void	rendergame(t_game_needs *game);
int		playeronexit(t_game_needs *game);
void	clearimg(t_game_needs *game);
void	ft_putchar(char c);
void	print_number(unsigned int nbr);
void	closefunc(void *param);

#endif
