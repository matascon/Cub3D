/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matascon <matascon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 17:26:48 by matascon          #+#    #+#             */
/*   Updated: 2020/09/07 17:26:49 by matascon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char	*identify_case(t_env *env, char *ptr_file)
{
	if (ptr_file[0] == 'R' && ptr_file[1] == ' ')
		ptr_file = ft_get_resolution(env, ptr_file + 2);
	else if (ptr_file[0] == 'N' && ptr_file[1] == 'O' && ptr_file[2] == ' ')
		ptr_file = ft_get_texture_north(env, ptr_file + 3);
	else if (ptr_file[0] == 'S' && ptr_file[1] == 'O' && ptr_file[2] == ' ')
		ptr_file = ft_get_texture_south(env, ptr_file + 3);
	else if (ptr_file[0] == 'W' && ptr_file[1] == 'E' && ptr_file[2] == ' ')
		ptr_file = ft_get_texture_west(env, ptr_file + 3);
	else if (ptr_file[0] == 'E' && ptr_file[1] == 'A' && ptr_file[2] == ' ')
		ptr_file = ft_get_texture_east(env, ptr_file + 3);
	else if (ptr_file[0] == 'S' && ptr_file[1] == ' ')
		ptr_file = ft_get_texture_sprite(env, ptr_file + 2);
	else if (ptr_file[0] == 'F' && ptr_file[1] == ' ')
		ptr_file = ft_get_color_floor(env, ptr_file + 2);
	else if (ptr_file[0] == 'C' && ptr_file[1] == ' ')
		ptr_file = ft_get_color_roof(env, ptr_file + 2);
	else
		ft_exit(env, ERROR_4);
	return (ptr_file);
}

static int	check_arguments(t_env *env)
{
	if (!env->file.r)
		return (0);
	else if (!env->file.no)
		return (0);
	else if (!env->file.so)
		return (0);
	else if (!env->file.we)
		return (0);
	else if (!env->file.ea)
		return (0);
	else if (!env->file.s)
		return (0);
	else if (!env->file.f)
		return (0);
	else if (!env->file.c)
		return (0);
	return (1);
}

static void init_values_for_file(t_env *env)
{
	env->rc.color.floor = 0;
	env->rc.color.roof = 0;
	env->file.r = 0;
	env->file.no = 0;
	env->file.so = 0;
	env->file.we = 0;
	env->file.ea = 0;
	env->file.s = 0;
	env->file.f = 0;
	env->file.c = 0;
	env->dir_tex_north = NULL;
	env->dir_tex_south = NULL;
	env->dir_tex_west = NULL;
	env->dir_tex_east = NULL;
	env->dir_tex_sprite = NULL;
	env->map.map = NULL;
}

void		ft_parse_file(t_env *env)
{
	char	*ptr_file;
	int i;

	init_values_for_file(env);
	ptr_file = env->file.file;
	while (*ptr_file && !check_arguments(env))
	{
		if (ft_isspace(*ptr_file))
			ptr_file++;
		else
			ptr_file = identify_case(env, ptr_file);
	}
	if (!(*ptr_file))
		ft_exit(env, ERROR_6);
	ft_parse_map(env, ptr_file);
}
