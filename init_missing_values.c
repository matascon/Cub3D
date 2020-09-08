/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_missing_values.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matascon <matascon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 17:26:32 by matascon          #+#    #+#             */
/*   Updated: 2020/09/08 16:45:12 by matascon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_sprites(t_env *env)
{
	int	i;
	int	j;
	int	n_spt;

	i = 0;
	n_spt = 0;
	while (i < env->map.h_map)
	{
		j = 0;
		while (j < env->map.w_map)
		{
			if (env->map.map[i][j] == '2')
				n_spt++;
			j++;
		}
		i++;
	}
	env->rc.sprite = (t_sprite *)malloc(sizeof(t_sprite) * n_spt);
	if (!env->rc.sprite)
		ft_exit(env, ERROR_13);
	env->rc.nbr_sprites = n_spt;
}

static void	init_orientation(t_env *env)
{
	if (env->rc.player.orientation_chr == 'N')
	{
		env->rc.player.dir_x = 0;
		env->rc.player.dir_y = -1;
	}
	else if (env->rc.player.orientation_chr == 'S')
	{
		env->rc.player.dir_x = 0;
		env->rc.player.dir_y = 1;
	}
	else if (env->rc.player.orientation_chr == 'W')
	{
		env->rc.player.dir_x = -1;
		env->rc.player.dir_y = 0;
	}
	else if (env->rc.player.orientation_chr == 'E')
	{
		env->rc.player.dir_x = 1;
		env->rc.player.dir_y = 0;
	}	
	env->rc.plan_x = -0.66 * env->rc.player.dir_y;
	env->rc.plan_y = 0.66 * env->rc.player.dir_x;
}

static void	init_position_player(t_env *env)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (!ft_strchr("NSWE", env->map.map[i][j]))
	{
		if (j == env->map.w_map - 1)
		{
			j = -1;
			i++;
		}
		j++;
	}
	env->rc.player.position_x = j + 0.5;
	env->rc.player.position_y = i + 0.5;
	env->rc.player.orientation_chr = env->map.map[i][j];
}

void		ft_init_missing_values(t_env *env)
{
	init_position_player(env);
	init_orientation(env);
	init_sprites(env);
}
