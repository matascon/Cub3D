/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matascon <matascon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 19:04:16 by matascon          #+#    #+#             */
/*   Updated: 2020/09/09 16:58:21 by matascon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	move_down(t_env *env)
{
	if (env->mv.down == 1)
	{
		if (env->map.map[(int)(env->rc.player.position_y)][(int)\
		(env->rc.player.position_x - env->rc.player.dir_x * 0.06)] != '1' \
		&& env->map.map[(int)(env->rc.player.position_y)][(int)\
		(env->rc.player.position_x - env->rc.player.dir_x * 0.06)] != '2')
			env->rc.player.position_x -= env->rc.player.dir_x * 0.06;
		if (env->map.map[(int)(env->rc.player.position_y - \
		env->rc.player.dir_y * 0.06)][(int)(env->rc.player.position_x)] != \
		'1' && env->map.map[(int)(env->rc.player.position_y - \
		env->rc.player.dir_y * 0.06)][(int)(env->rc.player.position_x)] != '2')
			env->rc.player.position_y -= env->rc.player.dir_y * 0.06;
	}
}

static void	move_up(t_env *env)
{
	if (env->mv.up == 1)
	{
		if (env->map.map[(int)(env->rc.player.position_y)][(int)\
		(env->rc.player.position_x + env->rc.player.dir_x * 0.06)] != '1' \
		&& env->map.map[(int)(env->rc.player.position_y)][(int)\
		(env->rc.player.position_x + env->rc.player.dir_x * 0.06)] != '2')
			env->rc.player.position_x += env->rc.player.dir_x * 0.06;
		if (env->map.map[(int)(env->rc.player.position_y + \
		env->rc.player.dir_y * 0.06)][(int)(env->rc.player.position_x)] != \
		'1' && env->map.map[(int)(env->rc.player.position_y + \
		env->rc.player.dir_y * 0.06)][(int)(env->rc.player.position_x)] != '2')
			env->rc.player.position_y += env->rc.player.dir_y * 0.06;
	}
}

int			ft_movement(t_env *env)
{
	env->mv.speed_rot = 0.06;
	move_up(env);
	move_down(env);
	ft_move_right(env);
	ft_move_left(env);
	ft_render_frame(env);
	return (0);
}
