/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matascon <matascon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 17:26:08 by matascon          #+#    #+#             */
/*   Updated: 2020/09/09 17:04:04 by matascon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	free_map(t_env *env)
{
	int i;

	if (env->map.map)
	{
		i = 0;
		while (env->map.map[i])
			free(env->map.map[i++]);
		free(env->map.map);
	}
}

static void	free_dir_textures(t_env *env)
{
	if (env->dir_tex_north)
		free(env->dir_tex_north);
	if (env->dir_tex_south)
		free(env->dir_tex_south);
	if (env->dir_tex_west)
		free(env->dir_tex_west);
	if (env->dir_tex_east)
		free(env->dir_tex_east);
	if (env->dir_tex_sprite)
		free(env->dir_tex_sprite);
}

void		ft_exit(t_env *env, char *message)
{
	if (message)
		ft_putendl_fd(message, 1);
	if (env->mlx_ptr)
		free(env->mlx_ptr);
	if (env->win_ptr)
		free(env->win_ptr);
	if (env->file.file)
		free(env->file.file);
	if (env->rc.sprite)
		free(env->rc.sprite);
	free_dir_textures(env);
	free_map(env);
	free(env);
	exit(0);
}
