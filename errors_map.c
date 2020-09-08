/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matascon <matascon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 17:26:03 by matascon          #+#    #+#             */
/*   Updated: 2020/09/07 17:26:04 by matascon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	check_specifier(t_env *env, int x, int y)
{
	int	i;
	int	j;
	int	specifier;

	i = 0;
	specifier = 0;
	while (i < y)
	{
		j = 0;
		while (j < x)
		{
			if ((env->map.map[i][j] == 'N') || \
			(env->map.map[i][j] == 'S') || \
			(env->map.map[i][j] == 'W') || \
			(env->map.map[i][j] == 'E'))
				specifier++;
			if (specifier > 1)
				return (1);
			j++;
		}
		i++;
	}
	return (!specifier);
}

static int	check_objs_no_wall(char c)
{
	if (c == '0')
		return (1);
	else if (c == '2')
		return (1);
	else if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
		return (1);
	return (0);
}

static int	check_inside_map(t_env *env, int x, int y)
{
	int	i;
	int	j;

	i = 1;
	while (i < y - 1)
	{
		j = 1;
		while (j < x - 1)
		{
			if (env->map.map[i][j] == 'X')
			{
				if (check_objs_no_wall(env->map.map[i - 1][j]))
					ft_exit(env, ERROR_14);
				if (check_objs_no_wall(env->map.map[i + 1][j]))
					ft_exit(env, ERROR_14);
				if (check_objs_no_wall(env->map.map[i][j - 1]))
					ft_exit(env, ERROR_14);
				if (check_objs_no_wall(env->map.map[i][j + 1]))
					ft_exit(env, ERROR_14);
			}
			j++;
		}
		i++;
	}
	return (0);
}

static int	check_borders_map(t_env *env, int x, int y)
{
	int	i;

	i = 0;
	while (i < x)
	{
		if (check_objs_no_wall(env->map.map[0][i]) || \
		(env->map.map[0][i] == 'X' && env->map.map[1][i] == '0'))
			return (1);
		if (check_objs_no_wall(env->map.map[y - 1][i]) || \
		(env->map.map[y - 1][i] == 'X' && env->map.map[y - 2][i] == '0'))
			return (1);
		i++;
	}
	i = 0;
	while (i < y)
	{
		if (check_objs_no_wall(env->map.map[i][0]) || \
		(env->map.map[i][0] == 'X' && env->map.map[i][1] == '0'))
			return (1);
		if (check_objs_no_wall(env->map.map[i][x - 1]) || \
		(env->map.map[i][x - 1] == 'X' && env->map.map[i][x - 2] == '0'))
			return (1);
		i++;
	}
	return (0);
}

void		ft_check_errors_map(t_env *env)
{
	if (check_borders_map(env, env->map.w_map, env->map.h_map))
		ft_exit(env, ERROR_14);
	else if (check_inside_map(env, env->map.w_map, env->map.h_map))
		ft_exit(env, ERROR_14);
	else if (check_specifier(env, env->map.w_map, env->map.h_map))
		ft_exit(env, ERROR_14);
}
