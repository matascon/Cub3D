/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_sprite.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matascon <matascon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 17:53:48 by matascon          #+#    #+#             */
/*   Updated: 2020/09/07 18:23:18 by matascon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	free_dist_wall(t_env *env)
{
	if (env->rc.render.dist_wall)
	{
		free(env->rc.render.dist_wall);
		env->rc.render.dist_wall = NULL;
	}
}

static void	sort_sprite(t_env *env)
{
	int	i;
	int	swap;

	i = 0;
	while (i + 1 < env->rc.nbr_sprites)
	{
		if (env->rc.sprite[env->rc.sprite[i].order].distance < \
		env->rc.sprite[env->rc.sprite[i + 1].order].distance)
		{
			swap = env->rc.sprite[i].order;
			env->rc.sprite[i].order = env->rc.sprite[i + 1].order;
			env->rc.sprite[i + 1].order = swap;
			sort_sprite(env);
		}
		i++;
	}
}

static void	sprite_distance(t_env *env)
{
	int	i;

	i = 0;
	while (i < env->rc.nbr_sprites)
	{
		env->rc.sprite[i].order = i;
		env->rc.sprite[env->rc.sprite[i].order].distance = \
		pow(env->rc.player.position_x - env->rc.sprite\
		[env->rc.sprite[i].order].coord_x, 2) + pow(env->rc.player.\
		position_y - env->rc.sprite[env->rc.sprite[i].order].coord_y, 2);
		i++;
	}
}

void		ft_raycast_sprite(t_env *env)
{
	sprite_distance(env);
	sort_sprite(env);
	ft_render_sprite(env);
	free_dist_wall(env);
}
