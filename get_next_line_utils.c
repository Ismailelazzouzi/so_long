/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isel-azz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 03:07:55 by isel-azz          #+#    #+#             */
/*   Updated: 2024/04/07 03:07:58 by isel-azz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	found_newline(char *holder)
{
	int	i;

	if (!holder)
		return (1);
	i = 0;
	while (holder[i])
	{
		if (holder[i] == '\n')
			return (0);
		i++;
	}
	return (1);
}

int	ft_strlen(char	*str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*join_strs(char	*s1, char *s2)
{
	char	*ret;
	int		i;
	int		j;

	if (!s1)
		i = 0;
	if (s1)
		i = ft_strlen(s1);
	j = ft_strlen(s2);
	ret = malloc((i + j + 1) * sizeof(char));
	if (!ret)
		return (free(s1), NULL);
	i = 0;
	while (s1 && s1[i])
	{
		ret[i] = s1[i];
		i++;
	}
	while (*s2)
		ret[i++] = *(s2++);
	ret[i] = '\0';
	free(s1);
	return (ret);
}
