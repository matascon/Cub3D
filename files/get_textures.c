/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matascon <matascon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 17:26:26 by matascon          #+#    #+#             */
/*   Updated: 2020/09/09 16:58:10 by matascon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*ft_get_texture_north(t_env *env, char *ptr_file)
{
	if (env->file.no)
		ft_exit(env, ERROR_5);
	env->file.no = 1;
	ptr_file = ft_aux_textures(env, ptr_file, NO);
	return (ptr_file);
}

char	*ft_get_texture_south(t_env *env, char *ptr_file)
{
	if (env->file.so)
		ft_exit(env, ERROR_5);
	env->file.so = 1;
	ptr_file = ft_aux_textures(env, ptr_file, SO);
	return (ptr_file);
}

char	*ft_get_texture_west(t_env *env, char *ptr_file)
{
	if (env->file.we)
		ft_exit(env, ERROR_5);
	env->file.we = 1;
	ptr_file = ft_aux_textures(env, ptr_file, WE);
	return (ptr_file);
}

char	*ft_get_texture_east(t_env *env, char *ptr_file)
{
	if (env->file.ea)
		ft_exit(env, ERROR_5);
	env->file.ea = 1;
	ptr_file = ft_aux_textures(env, ptr_file, EA);
	return (ptr_file);
}

char	*ft_get_texture_sprite(t_env *env, char *ptr_file)
{
	if (env->file.s)
		ft_exit(env, ERROR_5);
	env->file.s = 1;
	ptr_file = ft_aux_textures(env, ptr_file, S);
	return (ptr_file);
}
