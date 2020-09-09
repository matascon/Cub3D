/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_wall_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matascon <matascon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 18:14:03 by matascon          #+#    #+#             */
/*   Updated: 2020/09/09 16:58:39 by matascon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	dda_algorithm(t_env *env)
{
	int	hit;

	hit = 0;
	while (hit == 0)
	{
		if (env->rc.side_dist_x < env->rc.side_dist_y)
		{
			env->rc.side_dist_x += env->rc.delta_x;
			env->rc.map_x += env->rc.step_x;
			env->rc.side = 0;
		}
		else
		{
			env->rc.side_dist_y += env->rc.delta_y;
			env->rc.map_y += env->rc.step_y;
			env->rc.side = 1;
		}
		if (env->map.map[env->rc.map_y][env->rc.map_x] == '1')
			hit = 1;
	}
}

static void	step_raycasting(t_env *env)
{
	if (env->rc.ray_x < 0)
	{
		env->rc.step_x = -1;
		env->rc.side_dist_x = (env->rc.player.position_x - env->rc.map_x) * \
		env->rc.delta_x;
	}
	else
	{
		env->rc.step_x = 1;
		env->rc.side_dist_x = (env->rc.map_x + 1 - env->rc.player.position_x) \
		* env->rc.delta_x;
	}
	if (env->rc.ray_y < 0)
	{
		env->rc.step_y = -1;
		env->rc.side_dist_y = (env->rc.player.position_y - env->rc.map_y) * \
		env->rc.delta_y;
	}
	else
	{
		env->rc.step_y = 1;
		env->rc.side_dist_y = (env->rc.map_y + 1 - env->rc.player.position_y) \
		* env->rc.delta_y;
	}
}

static void	init_raycasting(t_env *env, int x)
{
	env->rc.camera_in_x = 2 * x / (double)(env->width_screen) - 1;
	env->rc.ray_x = env->rc.player.dir_x + env->rc.plan_x * env->rc.camera_in_x;
	env->rc.ray_y = env->rc.player.dir_y + env->rc.plan_y * env->rc.camera_in_x;
	env->rc.delta_x = fabs(1 / env->rc.ray_x);
	env->rc.delta_y = fabs(1 / env->rc.ray_y);
	env->rc.map_x = (int)env->rc.player.position_x;
	env->rc.map_y = (int)env->rc.player.position_y;
}

void		ft_raycast_wall(t_env *env)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x < env->width_screen)
	{
		init_raycasting(env, x);
		step_raycasting(env);
		dda_algorithm(env);
		if (env->rc.side == 0)
			env->rc.perp_wall_dist = (env->rc.map_x - \
			env->rc.player.position_x + (1 - env->rc.step_x) / 2) / \
			env->rc.ray_x;
		else
			env->rc.perp_wall_dist = (env->rc.map_y - \
			env->rc.player.position_y + (1 - env->rc.step_y) / 2) / \
			env->rc.ray_y;
		ft_raycast_columns(env, x, y);
		env->rc.render.dist_wall[x] = env->rc.perp_wall_dist;
		x++;
	}
}
