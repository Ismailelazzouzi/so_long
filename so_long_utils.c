/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isel-azz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 02:57:54 by isel-azz          #+#    #+#             */
/*   Updated: 2024/04/07 02:58:01 by isel-azz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_number(unsigned int nbr)
{
	if (nbr > 9)
	{
		print_number(nbr / 10);
		print_number(nbr % 10);
	}
	else
	{
		ft_putchar(nbr + 48);
	}
}

void	closefunc(void *param)
{
	t_game_needs	*game;

	game = (t_game_needs *)param;
	freemap(game);
	exit(0);
}
