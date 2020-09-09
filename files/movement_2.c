/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matascon <matascon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 19:51:11 by matascon          #+#    #+#             */
/*   Updated: 2020/09/09 16:58:24 by matascon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	aux_move_left(t_env *env)
{
	if (env->mv.left == 1)
	{
		if (env->map.map[(int)(env->rc.player.position_y - env->rc.plan_y * \
		0.06)][(int)(env->rc.player.position_x)] != '1' && env->map.map[(int)\
		(env->rc.player.position_y - env->rc.plan_y * 0.06)]\
		[(int)(env->rc.player.position_x)] != '2')
			env->rc.player.position_y -= env->rc.plan_y * 0.06;
		if (env->map.map[(int)(env->rc.player.position_y)][(int)\
		(env->rc.player.position_x - env->rc.plan_x * 0.06)] != '1' && \
		env->map.map[(int)(env->rc.player.position_y)]\
		[(int)(env->rc.player.position_x - \
		env->rc.plan_x * 0.06)] != '2')
			env->rc.player.position_x -= env->rc.plan_x * 0.06;
	}
}

void		ft_move_left(t_env *env)
{
	if (env->mv.rot_left == 1)
	{
		env->mv.old_dir_x = env->rc.player.dir_x;
		env->rc.player.dir_x = env->rc.player.dir_x * cos(\
		-env->mv.speed_rot) - env->rc.player.dir_y * sin(-env->mv.speed_rot);
		env->rc.player.dir_y = env->mv.old_dir_x * sin(-env->mv.speed_rot) + \
		env->rc.player.dir_y * cos(-env->mv.speed_rot);
		env->mv.old_plan_x = env->rc.plan_x;
		env->rc.plan_x = env->rc.plan_x * cos(-env->mv.speed_rot) - \
		env->rc.plan_y * sin(-env->mv.speed_rot);
		env->rc.plan_y = env->mv.old_plan_x * sin(-env->mv.speed_rot) + \
		env->rc.plan_y * cos(-env->mv.speed_rot);
	}
	aux_move_left(env);
}

static void	aux_move_right(t_env *env)
{
	if (env->mv.right == 1)
	{
		if (env->map.map[(int)(env->rc.player.position_y)][(int)\
		(env->rc.plan_x * 0.06 + env->rc.player.position_x)] != '1' && \
		env->map.map[(int)(env->rc.player.position_y)][(int)\
		(env->rc.plan_x * 0.06 + env->rc.player.position_x)] != '2')
			env->rc.player.position_x += env->rc.plan_x * 0.06;
		if (env->map.map[(int)(env->rc.player.position_y + \
		env->rc.plan_y * 0.06)][(int)(env->rc.player.position_x)] \
		!= '1' && env->map.map[(int)(env->rc.player.position_y + \
		env->rc.plan_y * 0.06)][(int)(env->rc.player.position_x)] != '2')
			env->rc.player.position_y += env->rc.plan_y * 0.06;
	}
}

void		ft_move_right(t_env *env)
{
	if (env->mv.rot_right == 1)
	{
		env->mv.old_dir_x = env->rc.player.dir_x;
		env->rc.player.dir_x = env->rc.player.dir_x * cos(\
		env->mv.speed_rot) - env->rc.player.dir_y * sin(env->mv.speed_rot);
		env->rc.player.dir_y = env->mv.old_dir_x * sin(env->mv.speed_rot) + \
		env->rc.player.dir_y * cos(env->mv.speed_rot);
		env->mv.old_plan_x = env->rc.plan_x;
		env->rc.plan_x = env->rc.plan_x * cos(env->mv.speed_rot) - \
		env->rc.plan_y * sin(env->mv.speed_rot);
		env->rc.plan_y = env->mv.old_plan_x * sin(env->mv.speed_rot) + \
		env->rc.plan_y * cos(env->mv.speed_rot);
	}
	aux_move_right(env);
}
