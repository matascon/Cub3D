/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parse_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matascon <matascon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 17:27:07 by matascon          #+#    #+#             */
/*   Updated: 2020/09/07 17:27:08 by matascon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int check_objects_map(char c)
{
	if (c == '0')
		return (1);
	else if (c == '1')
		return (1);
	else if (c == '2')
		return (1);
	else if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
		return (1);
	else if (c == '\t' || c == ' ')
		return (0);
	return (-1);
}

void		ft_overwrite_map(t_env *env, char *ptr, int y)
{
	int	i;
	int	j;
	int	check;

	i = 0;
	while (i < y)
	{
		j = 0;
		while (*ptr != '\n')
		{
			if (*ptr == '\t')
				j += 3;
			if ((check = check_objects_map(*ptr)) == -1)
				ft_exit(env, ERROR_14);
			else if (check)
				env->map.map[i][j] = *ptr;
			ptr++;
			j++;
		}
		ptr++;
		i++;
	}
}

void		ft_fill_map(t_env *env, int x, int y)
{
	int	i;
	int j;

	i = 0;
	while (i < y)
	{
		j = 0;
		while (j < x)
		{
			env->map.map[i][j] = 'X';
			j++;
		}
		i++;
	}
}

void 		ft_book_and_save_dimensions(t_env *env, int x, int y)
{
	int	i;

	env->map.map = (char **)ft_calloc(sizeof(char *), (y + 1));
	if (!env->map.map)
		ft_exit(env, ERROR_13);
	env->map.map[y] = NULL;
	i = 0;
	while (i < y)
	{
		env->map.map[i] = (char *)ft_calloc(sizeof(char), x + 1);
		if (!env->map.map[i])
			ft_exit(env, ERROR_13);
		env->map.map[i][x] = '\0';
		i++;
	}
	env->map.w_map = x;
	env->map.h_map = y;
}

void		ft_find_dimensions(char *ptr, int *longer_line, int *col)
{
	int	x;
	int	y;

	*col = 0;
	*longer_line = 0;
	x = 0;
	y = 0;
	while (ptr[y])
	{
		if (ptr[y] == '\n')
		{
			(*col)++;
			if (*longer_line < x)
				*longer_line = x;
			x = -1;
		}
		if (ptr[y] == '\t')
			x += 3;
		y++;
		x++;
	}
}
