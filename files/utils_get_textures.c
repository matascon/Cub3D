/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_get_textures.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matascon <matascon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 17:27:04 by matascon          #+#    #+#             */
/*   Updated: 2020/09/09 17:08:23 by matascon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	check_errors_texture(t_env *env, char *ptr, int ready)
{
	if (!(*ptr) || !ready)
	{
		if (!(*ptr))
			ft_exit(env, ERROR_6);
		else
			ft_exit(env, ERROR_9);
	}
}

static void	assign_texture(t_env *env, char *texture, int type)
{
	if (type == NO)
		env->dir_tex_north = texture;
	else if (type == SO)
		env->dir_tex_south = texture;
	else if (type == WE)
		env->dir_tex_west = texture;
	else if (type == EA)
		env->dir_tex_east = texture;
	else
		env->dir_tex_sprite = texture;
}

static char	*pop_texture(t_env *env, char **aux_tex, char *ptr)
{
	int		i;

	i = 0;
	while (!ft_isspace(ptr[i]) && ptr[i])
		i++;
	if (!(ptr[i]))
		ft_exit(env, ERROR_6);
	*aux_tex = (char *)malloc(i + 1);
	i = 0;
	while (!ft_isspace(*ptr))
	{
		(*aux_tex)[i++] = *ptr;
		ptr++;
	}
	(*aux_tex)[i] = '\0';
	return (ptr);
}

char		*ft_aux_textures(t_env *env, char *ptr, int type)
{
	char	*texture;
	int		ready;

	ready = 0;
	while (*ptr && !ready)
	{
		if (ft_isspace(*ptr))
			ptr++;
		else
		{
			ptr = pop_texture(env, &texture, ptr);
			assign_texture(env, texture, type);
			ready++;
		}
	}
	check_errors_texture(env, ptr, ready);
	return (ptr);
}
